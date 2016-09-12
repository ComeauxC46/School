#include "Graph.hpp"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

Graph::Graph(int size)
{
	this->vertices.resize(size);
}

void Graph::buildGraph(ifstream& ifs)
{
	//Local Variables
	string name;
	string input;
	int line_count=0; //keeps track of which vertex is currently analyzed
		
	while(!ifs.eof())
	{
		getline(ifs, input);
		for(int i=0; i<input.size(); i++)
		{
			const char* c = &input[i];//used to convert char to int
			if(input[i] == ' ')
				continue;
			else if (atoi(c) == -1)
				break;
			else if(i == 0)//initilize the lable
				this->vertices[line_count].label = atoi(c); 
			else
				this->vertices[line_count].connectTo(atoi(c));
		}
		line_count++;
	}
	ifs.close();
}

void Graph::displayGraph()
{
	for(int i=0; i<this->vertices.size(); i++)
	{
		cout <<this->vertices[i].label <<":  ";
		for(list<Edge>::iterator it = this->vertices[i].edgeList.begin(); 
			it!=this->vertices[i].edgeList.end(); it++)
		{
			cout <<it->end <<" ";
		}
		cout <<"-1\n";
	}
}

void Graph::reverseGraph(Graph& T)
{
	int newStart, newEnd;
	//initilize graph
	for(int i=0; i<this->vertices.size(); i++)
		T.vertices.push_back(*(new Vertex(this->vertices[i].label)));
	for(int i=0; i<this->vertices.size(); i++)//controls which vertex
	{
		for (int s =0; s<this->vertices[i].edgeList.size(); s++) // controls edges
		{
			this->vertices[i].reverseEdge(newStart, newEnd);
			int c = T.findLabel(newStart);
			T.vertices[c].connectTo(newEnd);
		}
	}
}

int Graph::findLabel(int Label)
{
	int i = 0;
	for(i; i<this->vertices.size(); i++)
	{
		if (this->vertices[i].label == Label)
			break;
	}
	return i;
}

vector<int> Graph::getDFSOrder()
{
	vector<int> visited;
	vector<int> order;
	stack<int> vertex;
	
	//initilize DFS
	int first = this->findLabel(this->vertices[0].label);
	visited.push_back(this->vertices[0].label);
	vertex.push(this->vertices[0].label);
	this->vertexTraversal(first, visited, order, vertex);
	return order;
}

void Graph::vertexTraversal(int index, vector<int>& visited, vector<int>& order, stack<int>& vertex)
{
	//create iterator to iterate through edgeList
	list<Edge>::iterator eit = this->vertices[index].edgeList.begin();
	while(eit != this->vertices[index].edgeList.end())
	{
		if(!isVisited(visited, eit->end))
		{
			visited.push_back(eit->end);
			vertex.push(eit->end);
		}
		eit++;
	}
	if(this->vertices[index].label != vertex.top())
		this->vertexTraversal(this->findLabel(vertex.top()), visited, order, vertex);
	else
	{
		order.push_back(vertex.top());
		vertex.pop();
		if(vertex.empty())
			return;
		else
			this->vertexTraversal(this->findLabel(vertex.top()), visited, order, vertex);
	}
}

void Graph::makeSCG(Graph graph, vector<int> order)
{
	vector<int> visited;
	stack<int> DFSOrder;
	stack<int> vertex;
	vector<vector<int>> scc;// hold the strongly connected components
	Graph output;
	//create a stack out of the order vector
	for(int i=0; i<order.size(); i++)
		DFSOrder.push(order[i]);
	
	for(int i = visited.size(),c=0; i!= this->vertices.size(); i = visited.size(),c++)
	{
		//initilize DFS
		int index = this->findLabel(DFSOrder.top());
		visited.push_back(DFSOrder.top());
		vertex.push(DFSOrder.top());
		DFSOrder.pop();
		scc.push_back(*(new vector<int>));
		this->vertexTraversal(index, visited, scc[c], vertex);
	}
	
	//Create output graph with origional graph verticies
	for(int i=0; i<scc.size(); i++)
	{
		if(scc[i].size() == 1)
		{
			int l = graph.findLabel(scc[i][0]);
			output.vertices.push_back(graph.vertices[l]);
		}
		else
		{
			int l = graph.findLabel(scc[i][(scc[i].size()-1)]);
			output.vertices.push_back(graph.vertices[l]);
		}
	}
	
	//update verticies list
	for(int i=0; i<output.vertices.size(); i++)
	{
		list<Edge>::iterator eit = output.vertices[i].edgeList.begin();
		while(eit != output.vertices[i].edgeList.end())
		{
			//If the end of the edge is still a vertex continue
			if(isVertex(eit->end, output.vertices))
				eit++;
			else// else delete the edge
				eit = output.vertices[i].edgeList.erase(eit);
		}
	}
	
	//Check for loops
	for(int i=0; i<output.vertices.size(); i++)
	{
		list<Edge>::iterator eit = output.vertices[i].edgeList.begin();
		while(eit != output.vertices[i].edgeList.end())
		{
			//Check for loops
			if(isLoop(eit-> start, eit->end, output.vertices))
				eit = output.vertices[i].edgeList.erase(eit);
			eit++;
		}
	}
	
	//output the DAG graph
	cout<<"\nACYCLIC GRAPH\n";
	output.displayGraph();
}	
		
		
		
		
		
		
		
		
		
