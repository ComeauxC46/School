#ifndef Graph_hpp
#define Graph_hpp
#include <stdio.h>
#include <vector>
#include <fstream>
#include <stack>
#include "Vertex.hpp"

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<Vertex> vertices;
    Graph(int size = 0);
    // build a graph according to the input file
    void buildGraph(ifstream& ifs);
    // display the graph
    void displayGraph();
	//reverse the graph
	void reverseGraph(Graph& T);
	//Find index of label
	int findLabel(int Label);
	//get the order of/start DFS
	vector<int> getDFSOrder();
	//traverse Vertex to find next vertex to traverse
	void vertexTraversal(int index, vector<int>& visited, vector<int>& order, stack<int>& vertex);
	//Make the strongly connected graph from transpose
	void makeSCG(Graph graph, vector<int> order); 
};

#endif /* Graph_hpp */



