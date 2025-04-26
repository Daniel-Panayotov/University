#include <iostream>
#include "fantasyLiterature.h"

using namespace std;

FantasyLiterature::FantasyLiterature() : Literature() {
	string tempWorldSetting;
	string tempMagicSystem;

	cout << "Enter world setting: ";
	cin >> tempWorldSetting;

	cout << "Enter magic system: ";
	cin >> tempMagicSystem;

	worldSetting.replace(worldSetting.begin(), worldSetting.end(), tempWorldSetting);
	magicSystem.replace(magicSystem.begin(), magicSystem.end(), tempMagicSystem);
}

FantasyLiterature::FantasyLiterature(int year, const string& title, const string& author, const string& worldSetting, const string& magicSystem)
	: Literature(year, title, author)
	, worldSetting(worldSetting)
	, magicSystem(magicSystem)
{}

FantasyLiterature::FantasyLiterature(FantasyLiterature& lit)
	: Literature(lit.year, lit.title, lit.author)
	, worldSetting(lit.worldSetting)
	, magicSystem(lit.magicSystem)
{}

FantasyLiterature::~FantasyLiterature() {}

void FantasyLiterature::displayInfo() {
	cout << "Fantasy literature: " << "Release Year: " << year << ", Title: " << title << ", Author: " << author
		<< ", World setting: " << worldSetting << ", Magic system: " << magicSystem << endl;
}