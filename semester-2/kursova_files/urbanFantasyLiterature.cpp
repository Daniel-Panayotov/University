#include <iostream>
#include "urbanFantasyLiterature.h"

using namespace std;

UrbanFantasyLiterature::UrbanFantasyLiterature() : FantasyLiterature() {
	string tempCitySetting;

	cout << "Enter city setting: ";
	cin >> tempCitySetting;

	citySetting.replace(citySetting.begin(), citySetting.end(), tempCitySetting);
}

UrbanFantasyLiterature::UrbanFantasyLiterature
(int year, const string& title, const string& author, const string& worldSetting
	, const string& magicSystem, const string& citySetting)
	: FantasyLiterature(year, title, author, worldSetting, magicSystem)
	, citySetting(citySetting)
{}

UrbanFantasyLiterature::UrbanFantasyLiterature(UrbanFantasyLiterature& lit)
	: FantasyLiterature(lit.year, lit.title, lit.author, lit.worldSetting, lit.magicSystem)
	, citySetting(lit.citySetting)
{}

UrbanFantasyLiterature::~UrbanFantasyLiterature() {}

void UrbanFantasyLiterature::displayInfo() {
	cout << "Urban Fantasy Literature: " << "Release Year: " << year << ", Title: " << title << ", Author: " << author
		<< ", World setting: " << worldSetting << ", Magic system: " << magicSystem << ", City setting: " << citySetting << endl;
}