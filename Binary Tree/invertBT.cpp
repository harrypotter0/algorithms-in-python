// Invert Binary Tree 
#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

// Function to insert given key into the tree
void insert(Node*& root, string level, int key)
{
	// tree is empty
	if (level.length() == 0)
	{
		root = newNode(key);
		return;
	}

	int i = 0;
	Node* ptr = root;
	while (i < level.length() - 1)
	{
		if (level[i++] == 'L')
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	if (level[i] == 'L')
		ptr->left = newNode(key);
	else
		ptr->right = newNode(key);
}

// Function to perform preorder traversal of the binary tree
void preorder(Node* root)
{
	if (root == nullptr)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

// Iterative Function to invert given binary Tree using stack
void invertBinaryTree(Node* root) 
{
	// base case: if tree is empty
	if (root == nullptr) 
		return;

	// create an empty stack and push root node
	stack<Node*> s;
	s.push(root);

	// run till stack is not empty
	while (!s.empty())
	{
		// pop top node from stack
		Node* curr = s.top();
		s.pop();

		// swap left child with right child
		swap(curr->left, curr->right);

		// push right child of popped node to the stack
		if (curr->right)
			s.push(curr->right);

		// push left child of popped node to the stack
		if (curr->left)
			s.push(curr->left);
	}
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
		  1
		/   \
	   /	 \
	  2		  3
	 / \	 / \
	4   5   6   7   */
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5}, {"RL", 6}, {"RR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	invertBinaryTree(root);
	preorder(root);

	return 0;
}
