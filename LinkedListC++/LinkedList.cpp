/*
 * LinkedList.cpp
 *
 * Author:      Matheus Schaly
 * Created on:  Jul 17, 2017
 * Description: LinkedList implementation
 */

#include <iostream>

#include "Node.h"
using namespace std;

Node *head = NULL;

/*
 * Inserts a new node in the list
 * Data: data to be stored inside the new node
 * Position: POSITION to add the new node
 */

void insert (int data, int position) {
	Node *temp1 = new Node();
	temp1 -> setData(data);
	if (position == 1) {
		temp1 -> setNext(head);
		head = temp1;
		return;
	}
	Node *temp2 = head;
	for (int i = 2; i < position; i++) {
		temp2 = temp2 -> getNext();
	}
	temp1 -> setNext(temp2 -> getNext());
	temp2 -> setNext(temp1);
}

/*
 * Remove a previously existing node of the list
 * Position: POSITION of the node to be removed
 */

void remove (int position) {
	Node *temp = head;
	Node *prev;
	if (position == 1) {
		head = temp -> getNext();
		return;
	}
	for (int i = 1; i < position; i++) {
		prev = temp;
		temp = temp -> getNext();
	}
	prev -> setNext(temp -> getNext());
}

/*
 * Reverse the list
 */

void reverseList () {
	Node *current, *prev, *next;
	prev = NULL;
	current = head;
	while (current != NULL) {
		next = current -> getNext();
		current -> setNext(prev);
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
		cout << temp -> getData();
		temp = temp -> getNext();
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
