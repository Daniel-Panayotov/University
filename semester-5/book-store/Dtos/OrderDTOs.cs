using book_store.Models;

namespace book_store.Dtos;

public record paginatedOrdersDTO
(
    int pages,
    IEnumerable<OrderDTO> orders
);

public record OrderDTO
(
    int OrderID,
    int UserID,
    DateTime OrderTime,
    double TotalPrice,
    IEnumerable<BookDTO> books 
);

public static class OrderMappings
{
    public static OrderDTO ToDTO(this Order src) => new OrderDTO (
        src.OrderId,
        src.UserId,
        src.OrderTime,
        src.TotalPrice,
        src.RelOrderBooks.Select(ob => ob.ToBookDTO())
    );

    public static BookDTO ToBookDTO(this RelOrderBook src) => src.Book.ToDTO();      
}