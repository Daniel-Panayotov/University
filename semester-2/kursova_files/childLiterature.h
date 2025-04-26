#pragma once

#include <iostream>
#include "literature.h"

using namespace std;

class ChildLiterature : public Literature {
public:
	ChildLiterature();
	ChildLiterature(int year, const string& title, const string& author, int minAge, int maxAge);
	ChildLiterature(ChildLiterature&);
	~ChildLiterature();
	virtual void displayInfo();
private:
	int minAge;
	int maxAge;
};