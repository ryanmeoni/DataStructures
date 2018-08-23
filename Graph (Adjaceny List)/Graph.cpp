#include "Graph.h"
#include "Node.h" 

Graph::Graph() {}

//adds a node to the graph 
void Graph::addNode(Node* newNode)
{
	this->nodes.push_back(newNode);
}

//creates a directed node edge 
void Graph::createEdge(Node* nodeOne, Node* nodeTwo)
{
	nodeOne->neighbors.push_back(nodeTwo);
}

//returns a node with a given node value
Node* Graph::findNode(int nodeValue)
{
	for (int i = 0; i < this->nodes.size(); i++)
	{
		if (this->nodes[i]->nodeValue == nodeValue) return this->nodes[i]; 
	}
}

Graph::~Graph() {}