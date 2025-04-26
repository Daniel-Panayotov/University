#include <iostream>;
#include <string>;

using namespace std;

struct Node {
public:
	Node* left;
	Node* right;
	int val;

	Node(int val) : left(nullptr), right(nullptr) {
		this->val = val;
	}
};

class Tree {
private:
	Node* root;

	void printL(Node* node) {
		if (!node) return;

		printL(node->left);
		cout << node->val;
		printL(node->right);
	}

	void printR(Node* node) {
		if (!node) return;

		printR(node->right);
		cout << node->val;
		printR(node->left);
	}

	void destruct(Node* node) {
		if (!node) return;

		destruct(node->left);
		destruct(node->right);

		delete node;
	}

	Node* createTree() {
		int x;

		cin >> x;
		if (x == 0) return nullptr;

		Node* tmp = new Node(x);

		tmp->left = createTree();
		tmp->right = createTree();

		return tmp;
	}

public:
	Tree() : root(nullptr) {}
	Tree(int val) { root = new Node(val); }
	~Tree() { destruct(root); }

	void printLeft() { printL(root); }
	void printRight() {	printR(root); }

	void buildTree() {
		root = createTree();
	}
};

int main() {
	Tree x;

	x.buildTree();

	x.printLeft();

	return 0;
}