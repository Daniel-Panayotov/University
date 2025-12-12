using CsvHelper;
using CsvHelper.Configuration;
using Microsoft.EntityFrameworkCore;
using System.Globalization;

namespace book_store.Services;

public record OrderBookExportDTO
(
    int OrderID,
    int UserID,
    DateTime OrderTime,
    double TotalPrice,
    int BookID,
    string BookISBN,
    string BookName,
    string Author,
    string CoverLink,
    int Pages,
    int Year,
    double BookPrice
);

public class CsvService
{

    private readonly BookStoreContext _ctx;

    public CsvService(BookStoreContext context)
    {
        _ctx = context;
    }

    public byte[] ExportToCsv<T>(IEnumerable<T> data)
    {
        using var memoryStream = new MemoryStream();
        using var writer = new StreamWriter(memoryStream);

        var config = new CsvConfiguration(CultureInfo.InvariantCulture)
        {
            ShouldQuote = args => true // Quote all fields for safety
        };

        using var csv = new CsvWriter(writer, config);
        csv.WriteRecords(data);
        writer.Flush();

        return memoryStream.ToArray();
    }

    public async Task<byte[]> ExportOrdersToCsv()
    {
        // Fetch and flatten data directly from database
        var flattenedData = await _ctx.Orders
            .AsNoTracking()
            .Include(o => o.RelOrderBooks)
                .ThenInclude(ob => ob.Book)
            .SelectMany(o => o.RelOrderBooks.Select(ob => new OrderBookExportDTO(
                OrderID: o.OrderId,
                UserID: o.UserId,
                OrderTime: o.OrderTime,
                TotalPrice: o.TotalPrice,
                BookID: ob.Book.BookId,
                BookISBN: ob.Book.BookIsbn,
                BookName: ob.Book.Name,
                Author: ob.Book.Author,
                CoverLink: ob.Book.CoverLink ?? "",
                Pages: ob.Book.Pages,
                Year: ob.Book.Year,
                BookPrice: ob.Book.Price
            )))
            .ToListAsync();

        // Generate CSV using CsvHelper
        using var memoryStream = new MemoryStream();
        using var writer = new StreamWriter(memoryStream);
        using var csv = new CsvWriter(writer, CultureInfo.InvariantCulture);

        csv.WriteRecords(flattenedData);
        writer.Flush();

        return memoryStream.ToArray();
    }
}
