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

    [HttpPost("create")]
    public async Task<IActionResult> createOne([FromBody] int x)
    {

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
