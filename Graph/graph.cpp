#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 6

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
	public:
	// A array of vectors to represent adjacency list
	vector<int> adjList[N];

	// Constructor
	Graph(vector<Edge> edges)
	{
		// add edges to the undirected graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			// insert at end
			adjList[src].push_back(dest);

			// Uncomment below line for undirected graph
			// adjList[dest].push_back(src);
		}
	}
};

// print adjacency list representation of graph
void printGraph(Graph const& graph)
{
	for (int i = 0; i < N; i++)
	{
		// print current vertex number
		cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : graph.adjList[i])
			cout << v << " ";
		cout << endl;
	}
}

// main function
int main()
{
	// work fine in C++11 and C++14 but will fail in C++98.
	vector<Edge> edges =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// construct graph
	Graph graph(edges);

	// print adjacency list representation of graph
	printGraph(graph);

	return 0;
}
