#include <iostream>
#include "technicalLiterature.h"

using namespace std;

TechnicalLiterature::TechnicalLiterature() : Literature() {
	string tempField;
	string tempDescription;

	cout << "Enter field of study: ";
	cin >> tempField;
	
	cout << "Enter description: ";
	cin >> tempDescription;

	field.replace(field.begin(), field.end(), tempField);
	description.replace(description.begin(), description.end(), tempDescription);
}

TechnicalLiterature::TechnicalLiterature(int year, const string& title, const string& author, const string& field, const string& description) 
	: Literature(year, title, author)
	, field(field)
	, description(description)
{}

TechnicalLiterature::TechnicalLiterature(TechnicalLiterature& lit) 
	: Literature(lit.year, lit.title, lit.author)
	, field(lit.field)
	, description(lit.description)
{}

TechnicalLiterature::~TechnicalLiterature() {}

void TechnicalLiterature::displayInfo() {
	cout << "Technical literature: " << "Release Year: " << year << ", Title: " << title << ", Author: " << author 
		<< ", field of study: " << field << ", description: " << description << endl;
}