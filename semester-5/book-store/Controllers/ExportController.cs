using book_store.Models;
using book_store.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace book_store.Controllers;

[ApiController]
[Route("api/exports")]
public class ExportController : Controller
{
    private readonly BookStoreContext _ctx;
    private readonly CsvService _csvService;
    public ExportController(BookStoreContext dbCtx, CsvService csv) { _ctx = dbCtx; _csvService = csv; }

    [HttpGet("books-as-csv")]
    public async Task<IActionResult> ExportBooks()
    {
        List<Book> data = await _ctx.Books.ToListAsync();

        var csv = _csvService.ExportToCsv(data);

        return File(csv, "text/csv", "books.csv");
    }

    [HttpGet("orders-as-csv")]
    public async Task<IActionResult> ExportOrders()
    {
        
        var csv = await _csvService.ExportOrdersToCsv();

        return File(
            csv,
            "text/csv",
            $"orders_export_{DateTime.Now:yyyyMMdd_HHmmss}.csv"
        );
    }
}
