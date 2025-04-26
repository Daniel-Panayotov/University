#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Person {
private:
	int age;
	 char* name;
public:
	void setData(void);
	void display(void);
};

void Person::setData() {
	char buf[20];
	cout << "Enter name: ";
	cin >> buf;
	name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	cout << "Enter Age: ";
	cin >> age;
}

void Person::display() {
	cout << "My name is: " << name << " and my age is: " << age << endl;
}

void main() {
	Person Ivan;
	Ivan.setData();
	Ivan.display();
}