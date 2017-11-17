#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Search Tree node
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

// Recursive function to insert an key into BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node an return it
	if (root == nullptr)
		return newNode(key);

    // if given key is less than the root node, recuse for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);

    // if given key is more than the root node, recuse for right subtree
    else
		root->right = insert(root->right, key);

	return root;
}

// Function to perform inorder traversal of the given binary tree and
// check if it is a BST or not. Here prev is previous processed node
bool isBST(Node* root, Node* &prev)
{
    // base case: empty tree is a BST
	if (root == nullptr)
		return true;

    // check if left subtree is BST or not
	bool left = isBST(root->left, prev);

	// value of current node should be more than that of previous node
	if (root->data <= prev->data)
		return false;

    // update previous node and check if right subtree is BST or not
	prev = root;
	return left && isBST(root->right, prev);
}

// Function to determine if given Binary Tree is a BST or not
void isBST(Node* node)
{
    // pointer to store previous processed node in inorder traversal
	Node* prev = newNode(INT_MIN);

	// check if nodes are nodes are processed in sorted order
	if (isBST(node, prev))
        printf("This is a BST.");
    else
        printf("This is NOT a BST!");
}

// main function
int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// swap nodes
	swap(root->left, root->right);
	isBST(root);

	return 0;
}
