#include <iostream> 

struct Node
{
	int data;
	struct Node* left = NULL;
	struct Node* right = NULL;

	Node(int data) {
		this->data = data;
	}

};

void insert(int data, Node*& root)
{
	if (root == NULL)
	{
		root = new Node(data); 
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

//NODE STRUCT IF PARENT POINTER NEEDED
//struct Node
//{
//	int data;
//	struct Node* left = nullptr;
//	struct Node* right = nullptr;
//	struct Node* parent = nullptr;

//	Node(int data) {
//		this->data = data;
//	}

//};

//INSERT FUNCTION IF PARENT POINTER NEEDED
//void insert(int data, Node*& root)
//{
//	Node* current = root;
//	Node* parent = nullptr;

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

void remove(int data, Node*& root)
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
			delete root;
			root = NULL;
		} 

		//if node to delete had 1 child
		else if ((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left == NULL))
		{
			if (root->right != NULL)
			{
				Node* temp = root->right; 
				delete root;
				root = temp;
			}
			if (root->left != NULL)
			{
				Node* temp = root->left;
				delete root;
				root = temp;
			}
		}

		//if node to delete has 2 children 
		else { 

			Node*curr = root->right; 

			while (curr->left != NULL)
			{
				curr = curr->left; 
			}

			root->data = curr->data; 

			remove(curr->data, root->right); 
		}
	}
}


void inOrderTraversal(Node*& root)
{
	if (root != NULL)
	{
		inOrderTraversal(root->left); 
		std::cout << root->data << std::endl; 
		inOrderTraversal(root->right); 
	}
}

int main()
{

	Node* root = NULL; 
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