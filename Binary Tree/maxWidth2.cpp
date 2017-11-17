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

// Traverse the tree in pre-order fashion and store count of nodes 
// in each level
void preorder(Node *root, int level, auto &map)
{
    // base case: empty tree
	if (root == nullptr)
		return;

    // increment count of nodes in current level
    map[level]++;

    // recurse for left and right subtree by increasing level by 1
	preorder(root->left, level + 1, map);
	preorder(root->right, level + 1, map);
}

// Recursive function to find maximum width of the tree
void maxWidth(Node *root)
{
    // create an empty map to store count of nodes in each levels
	unordered_map<int, int> map;

	// traverse the tree and fill map
	preorder(root, 1, map);

    // stores maximum width
	int res = 0;

	// iterate through the map and update maximum width
	for (auto it: map)
		res = max(res, it.second);

    cout << "Maximum width is " << res;
}

// main function
int main()
{
	Node* root = nullptr;
	vector<pair<string, int> > keys =
	{
		{"", 15}, {"L", 10}, {"R", 20}, {"LL", 8},
		{"LR", 12}, {"RL", 16}, {"RR", 25}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	maxWidth(root);

	return 0;
}
