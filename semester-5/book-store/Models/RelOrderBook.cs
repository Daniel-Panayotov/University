namespace book_store.Models;

public partial class RelOrderBook
{
    public int RelOrderBooksId { get; set; }

    public int OrderId { get; set; }

    public int BookId { get; set; }

    public virtual Book Book { get; set; } = null!;

    public virtual Order Order { get; set; } = null!;
}
