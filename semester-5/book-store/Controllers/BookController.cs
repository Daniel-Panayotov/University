using Microsoft.AspNetCore.Mvc;

namespace book_store.Controllers;

[ApiController]
[Route("api/books")]
public class BookController : Controller
{
    [HttpGet("getPaginated")]
    public IActionResult getPaginated([FromQuery] int page, [FromQuery] int pageSize)
    {
        return Ok();
    }
}
