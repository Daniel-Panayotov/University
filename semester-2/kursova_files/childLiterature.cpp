#include "childLiterature.h"
#include <iostream>

using namespace std;

ChildLiterature::ChildLiterature() : Literature() {
	cout << "Enter minimum age for reading: ";
	cin >> minAge;
	cout << "Enter maximum age for reading: ";
	cin >> maxAge;
}

ChildLiterature::ChildLiterature(int year, const string& title, const string& author, int minAge, int maxAge) 
	: Literature(year, title, author)
	, minAge(minAge)
	, maxAge(maxAge)
{}

ChildLiterature::ChildLiterature(ChildLiterature& lit)
	: Literature(lit.year, lit.title, lit.author)
	, minAge(lit.minAge)
	, maxAge(lit.maxAge) 
{}

ChildLiterature::~ChildLiterature()  {}

void ChildLiterature::displayInfo() {
	cout << "Child literature: " << "Release Year: " << year << ", Title: " << title << ", Author: " << author 
		<< ", min Age: " << minAge << ", max Age: " << maxAge << endl;
}