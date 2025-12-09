using book_store.Models;

namespace book_store.Dtos;

public class BookModel
{
    public int BookID { get; set; }
    public string ISBN { get; set; } = string.Empty;
    public string Name { get; set; } = string.Empty;
    public string Author { get; set; } = string.Empty;
    public string? CoverLink { get; set; }
    public int Pages { get; set; }
    public int Year { get; set; }
    public double Price { get; set; }

    public BookModel() { }

    public BookModel(BookDTO src)
    {
        BookID = src.BookID;
        Name = src.Name;
        Author = src.Author;
        CoverLink = src.CoverLink;
        Pages = src.Pages;
        Year = src.Year;
        Price = src.Price;
    }

    public BookDTO ToDTO() => new BookDTO(BookID, ISBN, Name, Author, CoverLink, Pages, Year, Price);
};

public record BookDTO (
    int BookID,
    string BookISBN,
    string Name,
    string Author,
    string? CoverLink,
    int Pages,
    int Year,
    double Price    
);

public static class BookMappings
{    
    public static BookDTO ToDTO(this Book src) => new BookDTO(
        src.BookId,
        src.BookIsbn,
        src.Name,
        src.Author,
        src.CoverLink,
        src.Pages,
        src.Year,
        src.Price
    );
};
