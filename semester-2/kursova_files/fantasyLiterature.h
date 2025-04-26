#pragma once

#include <iostream>
#include "literature.h"

using namespace std;

class FantasyLiterature : public Literature {
public:
	FantasyLiterature();
	FantasyLiterature(int year, const string& title, const string& author, const string& worldSetting, const string& magicSystem);
	FantasyLiterature(FantasyLiterature&);
	~FantasyLiterature();
	virtual void displayInfo();
protected:
	string worldSetting;
	string magicSystem;
};