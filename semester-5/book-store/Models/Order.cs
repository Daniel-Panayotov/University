using System;
using System.Collections.Generic;

namespace book_store.Models;

public partial class Order
{
    public int OrderId { get; set; }

    public int UserId { get; set; }

    public DateTime OrderTime { get; set; }

    public double TotalPrice { get; set; }

    public virtual ICollection<RelOrderBook> RelOrderBooks { get; set; } = new List<RelOrderBook>();
}
