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

// Helper function to find maximum difference between a node and its
// descendants in a binary tree
int maxDifference(Node* root, int &diff)
{
    // base case: if tree is empty, return infinity
	if (root == nullptr)
		return INT_MAX;

    // recurse for left and right subtree
	int left = maxDifference(root->left, diff);
	int right = maxDifference(root->right, diff);

	// find maximum difference between current node and its descendants
	int d = root->data - min(left, right);

	// update the maximum difference found so far if required
	diff = max(diff, d);

	// in order for difference to be maximum, the function should return
	// minimum value among all nodes in sub-tree rooted at it
	return min(min(left, right), root->data);
}

// Find maximum difference between a node and its descendants in a binary tree
int maxDifference(Node *root)
{
	int diff = INT_MIN;
	maxDifference(root, diff);

	return diff;
}

// main function
int main()
{
	Node* root = nullptr;
	/* Construct below tree
		  6
		/   \
	   /	 \
	  3       8
			/   \
		   /	 \
		  2	      4
		/   \
	   /	 \
	  1       7
	*/

	vector<pair<string, int>> keys =
	{
		{"", 6}, {"L", 3}, {"R", 8}, {"RL", 2}, {"RR", 4},
		{"RLL", 1}, {"RLR", 7}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	cout << maxDifference(root);

	return 0;
}
