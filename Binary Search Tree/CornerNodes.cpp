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

// Iterative function to print corner nodes of every level in binary tree
void print(Node *root)
{
    // return if tree is empty
	if (root == nullptr)
		return;

    // create an empty queue to store Tree nodes
	queue<Node*> q;

	// enqueue root node
	q.push(root);

	// run till queue is not empty
	while (!q.empty())
	{
	    // get size of current level
		int size = q.size();
		int n = size;

		// process all nodes present in current level
		while (n--)
		{
			Node *node = q.front();
			q.pop();

			// if corner node found, print it
			if (n == size - 1 || n == 0)
				cout << node->data << " ";

		    // enqueue left and right child of current node
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		// terminate level by printing newline
		cout << endl;
	}
}


// main function
int main()
{
    /* Construct below tree
             1
            / \
           /   \
          2     3
         /     / \
        /     /   \
       4     5     6
      /     / \     \
     /     /   \     \
    7     8     9     10
    */

	vector<pair<string, int>> keys =
	{
		 {"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"RL", 5},
		 {"RR", 6}, {"LLL", 7}, {"RLL", 8}, {"RLR", 9}, {"RRR", 10}
	};

    Node* root = nullptr;
	for (auto pair: keys)
		insert(root, pair.first, pair.second);

	print(root);

	return 0;
}
