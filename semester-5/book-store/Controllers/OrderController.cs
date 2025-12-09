using book_store.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace book_store.Controllers;

[ApiController]
[Route("api/orders")]
public class OrderController : Controller
{
    private readonly BookStoreContext _ctx;

    public OrderController(BookStoreContext dbCtx) { _ctx = dbCtx; }

    [HttpPost("new")]
    public async Task<IActionResult> addOrder([FromQuery] int bookID)
    {
        Book? book = await _ctx.Books.Where(b => b.BookId == bookID).FirstOrDefaultAsync();
        if (book == null) return NotFound("Book doesnt exist.");

        Order order = new Order() { TotalPrice = book.Price, OrderTime = DateTime.Now, UserId = 1 };
        RelOrderBook OrderBook = new RelOrderBook() { Book = book, Order = order};

        _ctx.Add(order);
        _ctx.Add(OrderBook);

        int entries = await _ctx.SaveChangesAsync();
        if (entries != 2) return NotFound("idk man");

        return Ok();
    }
}
