#include <iostream>
#include <vector>

using namespace std;

struct Node {
	Node* next;
	int value;
	Node(int value) {
		next = nullptr;
		this->value = value;
	}
};

void main() {
	
}

//EX2
int getCount(Node* head) {
    int count = 0;
    Node* curr = head;

    while (curr) {
        count++;
        curr = curr->next;           
    }

    return count;
}

//EX3
int getMax(Node* head) {
	int max = head->value;
    Node* curr = head->next;

    while (curr) {
		if (max < curr->value) max = curr->value;
        curr = curr->next;           
    }

    return max;
}

//EX4
void findUnique(Node* head) {
     Node* curr = head;
	 vector<int> nums;

	 while (curr) {
		 bool isMatch = false;

		 for (int i = 0; i < nums.size(); i++) 		 
			 if (nums[i] == curr->value) {
				 isMatch = true;
				 break;
			 }
		 
		 if (!isMatch) {
			 nums.push_back(curr->value);
			 cout << curr->value;
		 } 
		 
		 curr = curr->next;
	 }
}
	
//EX5
struct FrequencyDesc {
	int value;
	int found;

	FrequencyDesc(int value) {
		this->value = value;
		found = 0;
	}
};

FrequencyDesc findMostFrequent(Node* head) {
	Node* curr = head;
	vector<FrequencyDesc> list;

	while (curr) {
		bool isMatch = false;

		for (int i = 0; i < list.size(); i++) 
			if (list[i].value == curr->value) {
				isMatch = true;
				list[i].found++;
				break;
	        };

		if (!isMatch) list.push_back(FrequencyDesc(curr->value));

		curr = curr->next;
	}

	FrequencyDesc mostFound = list[0];
	for (int i = 1; i < list.size(); i++)
		if (mostFound.found < list[i].found) mostFound = list[i];

	return mostFound;
}

//EX6 is the same as EX4

//EX7
void append(Node* head, int value) {
	Node* curr = head;

	while (curr) curr = curr->next;

	Node* temp = new Node(value);
	curr->next = temp;
}

//EX8
void pop(Node* head) {
	Node* temp = head;
	head = head->next;
	delete temp;
}