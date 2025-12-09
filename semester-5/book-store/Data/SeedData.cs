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
                CoverLink = "https://m.media-amazon.com/images/I/81Tbf79ePML._SY466_.jpg",
                Pages = 291,
                Year = 2016,
                Price = 20,
            },
            new Book
            {
                BookIsbn = "9781804995518",
                Name = "Gardens Of The Moon (Malazan Book Of The Fallen 1)",
                Author = "Steven Erikson",
                CoverLink = "https://m.media-amazon.com/images/I/71XHJct7u3L._SY466_.jpg",
                Pages = 494,
                Year = 2009,
                Price = 35,
            },
            new Book
            {
                BookIsbn = "1250868289",
                Name = "Mistborn: The Final Empire",
                Author = "Brandon Sanderson",
                CoverLink = "https://m.media-amazon.com/images/I/811qBmIYTFL._SY466_.jpg",
                Pages = 576,
                Year = 2023,
                Price = 15,
            },
            new Book 
            { 
                BookIsbn = "0999851160",
                Name = "Of Shadow and Sea (The Elder Empire - Shadow Book 1)",
                Author = "Will Wight",
                CoverLink = "https://m.media-amazon.com/images/I/81TbK-AKcOL._SY522_.jpg",
                Pages = 404,
                Year = 2014,
                Price = 15,
            },
            new Book
            {
                BookIsbn = " 784 ",
                Name = "The Wheel of Time - The Eye of the World",
                Author = "Robert Jordan",
                CoverLink = "https://upload.wikimedia.org/wikipedia/en/thumb/0/00/WoT01_TheEyeOfTheWorld.jpg/250px-WoT01_TheEyeOfTheWorld.jpg",
                Pages = 784,
                Year = 1964,
                Price = 30,
            });            

        context.SaveChanges();
    }
}