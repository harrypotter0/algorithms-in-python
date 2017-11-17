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

// Function to perform inorder traversal of the tree
void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Function to build the tree from given parent array
Node *createTree(int parent[], int n)
{
    // create an empty map
	unordered_map<int, Node*> map;

	// create n new tree nodes each having value from 0 to n-1
	// and store them in a map
	for (int i = 0; i < n; i++)
		map[i] = newNode(i);

    // represents root node of binary tree
	Node *root = nullptr;

	// traverse the parent array and build the tree
	for (int i = 0; i < n; i++)
	{
	    // if parent is -1, set root to current node having
	    // value i (stored in map[i])
		if (parent[i] == -1)
			root = map[i];
		else
		{
		    // get parent node for current node
			Node *ptr = map[parent[i]];

			// if parent's left child is filled, map the node to its right child
			if (ptr->left)
				ptr->right = map[i];

			// if parent's left child is empty, map the node to it
            else
				ptr->left = map[i];
		}
	}

	// return root of the constructed tree
	return root;
}

// main function
int main()
{
	int parent[] = {-1, 0, 0, 1, 2, 2, 4, 4};
	int n = sizeof parent / sizeof parent[0];

	Node *root = createTree(parent, n);

	inorder(root);

	return 0;
}
