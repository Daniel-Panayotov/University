#include "literature.h"
#include <iostream>

using namespace std;

Literature::Literature() {
	string tempTitle;
	string tempAuthor;

	cout << "Enter release year of book: ";
	cin >> year;

	cout << "Enter book name: ";
	cin >> tempTitle;

	cout << "Enter author name: ";
	cin >> tempAuthor;

	title.replace(title.begin(), title.end(), tempTitle);
	author.replace(author.begin(), author.end(), tempAuthor);
}

Literature::Literature(int year, const string& title, const string& author) 
	: year(year)
	, title(title)
	, author(author)
{}

Literature::Literature(Literature& lit) 
	: year(lit.year)
	, title(lit.title)
	, author(lit.author) 
{}

Literature::~Literature() {}

void Literature::displayInfo() {
	cout << "Literature: " << "Book year: " << year << ", Book title: " << title << ", Author: " << author << endl;
}