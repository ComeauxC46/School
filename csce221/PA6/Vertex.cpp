#include "Vertex.hpp"
#include <iostream>
using namespace std;

Vertex:: Vertex(int label)
				: label(label){}

void Vertex::connectTo(int end)
{
	Edge* newEdge = new Edge(this->label, end, 0,0);
	this->edgeList.push_back(*newEdge);
}

void Vertex:: reverseEdge(int& s, int& e)
{
	list<Edge>::iterator it = this->edgeList.begin();
	while(it!=this->edgeList.end())
	{
		if(it->visited == 0)
		{
			s = it->end;
			e = it->start;
			it->visited=1;
			return;
		}
		it++;
	}
}

//see if the vertex is visited or not
bool isVisited(const vector<int>& visited, int label)
{
	for(int i=0; i<visited.size(); i++)
	{
		if(label == visited[i])
			return true;
	}
	return false;
}

bool isVertex(int label, vector<Vertex> vertices)
{
	for(int c=0; c<vertices.size(); c++)
	{
		if(label == vertices[c].label)
			return true;
	}
	return false;
}

//checks for either self loops or loops between 2 strongly connected components
bool isLoop(int start, int end, vector<Vertex> vertices)
{
	
	for(int i=0; i<vertices.size(); i++)
	{
		list<Edge>::iterator it = vertices[i].edgeList.begin();
		while(it != vertices[i].edgeList.end())
		{
			if(it->start == end && it->end == start || it->start == it->end) //loop found
				return true;
			it++;
		}
	}
	return false;
}
		
		
		