/*
 * Node.h
 *
 * Author:      Matheus Schaly
 * Created on:  Jul 17, 2017
 * Description: Defines the Node object
 */

#ifndef NODE_H_
#define NODE_H_
using namespace std;

class Node {
	int data;
	Node *next;
public:
	int getData ();
	void setData (int data);
	Node* getNext ();
	void setNext (Node *next);
};

#endif /* NODE_H_ */
