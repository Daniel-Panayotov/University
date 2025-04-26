#pragma once

#include <iostream>
#include "literature.h"

using namespace std;

class PoeticLiterature : public Literature {
public:
	PoeticLiterature();
	PoeticLiterature(int year, const string& title, const string& author, const string& poeticForm, const string& poeticTheme);
	PoeticLiterature(PoeticLiterature&);
	~PoeticLiterature();
	virtual void displayInfo();
private:
	string poeticForm;
	string poeticTheme;
};
