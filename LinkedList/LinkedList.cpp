#include <iostream>
#include "LinkedList.h"
 


LinkedList::LinkedList() {

	this->head = NULL; 

}

void LinkedList::insert(int data) 
{
	Node *newNode = new Node(); 
	newNode->data = data; 
	newNode->next = head; 
	this->head = newNode; 

}

void LinkedList::deleteNode(int data)
{
	Node *current = this->head; 
	Node *previous = NULL;

	while (current != NULL)
	{

		if (current->data == data)
		{

			if (current == head)
			{
				Node *temp = new Node(); 
				temp = head; 
				head = head->next; 
				delete temp; 
				break; 
			}

			previous->next = current->next; 
			delete current; 
			break; 
		}

		previous = current; 
		current = current->next; 
	}
}

void LinkedList::printNodes()
{

	Node *current = this->head; 

	while (current != NULL)
	{

		std::cout << current->data << std::endl; 
		current = current->next; 


	}


}

Node* LinkedList::findNode(int d)
{
	Node *current = this->head; 

	while (current != NULL)
	{

		if (current->data == d) { return current;}

		current = current->next; 
	}
}

void LinkedList::deleteMiddleNode(Node *toDelete)
{
	Node *nextNode = toDelete->next;

	toDelete->data = nextNode->data;

	toDelete->next = nextNode->next;

	delete nextNode;

}