using book_store.Models;
using Microsoft.EntityFrameworkCore;

namespace book_store.Data;

public class SeedData
{
    public static void Initialize(IServiceProvider serviceProvider)
    {
        using var context = new BookStoreContext(
            serviceProvider.GetRequiredService<
                DbContextOptions<BookStoreContext>>());

        if (context == null || context.Books == null)
        {
            throw new NullReferenceException(
                "Null dbContext or books DbSet");
        }

        if (context.Books.Any()) return;
        

        context.Books.AddRange(
            new Book
            {
                BookIsbn = "1959001345",
                Name = "Unsouled (Cradle Book 1)",
                Author = "Will Wight",
                Pages = 291,
                Year = 2016,
                Price = 20,
            },
            new Book
            {
                BookIsbn = "9781804995518",
                Name = "Gardens Of The Moon (Malazan Book Of The Fallen 1)",
                Author = "Steven Erikson",
                Pages = 494,
                Year = 2009,
                Price = 35,
            },
            new Book
            {
                BookIsbn = "1250868289",
                Name = "Mistborn: The Final Empire",
                Author = "Brandon Sanderson",
                Pages = 576,
                Year = 2023,
                Price = 15,
            });

        context.SaveChanges();
    }
}