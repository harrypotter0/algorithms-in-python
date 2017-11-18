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
// fill the map with diagonal elements
void printDiagonal(Node *node, int diagonal, auto &map)
{
	// base case: empty tree
	if (node == nullptr)
		return;

    // insert current node in current diagonal
	map.insert(make_pair(diagonal, node->data));

	// recurse for left subtree by increasing diagonal by 1
    printDiagonal(node->left, diagonal + 1, map);

	// recurse for right subtree with same diagonal
	printDiagonal(node->right, diagonal, map);
}

// Function to print the diagonal elements of given binary tree
void printDiagonal(Node *root)
{
	// create an empty map to store diagonal element in every slope
	// we can also use map<int, vector<int>> instead of multimap<int, int>
	multimap<int, int> map;


    // do pre-order traversal of the tree and fill the map
	printDiagonal(root, 0, map);

	// traverse the map and print diagonal elements
   	int temp = 0;
 	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (temp != it->first)
   		{
   			cout << endl;
   			temp = it->first;
   		}
		cout << it->second << " ";
 	}
}

// main function
int main()
{
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

	Node* root = nullptr;

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	printDiagonal(root);

	return 0;
}
