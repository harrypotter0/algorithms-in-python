//find the distance between node 'x' and node 'y' in a
// given binary tree rooted at 'root' node
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

// Helper function to check if given node is present in binary tree or not
bool isNodePresent(Node* root, Node* node)
{
    // base case
	if (root == nullptr)
		return false;

    // if node is found, return true
	if (root == node)
		return true;

    // return true if node is found in the left subtree or right subtree
	return isNodePresent(root->left, node) ||
            isNodePresent(root->right, node);
}

// Helper function to find level of given node present in binary tree
int findLevel(Node *root, Node* node, int level)
{
    // base case
	if (root == nullptr)
		return INT_MIN;

    // return level if node is found
	if (root == node)
		return level;

    // search node in left subtree
	int left = findLevel(root->left, node, level + 1);

    // if node is found in left subtree, return
	if (left != INT_MIN)
		return left;

    // else continue the search in right subtree
	return findLevel(root->right, node, level + 1);
}

// Function to find lowest common ancestor of given nodes x and y where
// both x and y are present in the binary tree.
Node* findLCA(Node* root, Node* x, Node* y)
{
    // base case 1: if tree is empty
	if (root == nullptr)
		return nullptr;

    // base case 2: if either x or y is found
	if (root == x || root == y)
		return root;

    // recursively check if x or y exists in the left subtree
    Node* left = findLCA(root->left, x, y);

	// recursively check if x or y exists in the right subtree
    Node* right = findLCA(root->right, x, y);

    // if x is found in one subtree and y is found in other subtree,
    // update lca to current node
    if (left && right)
   		return root;

    // if x and y exists in left subtree
    if (left)
		return left;

    // if x and y exists in right subtree
    if (right)
		return right;
}

// Function to find the distance between node 'x' and node 'y' in a
// given binary tree rooted at 'root' node
int findDistance(Node *root, Node* x, Node* y)
{
    // lca stores lowest common ancestor of x and y
    Node *lca = nullptr;

	// call LCA procedure only if both x and y are present in the tree
	if (isNodePresent(root, y) && isNodePresent(root, x))
        lca = findLCA(root, x, y);
    else
        return INT_MIN;

    // return distance of x from lca + distance of y from lca
    return findLevel(lca, x, 0) + findLevel(lca, y, 0);

    // above return statement is equivalent to
    // findLevel(root, x, 0) + findLevel(root, y, 0) - 2*findLevel(root, lca, 0)

    // we can avoid calling isNodePresent() function by using return values of
    // findLevel() function to check if x and y are present in the tree or not
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
	   \	 / \
	    4   5   6
           / \
          7   8
    */

    vector<pair<string, int>> keys =
	{
		{"", 1}, {"L", 2}, {"R", 3}, {"LR", 4},
		{"RL", 5}, {"RR", 6}, {"RLL", 7}, {"RRR", 8}
	};

	for (auto pair: keys)
		insert(root, pair.first, pair.second);

    // find distance between node 7 and node 6
	cout << findDistance(root, root->right->left->left, root->right->right);

	return 0;
}
