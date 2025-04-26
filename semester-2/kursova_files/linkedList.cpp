#include <iostream>
#include "linkedList.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
	Node* curr = head;
	Node* tmp = head;

	while (curr) {
		tmp = curr->nextPtr;
		delete curr;
		curr = tmp;
	}
}

void LinkedList::insert(Literature* lit) {
	auto new_node = new Node(lit);

	if (head == nullptr) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->nextPtr = new_node;
		tail = new_node;
	}
}

void LinkedList::display() {
	
	auto currPtr = head;

	while (currPtr) {
		currPtr->data->displayInfo();
		cout << " -> ";
		currPtr = currPtr->nextPtr;
	}
	cout << "null";
}