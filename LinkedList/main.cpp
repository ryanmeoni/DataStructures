#include <iostream>
#include <string> 
#include "Node.h" 
#include "LinkedList.h"

void printNodes(Node* head)
{
	Node *current = head;

	while (current != NULL)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}
int main()
{

	LinkedList list = LinkedList(); 

	list.insert(5); 
	list.insert(7); 
	list.insert(20); 
	list.insert(30); 
	list.insert(50); 
	list.insert(3); 
	list.insert(7);
	list.insert(30); 

	list.printNodes(); 

	std::cout << "######" << std::endl; 

	int deleteValue = 20; 

	Node *toDelete = list.findNode(deleteValue); 

	list.deleteMiddleNode(toDelete); 

	list.printNodes(); 
	return 0; 
}