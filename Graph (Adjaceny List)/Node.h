#pragma once
#include <iostream> 
#include <vector> 
#include <memory>

class Node {
public: 
	int nodeValue; 
	bool visited; 
	std::vector<std::shared_ptr<Node>> neighbors; 

	Node(int nodeValue); 
	~Node(); 
};