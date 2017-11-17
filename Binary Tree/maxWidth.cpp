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

// Function to find maximum width of the tree using level order
// traversal of given binary tree
void maxWidth(Node* root)
{
    // return if tree is empty
	if (root == nullptr)
		return;

    // create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

    // pointer to store current node
	Node* curr = nullptr;

	// stores maximum width
	int max = 0;

    // run till queue is not empty
	while (!queue.empty())
	{
		// calculate number of nodes in current level
		// This is equal to width of current level
		int width = queue.size();

        // update maximum width if number of nodes in current level
        // is more than maximum width found so far
		if (max < width)
			max = width;

		// process every node of current level and enqueue their
		// non-empty left and right child to queue
		while (width--)
		{
			curr = queue.front();
			queue.pop_front();

			if (curr->left)
				queue.push_back(curr->left);

			if (curr->right)
				queue.push_back(curr->right);
		}
	}

	cout << "Maximum width is " << max;
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
