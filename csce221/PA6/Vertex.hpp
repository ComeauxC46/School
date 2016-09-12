#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <list>
#include <string>
#include <vector>
#include "Edge.hpp"
using namespace std;

class Vertex {
public:
    // the label of this vertex
    int label;

    // using a linked-list to manage its edges which offers O(c) insertion
    list<Edge> edgeList;
    // init your vertex here
    Vertex(int label=0);
    // connect this vertex to a specific vertex (adding edge)
    void connectTo(int end);
	//reverse edge
	void reverseEdge(int& s, int& e);
};

#endif /* Vertex_hpp */
//see if the vertex is visited or not
bool isVisited(const vector<int>& visited, int label);
//Checks to see if there is a vetex with the integer label
bool isVertex(int label, vector<Vertex> vertices);
//checks for either self loops or loops between 2 strongly connected components
bool isLoop(int start, int end, vector<Vertex> vertices);