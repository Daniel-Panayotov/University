using System;
using System.Collections.Generic;

namespace book_store.Models;

public partial class Book
{
    public int BookId { get; set; }

    public string BookIsbn { get; set; } = null!;

    public string Name { get; set; } = null!;

    public string Author { get; set; } = null!;

    public string? CoverLink { get; set; }

    public int Pages { get; set; }

    public int Year { get; set; }

    public double Price { get; set; }

    public virtual ICollection<RelOrderBook> RelOrderBooks { get; set; } = new List<RelOrderBook>();
}
