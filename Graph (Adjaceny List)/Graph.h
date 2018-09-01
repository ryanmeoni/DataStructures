#pragma once
#include <iostream> 
#include <memory>
#include "Node.h"

class Graph {
public: 

	//Vector of all the nodes in graph. 
	std::vector<std::shared_ptr<Node>> nodes; 

	Graph(); 
	void addNode(std::shared_ptr<Node>& newNode);
	void createEdge(std::shared_ptr<Node>& nodeOne, std::shared_ptr<Node>& nodeTwo); 
	std::shared_ptr<Node> findNode(int nodeValue); 
	~Graph(); 
};