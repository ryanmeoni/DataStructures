#include <iostream> 
#include <memory>

struct Node
{
	int data;
	std::shared_ptr<Node> left; 
	std::shared_ptr<Node> right; 

	Node(int data) {
		this->data = data;
		this->left = NULL; 
		this->right = NULL; 
	}

};


void insert(int data, std::shared_ptr<Node>& root)
{
	if (root == NULL)
	{
		root = std::make_shared<Node>(data); 
	}
	else {
		if (root->data > data)
		{
			insert(data, root->left);
		}
		else {
			insert(data, root->right); 
		}
	}
}

void remove(int data, std::shared_ptr<Node>& root)
{
	

	if (root->data > data)
	{
		remove(data, root->left); 
	}

	else if (root->data < data)
	{
		remove(data, root->right); 
	}
	else { 

		//if node has zero children 
		if (root->right == NULL && root->left == NULL)
		{
			root = NULL;
		} 

		//if node to delete had 1 child
		else if ((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left == NULL))
		{
			if (root->right != NULL)
			{
				root = root->right; 
			}
			if (root->left != NULL)
			{
				root = root->left; 
			}
		}

		//if node to delete has 2 children 
		else { 

			std::shared_ptr<Node> curr = root->right; 

			while (curr->left != NULL)
			{
				curr = curr->left; 
			}

			root->data = curr->data; 

			remove(curr->data, root->right); 
		}
	}
}


void inOrderTraversal(std::shared_ptr<Node>& root)
{
	if (root != NULL)
	{
		inOrderTraversal(root->left); 
		std::cout << root->data << std::endl; 
		inOrderTraversal(root->right); 
	}
}

std::shared_ptr<Node> findNode(int data, std::shared_ptr<Node>& root)
{

	std::shared_ptr<Node> curr = root;

	if (curr == NULL)
	{
		std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
		return newNode;
	}

	while (curr != NULL)
	{
		if (curr->data == data)
		{
			return curr;
		}

		if (curr->data > data)
		{
			curr = curr->left;
		}
		else if (curr->data < data)
		{
			curr = curr->right;
		}
	}
}

int main()
{

	std::shared_ptr<Node> root = NULL; 
	insert(50, root); 
	insert(25, root); 
	insert(10, root); 
	insert(30, root); 
	insert(75, root); 
	insert(65, root); 
	insert(55, root); 
	insert(80, root); 
	insert(100, root); 
	inOrderTraversal(root); 
	remove(30, root); 
	inOrderTraversal(root); 
	return 0; 
}



//NODE STRUCT IF PARENT POINTER NEEDED
//struct Node
//{
//	int data;
//	std::shared_ptr<Node> left; 
//	std::shared_ptr<Node> right; 
//	std::shared_ptr<Node> parent; 

//	Node(int data) {
//		this->data = data;
//		this->left = NULL; 
//		this->right = NULL; 
//		this->parent = NULL; 
//	}

//};

//INSERT FUNCTION IF PARENT POINTER NEEDED
//void insert(int data, std::shared_ptr<Node>& root)
//{
//	std::shared_ptr<Node> current = root;
//	std::shared_ptr<Node> parent = nullptr;

//	while (current != nullptr) {

//		parent = current;
//		if (data > current->data) {

//			current = current->right;
//		}
//		else if (data < current->data) {

//			current = current->left;
//		}
//	}

//	current = new Node(data);

//	current->parent = parent;

//	if (parent == nullptr) {
//		root = current;
//	}
//	else if (current->data > parent->data) {
//		parent->right = current;
//	}
//	else if (current->data < parent->data) {
//		parent->left = current;
//	}
//}