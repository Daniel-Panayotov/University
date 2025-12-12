using book_store.Dtos;
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

    [HttpGet("get-paginated")]
    public async Task<IActionResult> getPaginated([FromQuery] string? search, [FromQuery] int? pageSize = 8, [FromQuery] int? page = 1)
    {
        if (string.IsNullOrWhiteSpace(search)) search = "";

        var query = _ctx.Orders
            .Where(o => o.RelOrderBooks.Any(ob => ob.Book.Name.ToLower().Contains(search.ToLower())
                                         || ob.Book.Author.ToLower().Contains(search.ToLower())))
            .Include(o => o.RelOrderBooks)
                .ThenInclude(ob => ob.Book)            
            .AsQueryable();

        var count = await query.CountAsync();
        if (count < (page.Value - 1) * pageSize.Value) return BadRequest("Invalid page.");

        List<Order> orders = await query
            .Skip((page.Value - 1) * pageSize.Value)
            .Take(pageSize.Value)
            .ToListAsync();

        IEnumerable<OrderDTO> orderDTOs =  orders.Select(o => o.ToDTO());

        return Ok(new paginatedOrdersDTO((int)Math.Ceiling((double)count / (page.Value * pageSize.Value)), orderDTOs));
    }
}
