#pragma once

#include <iostream>
#include "literature.h"
using namespace std;


class TechnicalLiterature : public Literature{
public:
	TechnicalLiterature();
	TechnicalLiterature(int year, const string& title, const string& author, const string& field, const string& description);
	TechnicalLiterature(TechnicalLiterature&);
	~TechnicalLiterature();
	virtual void displayInfo();
private:
	string field;
	string description;
};