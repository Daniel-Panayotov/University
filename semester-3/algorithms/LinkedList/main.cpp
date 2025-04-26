#include <iostream>;

using namespace std;

struct Node {
public:
	Node* next;
	Node* prev;
	int val;

	Node(int val) : next(nullptr), prev(nullptr) { this->val = val; }
	Node(int val, Node* prev) : next(nullptr) {
		this->val = val;
		this->prev = prev;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	LinkedList(int val) {
		this->head = new Node(val);
		this->tail = this->head;
	}
	~LinkedList() {
		Node* curr = head;
		Node* tmp = head;

		while (curr) {
			curr = curr->next;
			delete tmp;
			tmp = curr;
		}
	}

	void append(int val) {
		Node* tmp = new Node(val);

		if (!tail) { head = tmp; tail = tmp; return; }

		tmp->prev = tail;
		tail->next = tmp;
		tail = tail->next;
	}

	void insert(int val, int index) {
		Node* tmp = new Node(val);
		Node* curr = head;

		if (!curr) { head = tmp; tail = tmp; return; }

		int loopI = 0;
		while (curr && loopI < index) { loopI++; curr = curr->next; }

		if (!curr) { cout << "Invalid index" << endl; return; }

		tmp->next = curr;
		if (curr->prev) curr->prev->next = tmp;
		tmp->prev = curr->prev;
		curr->prev = tmp;
	}

	void remove(int index) {
		Node* curr = head;

		if (!curr) return;

		int loopI = 0;
		while (curr && loopI < index) { loopI++; curr = curr->next; }

		if (!curr) { cout << "Invalid index" << endl; return; }

		if (curr->prev) curr->prev->next = curr->next;
		delete curr;
	}

	void list() {
		Node* curr = head;

		while (curr) {
			cout << curr->val << " -> ";
			curr = curr->next;
		}

		cout << "null" << endl;
	}
};

int main() {
	LinkedList x;

	x.append(0);
	x.append(1);
	x.insert(3, 1);
	x.list();

	x.remove(1);
	x.list();

	return 0;
}