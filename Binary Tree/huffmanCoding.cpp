//Huffman Coding (Data compression Algorithm)
#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node 
{
	char ch;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;
	
	return node;
}

// Comparison object to be used to order the heap
struct comp 
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency 
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes 
// in a map.
void encode(Node* root, string str, 
				unordered_map<char, string> &huffmanCode)
{
	if (root == NULL)
		return;
	
	// found a leaf node
	if (!root->left && !root->right)
		huffmanCode[root->ch] = str;

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string 
void decode(Node* root, int &index, string str)
{
	if (root == NULL)
		return;
	
	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}
	index++;
	
	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// Builds Huffman Tree and huffmanCode and decode
// given input text
void buildHuffmanTree(string text)
{
	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	for (char ch: text)
		freq[ch]++;

	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;
	
	// Create a leaf node for each character and add it 
	// to the priority queue.
	for (auto it : freq) 
		pq.push(getNode(it.first, it.second, NULL, NULL));

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority 
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();
		
		// Create a new internal node with these two nodes 
		// as children and with frequency equal to the sum 
		// of the two nodes' frequencies. Add the new node 
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}
	
	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();
	
	// traverse the Huffman Tree and store Huffman Codes 
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << endl;
	for (auto it : huffmanCode)
		cout << it.first << " " << it.second << endl;
		
	cout << "\nOriginal string was :\n" << text << endl;
	
	// print encoded string
	string str = "";
	for (char ch: text)
		str += huffmanCode[ch];
	cout << "\nEncoded string is :\n" << str << endl;

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	int index = -1;
	cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 2)
		decode(root, index, str);
}

// main function
int main()
{
	string text = "Huffman coding is a data compression algorithm.";

	buildHuffmanTree(text);

	return 0;
}
