#include <iostream>
#include<vector>
#include "Graph.hpp"


int main(int argc, const char * argv[]) 
{	try
	{
		//Local Varibles and Streams
		ifstream ifs;
		int size;
		string dummy; // dummy varible used to help count file size
		
		if (argc!=2)
			throw -1;
		else
		{
		// open file argv[1]
		ifs.open(argv[1]);
		if(!ifs) throw -1;
		} 
		
		//Aquire size of input data
		while(!ifs.eof())
		{
			getline(ifs, dummy);
			size++;
		}
		
		//reset the file stream
		ifs.clear();
		ifs.seekg(0, ios::beg);
		
		//Init Graph and output to screen
		Graph graph (size);
		graph.buildGraph(ifs);
		cout<<"GRAPH\n";
		graph.displayGraph();
		
		//Init transpose and output to screen
		Graph transpose;
		graph.reverseGraph(transpose);
		cout<<"\nTRANSPOSE GRAPH\n";
		transpose.displayGraph();
		
		//Run DFS on the origional, then ren it on the transpose and output the DAG
		vector<int> order = graph.getDFSOrder();
		transpose.makeSCG(graph, order);
		
	}
	catch(int)
	{
		cerr<<"File Error...\n"
		    <<"Either you did not provide a file or the file did not open correctly\n";
	}
return 0;
}
