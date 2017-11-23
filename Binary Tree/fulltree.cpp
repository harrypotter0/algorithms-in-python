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

// Function to perform inorder traversal of the tree
void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Function to check if given node is a leaf node or not
bool isLeaf(Node* node)
{
	return (node->left == nullptr && node->right == nullptr);
}

// Function to convert a binary tree to full tree by removing half nodes
// i.e. remove nodes having one children
Node* truncate(Node* root)
{
    // base case: empty tree
	if (root == nullptr)
		return nullptr;

    // recursively truncate the left subtree and subtree first
	root->left = truncate(root->left);
	root->right = truncate(root->right);

	// if current node has two children or it is leaf node,
	// nothing needs to be done
    if ((root->left && root->right) || isLeaf(root))
		return root;

    // if current node has exactly one child, then delete it and replace
    // the node by the child node
    Node* child = (root->left) ? root->left: root->right;
    delete root;
    return child;
}

// main function
int main()
{
	Node* root = nullptr;

	/* Construct below tree
				 0
			   /   \
			  /	    \
			 1	     2
			/	    /
		   /	   /
		  3	      4
		 /	     / \
		/	    /   \
	   5	   6	 7
	*/

	vector<pair<string, int>> keys =
	{
		{"", 0}, {"L", 1}, {"R", 2}, {"LL", 3}, {"RL", 4},
		{"LLL", 5}, {"RLL", 6}, {"RLR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	truncate(root);
	inorder(root);

	return 0;
}
