#pragma once
#include <iostream> 
#include <vector> 

class Node {
public: 
	int nodeValue; 
	bool visited; 
	std::vector<Node*> neighbors; 

	Node(int nodeValue); 
	~Node(); 
};