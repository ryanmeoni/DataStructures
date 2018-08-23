#pragma once
#include <iostream> 
#include <map> 
#include "Node.h"

class Graph {
public: 

	//Vector of all the nodes in graph. 
	std::vector<Node*> nodes; 

	Graph(); 
	void addNode(Node* newNode);
	void createEdge(Node* nodeOne, Node* nodeTwo); 
	Node* findNode(int nodeValue); 
	~Graph(); 
};