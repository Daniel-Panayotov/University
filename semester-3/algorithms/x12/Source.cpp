#include <iostream>;

using namespace std;

struct Node {
public:
	int val;
	Node* L;
	Node* R;

	Node::Node(int val) {
		this->val = val;	
	}
};

class OrderedTree {
private:
	Node* root;

	void printAsc(Node* n) {
		if (!n) return;

		printAsc(n->R);
		cout << n->val;
	    printAsc(n->L);
	}

	void printDesc(Node* n) {
		if (!n) return;

	    printDesc(n->L);
	    cout << n->val;
	    printDesc(n->R);
	}

	void insertAsc(Node* n, int val) {
		if (val >= n->val) {
			if (!n->R) n->R = new Node(val);
			else insertAsc(n->R, val);
		}
		else if (!n->L) n->L = new Node(val);
		else insertAsc(n->L, val);
	}

public:
	void insert(int val) {
		if (!root) { root = new Node(val); return; }

		insertAsc(root, val);
	}

	void print(bool vuzh = true) {
		if (vuzh) printAsc(root);
		else printDesc(root);	    
    }
};

void main() {
	OrderedTree tree;

	tree.insert(1);
}

