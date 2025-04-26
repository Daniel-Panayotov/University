#include <iostream>

using namespace std;

struct Node {
	int info;
	Node* next;

	Node(int info) {	  
		this->info = info;
		this->next = nullptr;
	}

	Node(int info, Node* next) {
	    this->info = info;
		this->next = next;
	}
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList() {	
		this->head = nullptr;
	};

    LinkedList(int info) {	
		this->head = new Node(info);
	}

	~LinkedList() {
		if (!head) return;

		Node* tmp = head;

		while (head) {
			head = head->next;
			delete tmp;
			tmp = head;
		}

		delete tmp;
	}

	void LinkedList::deleteN(int n) {
		if (!head) { cout << "LinkedList is emptry"; return; }

		Node* curr = head->next;
		Node* prev = head;
		int i = 1;

		while(i < n && curr) {
			prev = curr;
			curr = curr->next;
		}

		if (i != n - 1) { cout << "Couldn't reach element: " << n; return; }
		if (!curr->next) { delete curr; return; }

		prev->next = curr->next;
		delete curr;		
	}
};

void main() {
	auto LL = new LinkedList(5);

	LL->deleteN(5);	
}