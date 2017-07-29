//============================================================================
// Name        : LinkedList.cpp
// Author      : Matheus Henrique Schaly
// Date        : Jul 17, 2017
// Description : Linked List implementation
//============================================================================

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *head = NULL;

/*
 * Inserts a new node in the list
 * Data: data to be stored inside the new node
 * Position: POSITION to add the new node
 */

void insert (int data, int position) {
	Node *temp1 = new Node(); // Creating the new node to be inserted
	temp1 -> data = data; // Including the data inside new node
	if (position == 1) {
		temp1 -> next = head;
		head = temp1;
		return;
	}
	Node *temp2 = head;
	for (int i = 2; i < position; i++) {
		temp2 = temp2 -> next;
	}
	temp1 -> next = temp2 -> next;
	temp2 -> next = temp1;
}

/*
 * Remove a previously existing node of the list
 * Position: POSITION of the node to be removed
 */

void remove (int position) {
	Node *temp = head;
	Node *prev;
	if (position == 1) {
		head = temp -> next;
		return;
	}
	for (int i = 1; i < position; i++) {
		prev = temp;
		temp = temp -> next;
	}
	prev -> next = temp -> next;
}

/*
 * Reverse the list
 */

void reverseList () {
	Node *current, *prev, *next;
	prev = NULL;
	current = head;
	while (current != NULL) {
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

/*
 * Prints the whole list
 */

void printList () {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp -> data;
		temp = temp -> next;
	}
	cout << endl;
}

int main() {
	insert(2, 1); // 2
	insert(3, 2); // 2 3
	insert(4, 1); // 4 2 3
	insert(5, 2); // 4 5 2 3
	remove(2); // 4 2 3
	insert(5, 1); // 5 4 2 3
	printList(); // 5 4 2 3
	remove(1); // 4 2 3
	remove(3); // 4 2
	remove(1); // 2
	insert(3, 2); // 2 3
	insert(1, 3); // 2 3 1
	printList(); // 2 3 1
	reverseList (); // 1 3 2
	printList(); // 1 3 2
	insert(7, 1); // 7 1 3 2
	insert(8, 4); // 7 1 3 8 2
	printList(); // 7 1 3 8 2
	reverseList(); // 2 8 3 1 7
	printList(); // 2 8 3 1 7
}
