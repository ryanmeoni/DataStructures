#include "Graph.h"
#include "Node.h" 

Graph::Graph() {}

//adds a node to the graph 
void Graph::addNode(std::shared_ptr<Node>& newNode)
{
	this->nodes.emplace_back(newNode);
}

//creates a directed node edge 
void Graph::createEdge(std::shared_ptr<Node>& nodeOne, std::shared_ptr<Node>& nodeTwo)
{
	nodeOne->neighbors.emplace_back(nodeTwo);
}

//returns a node with a given node value
std::shared_ptr<Node> Graph::findNode(int nodeValue)
{
	for (int i = 0; i < this->nodes.size(); i++)
	{
		if (this->nodes[i]->nodeValue == nodeValue) return this->nodes[i]; 
	}
}

Graph::~Graph() {}