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

// Function to perform inorder traversal of the tree
void inorder(Node* root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
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

// Function to determine if given Binary Tree is a BST or not by keeping a
// valid range (starting from [MIN_VALUE, MAX_VALUE]) and keep shrinking
// it down for each node as we go down recursively
bool isBST(Node* node, int minKey, int maxKey)
{
    // base case
    if (node == NULL)
        return true;

    // if node's value fall outside valid range
    if (node->data < minKey || node->data > maxKey)
        return false;

    // recursively check left and right subtrees with updated range
    return isBST(node->left, minKey, node->data) &&
            isBST(node->right, node->data, maxKey);
}

// Function to determine if given Binary Tree is a BST or not
void isBST(Node* root)
{
	if(isBST(root, INT_MIN, INT_MAX))
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
