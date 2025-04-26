#pragma once

#include "literature.h"
#include "childLiterature.h"

struct Node {
	Literature* data;
	Node* nextPtr;

	Node(Literature* data) : data(data), nextPtr(nullptr) {}
	Node(Literature* data, Node* ptr) : data(data), nextPtr(ptr) {}
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void insert(Literature* lit);
	void display();
private:
	Node* head;
	Node* tail;
};
