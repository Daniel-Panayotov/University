#pragma once

#include <iostream>
#include "literature.h"

using namespace std;

class ArtisticLiterature : public Literature {
public:
	ArtisticLiterature();
	ArtisticLiterature(int year, const string& title, const string& author, const string& artStyle, const string& visualElement);
	ArtisticLiterature(ArtisticLiterature&);
	~ArtisticLiterature();
	virtual void displayInfo();
private:
	string artStyle;
	string visualElement;
};