using book_store.Models;
using Microsoft.EntityFrameworkCore;

namespace book_store;

public partial class BookStoreContext : DbContext
{
    public BookStoreContext()
    {
    }

    public BookStoreContext(DbContextOptions<BookStoreContext> options)
        : base(options)
    {
    }

    public virtual DbSet<Book> Books { get; set; }

    public virtual DbSet<Order> Orders { get; set; }

    public virtual DbSet<RelOrderBook> RelOrderBooks { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Book>(entity =>
        {
            entity.HasKey(e => e.BookId).HasName("PK__Books__3DE0C2277D470D70");

            entity.Property(e => e.BookId).HasColumnName("BookID");
            entity.Property(e => e.Author).HasMaxLength(50);
            entity.Property(e => e.BookIsbn)
                .HasMaxLength(15)
                .HasColumnName("BookISBN");
            entity.Property(e => e.CoverLink).HasMaxLength(256);
            entity.Property(e => e.Name).HasMaxLength(100);
        });

        modelBuilder.Entity<Order>(entity =>
        {
            entity.HasKey(e => e.OrderId).HasName("PK__Orders__C3905BAFB8B0C7CC");

            entity.Property(e => e.OrderId).HasColumnName("OrderID");
            entity.Property(e => e.OrderTime).HasColumnType("datetime");
            entity.Property(e => e.UserId).HasColumnName("UserID");
        });

        modelBuilder.Entity<RelOrderBook>(entity =>
        {
            entity.HasKey(e => e.RelOrderBooksId).HasName("PK__relOrder__87FB36DA059F26EA");

            entity.ToTable("relOrderBooks");

            entity.Property(e => e.RelOrderBooksId).HasColumnName("relOrderBooksID");
            entity.Property(e => e.BookId).HasColumnName("BookID");
            entity.Property(e => e.OrderId).HasColumnName("OrderID");

            entity.HasOne(d => d.Book).WithMany(p => p.RelOrderBooks)
                .HasForeignKey(d => d.BookId)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK__relOrderB__BookI__3C69FB99");

            entity.HasOne(d => d.Order).WithMany(p => p.RelOrderBooks)
                .HasForeignKey(d => d.OrderId)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK__relOrderB__Order__3B75D760");
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
