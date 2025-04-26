#pragma once

#include <iostream>
#include "highFantasyLiterature.h"

using namespace std;

HighFantasyLiterature::HighFantasyLiterature() : FantasyLiterature() {
	string tempRealmType;

	cout << "Enter realm type: ";
	cin >> tempRealmType;

	realmType.replace(realmType.begin(), realmType.end(), tempRealmType);
}

HighFantasyLiterature::HighFantasyLiterature
(int year, const string& title, const string& author, const string& worldSetting
	, const string& magicSystem, const string& realmType)
	: FantasyLiterature(year, title, author, worldSetting, magicSystem)
	, realmType(realmType)
{}

HighFantasyLiterature::HighFantasyLiterature(HighFantasyLiterature& lit)
	: FantasyLiterature(lit.year, lit.title, lit.author, lit.worldSetting, lit.magicSystem)
	, realmType(lit.realmType)
{}

HighFantasyLiterature::~HighFantasyLiterature() {}

void HighFantasyLiterature::displayInfo() {
	cout << "High Fantasy Literature: " << "Release Year: " << year << ", Title: " << title << ", Author: " << author
		<< ", World setting: " << worldSetting << ", Magic system: " << magicSystem << ", Realm type: " << realmType << endl;
}