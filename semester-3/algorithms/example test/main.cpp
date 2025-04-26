#include <string>
#include <iostream>

using namespace std;

struct Node {
public:
	string info;
	Node* left;
	Node* right;

	Node(string info) : left(nullptr), right(nullptr) { this->info = info; }
};

int countStr(Node* node) {
	if (!node) return 0;

	return countStr(node->left) + countStr(node->right) + (node->info[0] == '?' ? 1 : 0);
}

int main() {
	Node* x = new Node("?hi");

	x->left = new Node("no");
	x->right = new Node("?no");

	x->left->left = new Node("?yo");

	cout << countStr(x);

	return 0;
}