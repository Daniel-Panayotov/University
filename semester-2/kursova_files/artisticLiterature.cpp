#include <iostream>
#include "artisticLiterature.h"

using namespace std;

ArtisticLiterature::ArtisticLiterature() : Literature() {
	string tempArtStyle;
	string tempVisualElement;

	cout << "Enter art style( Renaissance, Surrealism... ): ";
	cin >> tempArtStyle;

	cout << "Enter visual element: ";
	cin >> tempVisualElement;

	artStyle.replace(artStyle.begin(), artStyle.end(), tempArtStyle);
	visualElement.replace(visualElement.begin(), visualElement.end(), tempVisualElement);
}

ArtisticLiterature::ArtisticLiterature(int year, const string& title, const string& author, const string& artStyle, const string& visualElement)
	: Literature(year, title, author)
	, artStyle(artStyle)
	, visualElement(visualElement)
{}

ArtisticLiterature::ArtisticLiterature(ArtisticLiterature& lit)
	: Literature(lit.year, lit.title, lit.author)
	, artStyle(lit.artStyle)
	, visualElement(lit.visualElement)
{}

ArtisticLiterature::~ArtisticLiterature() {}

void ArtisticLiterature::displayInfo() {
	cout << "Artistic literature: " << "Release Year: " << year << ", Title: " << title << ", Author: " << author
		<< ", Art style: " << artStyle << ", Visual element: " << visualElement << endl;
}