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

// Function to check if given node is a leaf node or not
bool isLeaf(Node* node)
{
    return (node->left == nullptr && node->right == nullptr);
}

// Recursive function to find paths from root node to every leaf node
void printRootToleafPaths(Node* node, vector<int> &path)
{
	// base case
	if (node == nullptr)
		return;

	// include current node to path vector
	path.push_back(node->data);

	// if leaf node is found, print the path
	if (isLeaf(node))
	{
		for (int data: path)
			cout << data << " ";
		cout << endl;
	}

	// recurse for left and right subtree
	printRootToleafPaths(node->left, path);
	printRootToleafPaths(node->right, path);

	// remove current node after left and right subtree are done
	path.pop_back();
}

// Main function to print paths from root node to every leaf node
void printRootToleafPaths(Node* node)
{
    // vector to store root to leaf path
    vector<int> path;

	printRootToleafPaths(node, path);
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
	 / \	 / \
	4   5   6   7
           /     \
          8       9
    */

    vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5},
		{"RL", 6}, {"RR", 7}, {"RLL", 8}, {"RRR", 9}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	// print all root to leaf paths
	printRootToleafPaths(root);

	return 0;
}