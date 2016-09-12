#include "TemplateDoublyLinkedList.h"
#include <fstream>
#include <vector>
#include <exception>
#include "Record.h"

using namespace std;

//prototypes
void fill(vector<DoublyLinkedList<Record>>&);
void show(const vector<DoublyLinkedList<Record>>&);
void interface(vector<DoublyLinkedList<Record>>&);
vector<Record> search(vector<DoublyLinkedList<Record>>&, string); //searched the vector based on input 


int main()
{
	//create a vector of 26 boubly linked list of Records
	vector<DoublyLinkedList<Record>> book(26);
	
	try
	{
		//Fill the vector from file
		fill(book);
	}
	catch(int)
	{
		cerr<< "The file did not open correctly"<<endl;
	}
	
	//print the vector
	show(book);
	
	//user interaction
	interface(book);

return 0;
}


void fill(vector<DoublyLinkedList<Record>>& book)
{
	string title, author, ISBN, year, edition, space;
	ifstream ifs;
	ifs.open("Book.txt");
	if(!ifs)
		throw 1;
	
	while (getline(ifs,title) && getline(ifs,author) && getline(ifs,ISBN) && getline(ifs,year) 
		   && getline(ifs,edition) && (getline(ifs,space) || ifs.eof()))
	{
		Record* r = new Record(title, author, ISBN, year, edition);
		//insert based on fist letter of title and sort in list
		//Ex. A = 65. so 65-65 = 0. Enter into 'A' vector
		book[title[0]-'A'].insertOrderly(*r);
	}
	
	ifs.close();
}

void show(const vector<DoublyLinkedList<Record>>& book)
{
	for(int i=0; i<26; i++)
		if(!book[i].isEmpty())
			cout<<book[i];
}

void interface(vector<DoublyLinkedList<Record>>& book)
{
	//local variables
	string name;
	string edition;
	
	Record newRecord;
	
	//formatting
	cout <<"----------------------------------------\n";
	cout <<"\t\tMenu\n\n" ;
	
	//prompt user
	cout <<"Please enter a book title(using the correct capitalization) to seach for or press 'enter' to inset a new book\n";
	getline(cin,name);
	cout<<endl; //formatting purposes
	
	//search the vector
	vector<Record> r = search(book, name);
	
	if(r.size() == 0)
	{
		//prompt the user
		cout <<"A book with that title was not found in the list.\n\n";
		cout <<"Plese provide the book information to be entered into the database\n";
		cout <<"in order of title, author’s name, 13-digit ISBN, publishing year, and edition\n";
		cout <<"and press 'Enter' after each.\n";
		cin >>newRecord;
		
		//insert into database
		book[newRecord.getTitle()[0]-'A'].insertOrderly(newRecord);
		cout <<"The book has been entered into the database.\n";
		
		try
		{
			//update book.txt
			ofstream ops;
			ops.open("Book.txt");
			if(!ops)
				throw 1;
			for(int i=0; i<26; i++)
				ops <<book[i];
			ops.close();
		}
		catch(int)
		{
			cerr<< "The file did not open correctly"<<endl;
		}
	}
	
	else if(r.size() > 1)
	{
		//Prompt user
		cout <<"There are more than one book with this title in the database:\n\n";
		for(int i=0; i<r.size(); i++)
			cout <<r[i]<<endl;
		cout <<"Enter the correct edition (as shown on the screen)\n";
		getline(cin, edition);
		cout <<"\nHere it is:\n\n";
		for(int i=0; i<r.size(); i++)
		{
			if(r[i].getEdition() == edition)
			{
				cout <<"\nHere it is:\n\n";
				cout <<r[i]<<endl;
			}
			else
			{
				cout <<"That edition is not in the database\n";
				break;
			}
		}
	}
	
	else
	{
		cout <<"The book was found in the database: \n\n";
			cout <<r[0]<<endl;
	}
	
}

vector<Record> search(vector<DoublyLinkedList<Record>>& book, string name)
{
	vector<Record> temp;
	//find which index to access
	int index = name[0] - 'A';
	//input validation
	if(index<0 || index>25)
		return temp;
		
	else if(book[index].isEmpty()) //if the linked list is empty return
		return temp;
	else //search
	{
		DListNode<Record>* node = book[index].getFirst(); //create a reference node
		while(node != book[index].getAfterLast())
		{
			if(name == node->getElem().getTitle())
				temp.push_back(node->getElem());
			node = node->getNext();
		}		
	}
	return temp;
}
	
