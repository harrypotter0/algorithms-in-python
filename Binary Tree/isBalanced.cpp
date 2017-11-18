// Check if given tree is Balanced or not 

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

// Recursive function to check if given binary tree is height balanced or not
int isHeightBalanced(Node* root, bool& isBalanced)
{
	// base case: tree is empty
    if (root == nullptr)
		return 0;

	// get height of left subtree
	int left_height = isHeightBalanced(root->left, isBalanced);

	// get height of right subtree
	int right_height = isHeightBalanced(root->right, isBalanced);

	// tree is unbalanced if absolute difference between height of
	// its left subtree and right subtree is more than 1
	if (abs(left_height - right_height) > 1)
		isBalanced = false;

	// return height of subtree rooted at current node
	return max(left_height, right_height) + 1;
}

// Main function to check if given binary tree is height balanced or not
bool isHeightBalanced(Node* root)
{
	bool isBalanced = true;
	isHeightBalanced(root, isBalanced);

	return isBalanced;
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
	 / \	 /
	4   5   6   */

    vector<pair<string, int> > keys =
	{
        {"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"LR", 5}, {"RL", 6}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	isHeightBalanced(root)? cout << "Yes": cout << "No";

	return 0;
}
