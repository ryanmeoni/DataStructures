#pragma once
#include <iostream>
#include <map> 
#include "Node.h"

class LinkedList
{

public: 

	Node *head; 

	LinkedList(); 
	void insert(int data); 
	void deleteNode(int data); 
	void printNodes();  
	Node* findNode(int d); 
	void deleteMiddleNode(Node *toDelete); 
	


	~LinkedList() {
		std::cout << "List deleted." << std::endl; 
	}
};