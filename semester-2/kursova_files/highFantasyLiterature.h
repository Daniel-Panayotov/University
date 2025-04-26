#pragma once

#include <iostream>
#include "fantasyLiterature.h"

using namespace std;

class HighFantasyLiterature : public FantasyLiterature {
public:
	HighFantasyLiterature();
	HighFantasyLiterature(int year, const string& title, const string& author, const string& worldSetting
		, const string& magicSystem, const string& realmType);
	HighFantasyLiterature(HighFantasyLiterature&);
	~HighFantasyLiterature();
	virtual void displayInfo();
private:
	string realmType;
};
