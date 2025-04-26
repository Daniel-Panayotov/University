#include <iostream>
#include "poeticLiterature.h"

using namespace std;

PoeticLiterature::PoeticLiterature() : Literature() {
	string tempPoeticForm;
	string tempPoeticTheme;

	cout << "Enter poetic form: ";
	cin >> tempPoeticForm;

	cout << "Enter poetic theme: ";
	cin >> tempPoeticTheme;

	poeticForm.replace(poeticForm.begin(), poeticForm.end(), tempPoeticForm);
	poeticTheme.replace(poeticTheme.begin(), poeticTheme.end(), tempPoeticTheme);
}

PoeticLiterature::PoeticLiterature(int year, const string& title, const string& author, const string& poeticForm, const string& poeticTheme) 
	: Literature(year, title, author)
	, poeticForm(poeticForm)
	, poeticTheme(poeticTheme)
{}

PoeticLiterature::PoeticLiterature(PoeticLiterature& lit)
	: Literature(lit.year, lit.title, lit.author)
	, poeticForm(lit.poeticForm)
	, poeticTheme(lit.poeticTheme) 
{}

PoeticLiterature::~PoeticLiterature() {}

void PoeticLiterature::displayInfo() {
	cout << "Poetic literature: " << "Release Year: " << year << ", Title: " << title << ", Author: " << author
		<< ", poetic form: " << poeticForm << ", poetic theme: " << poeticForm << endl;
}