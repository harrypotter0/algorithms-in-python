// Find ancestor of a given Binary Node
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

// Recursive function to print all ancestors of given node in a binary tree. The
// function returns true if node is found in subtree rooted at given root node
bool printAncestors(Node *root, int node)
{
    // base case
	if (root == nullptr)
		return false;

    // return true if given node is found
	if (root->data == node)
		return true;

    // search node in left subtree
	bool left = printAncestors(root->left, node);

    // search node in right subtree
	bool right = false;
	if (!left)
		right = printAncestors(root->right, node);

	// if given node is found in either left or right subtree,
	// current node is an ancestor of given node
	if (left || right)
		cout << root->data << " ";

    // return true if node is found
	return left || right;
}

// main function
int main()
{
	Node* root = nullptr;

	/* Construct below tree
		  1
		/   \
	   /	 \
	  2	      3
	   \	 / \
	    4   5   6
           / \
          7   8
    */

    vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4},
		{"RL", 5}, {"RR", 6}, {"RLL", 7}, {"RRR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    int node = 7;
	printAncestors(root, node);

	return 0;
}
