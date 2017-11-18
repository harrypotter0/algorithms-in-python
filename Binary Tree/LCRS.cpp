//Convert Binary Tree into Left Child Right Sibling Tree
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

// Function to perform preorder traversal of the binary tree
void preorder(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
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

// Function to convert a normal binary tree to Left-child
// right-sibling (LC-RS) binary tree
void convert(Node *root)
{
    // base case: empty tree
	if (root == nullptr)
		return;

    // recursively convert left and right subtree first
	convert(root->left);
	convert(root->right);

	// if left child is empty, then make right child as left's
	// and set right to null
	if (root->left == nullptr)
	{
	   root->left = root->right;
	   root->right = nullptr;
	}

	// if left child already exists, then make right child of the
	// left child to point to right child of current node and
	// set current right child as null
	else
	{
		root->left->right = root->right;
		root->right = nullptr;
	}
}

// main function
int main()
{
	Node* root = nullptr;

	/* Construct below Tree
	          1     
	        /  \    
	       /    \   
	      2      3  
	     / \    /  
	    4   5  6  
	          / \ 
	         7   8
	*/
	vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5},
		{"RL", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	convert(root);
	
	preorder(root);

	return 0;
}
