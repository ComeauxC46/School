//MAIN.cpp
#include "BinarySearchTree.h"
#include <string>
#include <vector>
#include <limits>
using namespace std;

int main()
{
	//Variables used in program
	string file;
	int i = 1;
	vector<int> v;
	int input;
	int maxSize = 16;
	
	//Get file name from user
	while (i) //keep looping until file opens correctly
	{
		try
		{
			cout << "Please enter the name of the file you would like open.\n";
			cin >> file;
			
			//open the file
			ifstream ifs;
			ifs.open(file);
			i=0; //Input validation loop controller
			
			if(!ifs)
				throw -1;
			
			//Fill vector with data from file and output initial data
			cout <<"Input data:\n";
			while(!ifs.eof() && ifs >> input)
			{
				v.push_back(input);
				cout<< input <<endl;
			}
			ifs.close();
		}
		catch (int)
			{
				i = 1;
				cerr << "The file did not open correctly, please try again.\n"; 
			}
	}
	
	//Create a tree and fill it with data
	cout <<"Create Tree: \n";
	BSTree tree;
	tree.initilize_root(v[0]); // initilize root with the first number of file
	for(int i = 1; i < v.size(); i++)
		tree.insert_node(v[i], tree.getRoot());
	try
	{
		//Print the Tree and Size
		if(tree.getSize() <= maxSize)
		{
			cout <<tree;
			cout <<"Total number of nodes is " <<tree.getSize() <<endl;
		}
		else 
		{
			ofstream ost;
			ost.open("output.txt");
			if(!ost)
				throw 1;
			
			cout <<"The tree is located in the file output.txt\n\n";
			ost<<tree;
			ost.close();
		}
				
		//Preorder Traversal
		cout <<"PreOrder: \n";
		if(tree.getSize()>=maxSize)
		{
			ofstream ofs;
			ofs.open("preOrder_output.txt");
			if(!ofs)
				throw 1;
			cout <<"Please refer to the file preOrder_output.txt in the directory.\n";
			tree.preOrder(tree.getRoot(), ofs);
			ofs.close();
		}
		else
			tree.preOrder(tree.getRoot(), cout);
		
		//Inorder Traversal
		cout <<endl <<"InOrder: \n";
		if(tree.getSize()>=maxSize)
		{
			ofstream ofs;
			ofs.open("inOrder_output.txt");
			if(!ofs)
				throw 1;
			cout <<"Please refer to the file inOrder_output.txt in the directory.\n";
			tree.inOrder(tree.getRoot(),ofs);
			ofs.close();
		}
		else
			tree.inOrder(tree.getRoot(),cout);
			
		//Postorder Traversal
		cout <<endl <<"PostOrder: \n";
		if(tree.getSize()>=maxSize)
		{
			ofstream ofs;
			ofs.open("postOrder_output.txt");
			if(!ofs)
				throw 1;
			cout <<"Please refer to the file postOrder_output.txt in the directory.\n";
			tree.postOrder(tree.getRoot(), ofs);
			ofs.close();
		}
		else
			tree.postOrder(tree.getRoot(), cout);
	}
	catch (int)
	{
		cerr <<"The file could not be opened\n";
	}
	
	//Print the average search cost
	cout <<"\n\nThe average search cost is: " <<tree.aveSC() <<endl<<endl;
	
	//Print Tree By Level if Under Max Size
	cout <<"Tree by Levels: \n";
	if(tree.getSize() <= maxSize)
		tree.print_by_level();
	else
		cout <<"The file is to large to print by levels.\n\n";
	
	i=1; //reset loop controller
	while(i) //keep getting input until user inputs a valid number in tree
	{
		try
		{
			//Ask user to enter a node to delete
			int number = 0;
			cout <<"Please enter a number to delete from the tree.\n";
			cin >> number;
			while(std::cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout <<"That is not a valid entry. Try Again...\n";
				cin >> number;
			}

			//check to see if number entered is in the tree
			for(int c = 0; c<v.size(); c++)
			{ 
				if(number == v[c])
					break;
				else if(number != v[c] && c == v.size()-1)
					throw 'e';
			}
		
			//Remove the node
			tree.remove(number, tree.getRoot());
			i=0; //controls loop
			
			//Print the Tree and Size
			if(tree.getSize() <= maxSize)
			{
				tree.print_with_braces(tree.getRoot());
				cout <<"\nTotal number of nodes is " <<tree.getSize() <<endl;
			}
			else
			{
				ofstream ost;
				ost.open("removed.txt");
				if(!ost)
					throw -1;
				
				ost<<tree;
				ost.close();
				cout <<"The tree has been updated. Please refer to removed.txt\n";
			}
		}
		catch(char)
		{
			i=1;
			cerr <<"That is not in the tree. Please try again.\n\n";
		}
		catch(int)
		{
			cerr <<"The file did not open correctly\n";
		}
	}	
return 0;
}