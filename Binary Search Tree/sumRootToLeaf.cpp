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

// Function to print root-to-leaf path having given sum in a binary tree
bool printPath (Node *root, int sum)
{
    // base case
	if (sum == 0)
		return true;

    // base case
	if (root == nullptr)
		return false;

    // recurse for left and right subtree with reduced sum
	bool left = printPath(root->left, sum - root->data);
	bool right = printPath(root->right, sum - root->data);

	// print current node if it lies on path having given sum
	if (left || right)
		cout << root->data << " ";

	return left || right;
}

// Function to calculate maximum root-to-leaf sum in a binary tree
int rootToLeafSum(Node* root)
{
    // base case: tree is empty
	if (root == nullptr)
		return 0;

    // calculate maximum node-to-leaf sum for left child
	int left = rootToLeafSum(root->left);

	// calculate maximum node-to-leaf sum for right child
	int right = rootToLeafSum(root->right);

	// consider maximum sum child
	return (left > right ? left : right) + root->data;
}

// Function to print maximum sum root-to-leaf path in a given binary tree
void findMaxSumPath(Node *root)
{
	int sum = rootToLeafSum(root);
	cout << "Maximum sum is " << sum << endl;
	cout << "Maximum sum path is: ";

	printPath(root, sum);
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
    8   4   5   6
       /   / \   \
     10   7   9   5
    */

    vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LL", 8}, {"LR", 4},
		{"RL", 5}, {"RR", 6}, {"LRL", 10}, {"RLL", 7}, {"RLR", 9}, {"RRR", 5}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	findMaxSumPath(root);

	return 0;
}
