// Print Right view of given binary tree
#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
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

// Recursive function to print right view of given binary tree
void rightView(Node *root, int level, int &last_level)
{
    // base case: empty tree
	if (root == nullptr)
		return;

    // if current node is last node of current level
	if (last_level < level)
	{
	    // print the node's data
		cout << root->key << " ";

		// update last level to current level
		last_level = level;
	}

    // recurse for right and left subtree by increasing level by 1
	rightView(root->right, level + 1, last_level);
	rightView(root->left, level + 1, last_level);
}

// Function to print right view of given binary tree
void rightView(Node *root)
{
	int last_level = 0;
	rightView(root, 1, last_level);
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4}, {"RL", 5},
		{"RR", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	rightView(root);

	return 0;
}
