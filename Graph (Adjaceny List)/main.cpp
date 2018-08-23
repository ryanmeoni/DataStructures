#include <iostream> 
#include "Graph.h"
#include "Node.h"
#include <queue>

//Depth First Search 
void DFS(Node* root)
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

void BFS(Node* root)
{

	std::queue<Node*> queue;
	root->visited = true; 

	queue.push(root); 

	while (!queue.empty())
	{
		Node *curr = queue.front(); 
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

	Node *nodeOne = new Node(1);
	Node *nodeTwo = new Node(2);
	Node *nodeThree = new Node(3);
	Node *nodeFour = new Node(4);
	Node *nodeFive = new Node(5);
	Node *nodeSix = new Node(6);
	Node *nodeSeven = new Node(7);
	Node *nodeEight = new Node(8);
	Node *nodeNine = new Node(9);
	Node *nodeTen = new Node(10);

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
	
	Node *testNode = Graph.findNode(1); 
	BFS(testNode); 

	return 0; 
}