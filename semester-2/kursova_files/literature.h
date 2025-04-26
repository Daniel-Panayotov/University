#pragma once

#include <iostream>
using namespace std;

class Literature {
public:
	Literature();
	Literature(int year, const string& title, const  string& author);
	Literature(Literature&);
	~Literature();
	virtual void displayInfo();
protected:
	int year;
	string title;
	string author;
};