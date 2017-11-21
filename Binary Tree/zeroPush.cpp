//To sink root node having value 0 to the bottom of the tree
// The left and right subtree (if any) of root node are already sinked
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

// Function to perform in-order traversal of given binary tree
void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Function to sink root node having value 0 to the bottom of the tree
// The left and right subtree (if any) of root node are already sinked
void sink(Node *root)
{
    // base case: tree is empty
	if (root == nullptr)
		return;

    // if left subtree exists & left child has non-zero value
	if (root->left && root->left->data != 0)
	{
	    // swap data of current node with its left child
		swap(root->data, root->left->data);

		// recurse for left subtree
		sink(root->left);
	}

    // if right subtree exists & right child has non-zero value
	else if(root->right && root->right->data != 0)
	{
	    // swap data of current node with its right child
		swap(root->data, root->right->data);

		// recurse for right subtree
        sink(root->right);
	}
}

// Main function to sink nodes having zero value to the bottom
// of the binary tree
void sinkNodes(Node* &root)
{
    // base case: tree is empty
	if (root == nullptr)
		return;

    // fix left subtree and right subtree first
	sinkNodes(root->left);
	sinkNodes(root->right);

	// sink current node it has value 0
	if (root->data == 0)
		sink(root);
}

// main function
int main()
{
	/* Construct below tree
		  0
		/   \
	   /	 \
	  1       0
			/   \
		   /	 \
		  0	      2
		/   \
	   /	 \
	  3       4
	*/

	vector<pair<string, int>> keys =
	{
		{"", 0}, {"L", 1}, {"R", 0}, {"RL", 0}, {"RR", 2},
		{"RLL", 3}, {"RLR", 4}
	};

	Node* root = nullptr;
    for (auto pair: keys)
		insert(root, pair.first, pair.second);

	sinkNodes(root);

	inorder(root);

	return 0;
}
