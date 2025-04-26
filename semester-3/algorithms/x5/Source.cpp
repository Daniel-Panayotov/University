#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string value;
	int seenCount;
	Node* next;
  
	Node(string value) {
	    this->value = value;
		this->next = nullptr;
		this->seenCount = 1;
	};
};

class LinkedList {
private: 
    Node* head;
	Node* tail;

public:
	LinkedList(string value) {
	    Node* node = new Node(value);
	    this->head = node;
		this->tail = node;
	}

	~LinkedList() {
        Node* curr = this->tail;
		Node* next = nullptr;

		while(curr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}

	void LinkedList::appendSorted(string value) {
		Node* curr = this->tail;
		Node* prev = nullptr;

		while(curr->value < value) {	
			prev = curr;
			curr = curr->next;
			if (!curr) break;
		};

		if (!curr) {
		    Node* newNode = new Node(value);
			prev->next = newNode;
		} else if (curr->value > value) {
			Node* newNode = new Node(value);
			prev->next = newNode;
		} else curr->seenCount++;
	}
};

void main() {
	string input = "";
	LinkedList* ll = new LinkedList("a");
	while(input != "exit") {
	    cout << "Enter string or close program with 'exit': ";
		cin >> input;

		ll->appendSorted(input);
	}
}