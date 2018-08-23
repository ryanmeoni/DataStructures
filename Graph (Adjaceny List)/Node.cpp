#include "Node.h"
#include "Graph.h"
#include <iostream> 


Node::Node(int nodeValue) {

	this->nodeValue = nodeValue; 
	this->visited = false; 
}

Node::~Node() {}
