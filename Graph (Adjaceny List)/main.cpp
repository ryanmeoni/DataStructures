#include <iostream> 
#include "Graph.h"
#include "Node.h"
#include <queue>
#include <memory>

//Depth First Search. 
void DFS(std::shared_ptr<Node>& root)
{
	std::cout << root->nodeValue << std::endl; 

	root->visited = true; 

	for (int i = 0; i < root->neighbors.size(); i++)
	{
		bool status = root->neighbors[i]->visited;
		if (status == false)
		{
			DFS(root->neighbors[i]);
		}
	}
}

//Breadth First Search. 
void BFS(std::shared_ptr<Node>& root)
{

	std::queue<std::shared_ptr<Node>> queue;
	root->visited = true; 

	queue.push(root); 

	while (!queue.empty())
	{
		std::shared_ptr<Node> curr = queue.front(); 
		queue.pop(); 
		std::cout << curr->nodeValue << std::endl; 

		for (int i = 0; i < curr->neighbors.size(); i++)
		{
			if (curr->neighbors[i]->visited == false)
			{
				curr->neighbors[i]->visited = true; 
				queue.push(curr->neighbors[i]); 
			}
		}
	}
}

int main()
{
	Graph Graph;

	std::shared_ptr<Node> nodeOne = std::make_shared<Node>(1);
	std::shared_ptr<Node> nodeTwo = std::make_shared<Node>(2);
	std::shared_ptr<Node> nodeThree = std::make_shared<Node>(3);
	std::shared_ptr<Node> nodeFour = std::make_shared<Node>(4);
	std::shared_ptr<Node> nodeFive = std::make_shared<Node>(5);
	std::shared_ptr<Node> nodeSix = std::make_shared<Node>(6);
	std::shared_ptr<Node> nodeSeven = std::make_shared<Node>(7);
	std::shared_ptr<Node> nodeEight = std::make_shared<Node>(8);
	std::shared_ptr<Node> nodeNine = std::make_shared<Node>(9);
	std::shared_ptr<Node> nodeTen = std::make_shared<Node>(10);

	Graph.addNode(nodeOne);
	Graph.addNode(nodeTwo);
	Graph.addNode(nodeThree);
	Graph.addNode(nodeFour);
	Graph.addNode(nodeFive);
	Graph.addNode(nodeSix);
	Graph.addNode(nodeSeven);
	Graph.addNode(nodeEight);
	Graph.addNode(nodeNine);
	Graph.addNode(nodeTen);

	Graph.createEdge(nodeOne, nodeTwo);
	Graph.createEdge(nodeTwo, nodeFour);
	Graph.createEdge(nodeThree, nodeFour);
	Graph.createEdge(nodeOne, nodeSix);
	Graph.createEdge(nodeFive, nodeTwo);
	Graph.createEdge(nodeEight, nodeFour);
	Graph.createEdge(nodeSeven, nodeNine);
	Graph.createEdge(nodeTen, nodeOne);
	Graph.createEdge(nodeFour, nodeSeven);
	
	std::shared_ptr<Node> testNode = Graph.findNode(1); 
	DFS(testNode); 
	return 0; 
}