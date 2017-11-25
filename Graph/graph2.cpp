#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 6

// data structure to store graph edges
struct Edge {
	int src, dest, weight;
};

// class to represent a graph object
class Graph
{
	public:
	// A array of vectors to represent adjacency list
	vector<pair<int, int>> adjList[N];

	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the undirected graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			int weight = edges[i].weight;
			
			// insert at end
			adjList[src].push_back(make_pair(dest, weight));
			
			// Uncomment below line for undirected graph
			// adjList[dest].push_back(make_pair(src, weight));
		}
	}
};

// print adjacency list representation of graph
void printGraph(Graph const& graph)
{
	for (int i = 0; i < N; i++) 
	{
		// print all neighboring vertices of given vertex 
		for (pair<int, int> v : graph.adjList[i])
			cout << "(" << i << ", " << v.first << 
					", " << v.second << ") ";
		cout << endl;
	}
}

// main function
int main()
{
	// vector of graph edges as per above diagram. Please 
	// note that initialization vector in below format will
	// work fine in C++11 and C++14 but will fail in C++98.
	vector<Edge> edges = 
	{
		// (x, y, w) -> edge from x to y having weight w
		{ 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 }, 
		{ 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
	};

	// construct graph
	Graph graph(edges);

	// print adjacency list representation of graph
	printGraph(graph);

	return 0;
}
