#pragma once

#include <iostream>
#include "fantasyLiterature.h"

using namespace std;

class UrbanFantasyLiterature : public FantasyLiterature {
public:
	UrbanFantasyLiterature();
	UrbanFantasyLiterature(int year, const string& title, const string& author, const string& worldSetting
		, const string& magicSystem, const string& citySetting);
	UrbanFantasyLiterature(UrbanFantasyLiterature&);
	~UrbanFantasyLiterature();
	virtual void displayInfo();
private:
	string citySetting;
};
