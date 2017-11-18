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

// Recursive function to do a pre-order traversal of the tree and
// fill the map with diagonal sum of elements
void diagonalSum(Node* root, int diagonal, auto &map)
{
	// base case: empty tree
	if (root == nullptr)
		return;

    // update the current diagonal with node's value
	map[diagonal] += root->data;

	// recurse for left subtree by increasing diagonal by 1
	diagonalSum(root->left, diagonal + 1, map);

	// recurse for right subtree with same diagonal
	diagonalSum(root->right, diagonal, map);
}

// Function to print the diagonal sum of given binary tree
void diagonalSum(Node* root)
{
	// create an empty map to store diagonal sum for every slope
	map<int, int> map;

	// do pre-order traversal of the tree and fill the map
	diagonalSum(root, 0, map);

	// traverse the map and print diagonal sum
	for (auto it: map)
		cout << it.second << " ";
}

// main function
int main()
{
	Node* root = nullptr;

    /* Construct below tree
          1
        /   \
       /     \
      2       3
     /      /  \
    /      /    \
   4      5      6
         / \
        /   \
       7     8
    */

	vector<pair<string, int> > keys =
	{
		 {"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"RL", 5}, 
		 {"RR", 6}, {"RLL", 7}, {"RLR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	diagonalSum(root);

	return 0;
}
