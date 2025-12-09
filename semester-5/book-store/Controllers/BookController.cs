using book_store.Dtos;
using book_store.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace book_store.Controllers;

[ApiController]
[Route("api/books")]
public class BookController : Controller
{
    private readonly BookStoreContext _ctx;

    public BookController(BookStoreContext dbCtx) {  _ctx = dbCtx; }

    [HttpGet("get-paginated")]
    public async Task<IActionResult> getPaginated([FromQuery] string? search, [FromQuery] int? pageSize = 5, [FromQuery] int? page = 1)
    {
        if (string.IsNullOrWhiteSpace(search)) search = "";

        var query = _ctx.Books
            .Where(b => b.Name.ToLower().Contains(search.ToLower()) || b.Author.ToLower().Contains(search.ToLower()))
            .Skip((page.Value - 1) * pageSize.Value)
            .Take(pageSize.Value);

        List<Book> books = await query.ToListAsync();
        List<BookDTO> bookDTOs = books.Select(b => b.ToDTO()).ToList();

        return Ok(bookDTOs);
    }

    [HttpGet("get-one")]
    public async Task<IActionResult> getOne([FromQuery] int ID)
    {
        Book? book = await _ctx.Books.Where(b => b.BookId == ID).FirstOrDefaultAsync();
        if (book == null) return NotFound("Book could not be found");

        return Ok(book.ToDTO());
    }

    [HttpPost("create")]
    public async Task<IActionResult> createOne([FromBody] BookDTO bookDTO)
    {
        bool isDuplicate = await _ctx.Books.Where(b => b.BookIsbn == bookDTO.BookISBN).AnyAsync();
        if (isDuplicate) return Conflict("Book with this isbn exists");

        Book book = new Book() 
        { 
            BookIsbn = bookDTO.BookISBN,
            Name = bookDTO.Name,
            Author = bookDTO.Author,
            CoverLink = bookDTO.CoverLink,
            Pages = bookDTO.Pages,
            Year = bookDTO.Year,
            Price = bookDTO.Price,
        };

        _ctx.Add(book);

        int entries = await _ctx.SaveChangesAsync();
        if (entries == 0) return Problem("Could not save.");

        return Ok();
    }

    [HttpPut("edit")]
    public async Task<IActionResult> editOne([FromBody] BookDTO bookDTO, [FromQuery] int bookID)
    {
        Book? book = await _ctx.Books.Where(b => b.BookId == bookID).FirstOrDefaultAsync();
        if (book == null) return NotFound("Book not found");

        book.BookIsbn = bookDTO.BookISBN;
        book.Name = bookDTO.Name;
        book.Author = bookDTO.Author;
        book.CoverLink = bookDTO.CoverLink;
        book.Pages = bookDTO.Pages;
        book.Year = bookDTO.Year;
        book.Price = bookDTO.Price;

        int entries = await _ctx.SaveChangesAsync();
        if (entries == 0) return Problem("Could not save.");

        return Ok();
    }

    [HttpDelete("delete-by-id")]
    public async Task<IActionResult> deleteByID([FromQuery] int ID)
    {
        int rows = await _ctx.Books.Where(b => b.BookId == ID).ExecuteDeleteAsync();

        if (rows == 0) return BadRequest("Could not delete book.");

        return Ok();
    }
}
