using book_store.Models;

namespace book_store.Dtos;

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
