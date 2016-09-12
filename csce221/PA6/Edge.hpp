#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>

class Edge {
public:
    // start vertex's label
    int start;
    // end vertex's label
    int end;
    // the weight of this edge
    int weight;
	//To see if the edge is visited or not
	bool visited;
    
    Edge(int start=0, int end=0, int weight=0, bool visited=0);
};

#endif /* Edge_hpp */
