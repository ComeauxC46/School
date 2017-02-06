/*
    File        : Book.cpp

    Author      : 
	
    Date        : 2017/02/01
	
	Description : Implementation of the Book and Class structures

*/

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "Book.h"

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES IMPLEMENTATION */ 
/*--------------------------------------------------------------------------*/

map<ISBN, Book*>               DataBase;               //Associates an ISBN with a Book
map<Department, vector<ISBN> > booksInDepartment;      //All books in a specific department
map<ClassKey, Class*>          classDataBase;          //All books in a specific department

vector<ClassKey>               listOfClasses;          //Holds a list of all classes defined
vector<Department>             listOfDeparments;       //Holds a list of all deparments defined
vector<ISBN>                   listOfISBN;             //Holds a list of all ISBN defined


/*--------------------------------------------------------------------------*/
/* CLASS IMPLEMNTATION */
/*--------------------------------------------------------------------------*/

Class::Class()
{
	
	code  = "";
	courseNum   = "";
	courseName  = "";  
	
	booksInSection = map<Section, vector<pair<ISBN,string> > >(); //Initilize with empty map 
}


Class::Class(string Code, string Num, string Name)
{
	key = make_pair(Code, Num);
	
	code = Code;
	courseNum  = Num;
	courseName = Name;
	
	booksInSection = map<Section, vector<pair<ISBN,string> > >(); //Initilize with empty map
}

void Class::printKnownInfo()
{
	cout << endl; //add space between command line and courseName
	
	cout << "Class: " << setw(3) << " " << this->code << " " << this->courseNum <<endl;
	cout << "Name:  " << setw(3) << " " << this->courseName <<endl;
	
	if(!this->sec.empty())
	{
		cout << "Sections: ";
		for(int i = 0; i < this->sec.size(); i++)
		{
			cout << this->sec[i] << " ";
			
		}
		cout <<endl;
	}
}


/*--------------------------------------------------------------------------*/
/*CLASS FRIEND FUNCTIONs IMPLEMENTATION */
/*--------------------------------------------------------------------------*/

void C(vector<string> input)
{
	Department code = input[1];
	string courseNum = input[2];
	
	/*Validate user input*/
	if(input.size() < 4)
	{
		cout << "\n ERROR...\n Define failed. Not enough inputs.\n";
		return;
	}
		
	else if (find(listOfClasses.begin(), listOfClasses.end(), make_pair(input[1], input[2])) != listOfClasses.end())
	{
		cout << "\n Error...\n This class is already defined\n";
		return;
	}
	
	/*Reconstruct name since it was broken up by parser*/
	string name = "";
	for(int i=3; i < input.size(); i++)
	{
		if(i == input.size() - 1) //if last token of the name, dont add a space
			name += input[i];
		else
			name += (input[i] + " ");
	}
	
	/*Add new department*/
	if (find(listOfDeparments.begin(), listOfDeparments.end(), input[1]) == listOfDeparments.end())
	{
		listOfDeparments.push_back(code);
	}
	
	/*Creat new class and update lists*/
	Class* newClass = new Class(code, courseNum, name);
	classDataBase[newClass->key] = newClass;
	listOfClasses.push_back(newClass->key);
}

void A(vector<string> input)
{
	ISBN isbn = input[1];
	Department code = input[2];
	string courseNum = input[3];
	Section s = input[4];
	string ro = input[5]; //REQ/OPT
	
	/*Input Validation*/
	Class* updateClass = findClass(make_pair(code,courseNum));
	Book* updateBook = findBook(isbn);
	if(updateClass == NULL)
	{
		cout << "Error...class not registered\n";
		return;
	}
	if(updateBook == NULL)
	{
		cout << "Error... book not in database\n";
		return;
	}
	if(input.size() < 6)
	{
		cout << "\n ERROR...\n Update failed. Not enough inputs.\n";
		return;
	}
	else if (find(listOfClasses.begin(), listOfClasses.end(), updateClass->key) == listOfClasses.end())
	{
		cout << "\n ERROR...\n Update failed. This class has not been defined yet\n";
		return;
	}
	
	/*Add new section if not already added*/
	if (find(updateClass->sec.begin(), updateClass->sec.end(), s) == updateClass->sec.end())
	{
		updateClass->sec.push_back(s);
	}
	
	/* This associates a class with a section with a ISBN with a book requirement
	   for that section. It takes a section of the specified class and adds the 
	   ISBN and requirement pair to a vector which holds all books required for 
	   that Class section.*/
	updateClass->booksInSection[s].push_back(make_pair(isbn,ro));
	
	/*Link the book to a class (opposite of above operation)*/
	/*Only add if ClassKey has not already been added to list*/
	if (find(updateBook->courses.begin(), updateBook->courses.end(), updateClass->key) == updateBook->courses.end())
	{
		updateBook->courses.push_back(make_pair(code,courseNum));
	}
	
	/*Link Book to a Deparment only once*/
	if (find(booksInDepartment[code].begin(), booksInDepartment[code].end(), isbn) == booksInDepartment[code].end())
	{
		booksInDepartment[code].push_back(isbn);
	}
	
}

void GC(vector<string> input)
{
	Department code = input[1];
	string courseNum = input[2];

	Class* pClass = findClass(make_pair(input[1],input[2]));
	if(pClass == NULL)
	{
		cout << "Error... class is not registered\n";
		return;
	}
	
	/*For every section, find every book assigned to that section
	  and print known information about every book*/
	Section currentSec;
	ISBN currentISBN;
	for(int i = 0; i < pClass->sec.size(); i++)
	{
		cout << "\nSECTION: " << pClass->sec[i];
		currentSec = pClass->sec[i];
		for(int currentBook = 0;
			currentBook < pClass->booksInSection[currentSec].size();
			currentBook++)
		{
			currentISBN = pClass->booksInSection[currentSec][currentBook].first;
			findBook(currentISBN)->printKnownInfo();
			/*Print requirement for that section*/
			cout << "\nOPT/REQ: " 
				 << pClass->booksInSection[currentSec][currentBook].second 
				 <<endl;
		}
	}
}

void GS(vector<string> input)
{
	ClassKey currentClass = make_pair(input[1],input[2]);
	Section s = input[3];
	ISBN currentISBN;
	
	/*Input Validation*/
	Class* pClass = findClass(currentClass);
	if(pClass == NULL)
	{
		cout << "Error... class is not registered\n";
		return;
	}
	
	/*For every book in section, print all known information*/
	for(int currentBook = 0;
		currentBook < pClass->booksInSection[s].size();
		currentBook++)
	{
		currentISBN = pClass->booksInSection[s][currentBook].first;
		findBook(currentISBN)->printKnownInfo();
		//Print requirement for that section
		cout << "\nOPT/REQ: " 
			 << pClass->booksInSection[s][currentBook].second 
			 <<endl;
	}
	
}

void PC()
{
	/*Find and print all information if every class*/
	for(int i = 0; i < listOfClasses.size(); i++)
	{
		findClass(listOfClasses[i])->printKnownInfo();
	}
}
	

/*--------------------------------------------------------------------------*/
/* BOOK IMPLEMENTATION */
/*--------------------------------------------------------------------------*/

Book::Book()
{
	isbn    = " ";
	title   = " ";
	author  = " ";
	edition = " ";
	date    = " ";
	
}


Book::Book(string i, string t)
{
	isbn    = i;
	title   = t;
	author  = " ";
	edition = " ";
	date    = " ";
	
}

void Book::printKnownInfo()
{
	bool printed = false;
	
	cout << endl << endl; //add space between command line and book print
	
	if(!(this->courses.empty()))
	{
		cout << "Class:" << setw(2) << " ";
		for(int i = 0; i < this->courses.size(); i++)
		{
			cout << this->courses[i].first << " " 
			     << this->courses[i].second << " ";
		}
		cout << endl;
	}
	cout << "Name:" << setw(3) << " " <<this->title <<endl;
	cout << "ISBN:" << setw(3) << " " <<this->isbn <<endl;
	if(this->author != " ")
	{
		cout << "Author: " << this->author << endl;
	}
	if(this->edition != " ")
	{
		cout << "Edition:" << setw(3) << " " << this->edition << endl;
	}
	if(this->date != " ")
	{
		cout << "Publication Date:" << setw(3) << " " << this->date << endl;
	}
	for(int i=0; i < this->cost.size(); i++)
	{
		if(this->cost[i] != 0)
		{
			/*Only print 'Cost:' once*/
			if(!printed)
			{
				cout << "Cost:" << setw(3) << " ";
				printed = true;
			}
			
			cout << fixed;
			
			/*Only print if cost initilized*/
			if(i == 0)
			{
				cout << setprecision(2) << "$" << this->cost[i] << " New ";
			}
			
			else if (i == 1)
			{
				cout << setprecision(2) << "$" << this->cost[i] << " Used ";
			}
			
			else if (i == 2)
			{
				cout << setprecision(2) << "$" << this->cost[i] << " Rented ";
			}
			else if (i == 3)
			{
				cout << setprecision(2) << "$" << this->cost[i] << " Electronic ";
			}
			
		}
	}
}
	

/*--------------------------------------------------------------------------*/
/*BOOK FRIEND FUNCTIONs IMPLEMENTATION */
/*--------------------------------------------------------------------------*/

void B(vector<string> input)
{
	ISBN isbn = input[1];
	
	/*Input Validation*/
	if(input.size() < 3)
	{
		cout << "\n ERROR...\n Define failed. Not enough inputs.\n";
		return;
	}
	else if (find(listOfISBN.begin(), listOfISBN.end(), isbn) != listOfISBN.end())
	{
		cout << "\n Error...\n This book is already defined\n";
		return;
	}
	
	
	/*Reconstruct name since it was broken up by parser*/
	string name = "";
	for(int i=2; i < input.size(); i++)
	{
		if(i == input.size() - 1) //last token of the name, dont add a space
			name += input[i];
		else
			name += (input[i] + " ");
	}

	/*Create book and update lists*/
	Book* newBook = new Book(isbn, name);
	DataBase[isbn] = newBook;
	listOfISBN.push_back(isbn);
}



void D(vector<string> input)
{
	ISBN isbn = input[1];
	char type = input[2][0];
	string info = input[3];
	string name = "";
	
	/*Input Validation*/
	Book* updateBook = findBook(isbn);
	if(updateBook == NULL)
	{
		cout << "Error... book not in database\n";
		return;
	}
	if(input.size() < 4)
	{
		cout << "\n ERROR...\n Update failed. Not enough inputs.\n";
		return;
	}
	else if (find(listOfISBN.begin(), listOfISBN.end(), isbn) == listOfISBN.end())
	{
		cout << "\n ERROR...\n Update failed. " << isbn << " has not been defined yet\n";
		return;
	}
	
	/*Determine input information type*/
	switch(toupper(type))
	{
		case 'A':
		{
			/*Reconstruct author's name if it was broken up by parser*/
			for(int i=3; i < input.size(); i++)
			{
				if(i == input.size() - 1) //if last token of the name, dont add a space
					name += input[i];
				else
					name += (input[i] + " ");
			}
			break;
		}
		case 'E':
		{
			updateBook->edition = info;
			break;
		}
		case 'D':
		{
			updateBook->date = info;
			break;
		}
		default:
		{
			cout << "\n Error...\n Incorrect selection.\n";
			return;
		}
	}
}

void M(vector<string> input)
{
	ISBN isbn = input[1];
	if(input[2][0] == '$')   //Remove '$' if present
		input[2].erase(0,1);
	double amt = stod(input[2], NULL);
	char choice = input[3][0];
	
	Book* updateBook = findBook(isbn);
	if(updateBook == NULL)
	{
		cout << "Error... book not in database\n";
		return;
	}
	if(input.size() < 4)
	{
		cout << "\n ERROR...\n Update failed. Not enough inputs.\n";
		return;
	}
	else if (find(listOfISBN.begin(), listOfISBN.end(), isbn) == listOfISBN.end())
	{
		cout << "\n ERROR...\n Update failed. " << isbn << " has not been defined yet\n";
		return;
	}
		
	/*Determine input information type*/	
	switch(toupper(choice))
	{
		case 'N':
			updateBook->cost[0] = amt;
			break;
			
		case 'U':
			updateBook->cost[1] = amt;
			break;
			
		case 'R':
			updateBook->cost[2] = amt;
			break;
			
		case 'E':
			updateBook->cost[3] = amt;
			break;
			
		default:
			cout << "\n Error...\n Incorrect selection.\n";
			return;
	}
}

void GB(vector<string> input)
{
	ISBN i = input[1];
	
	/*Input Validation*/
	Book* pBook = findBook(i);
	if(pBook == NULL)
	{
		cout << "Error... book not in database\n";
		return;
	}
	
	pBook->printKnownInfo();
}

void PB()
{
	/*Find and print all information of every book in database*/
	for(int i = 0; i < listOfISBN.size(); i++)
	{
		findBook(listOfISBN[i])->printKnownInfo();
	}
}

void PY(vector<string> input)
{
	/*Seperate date and convet to number for easier comparison*/
	/*Date Format: MM/YYYY*/
	int month = stoi(input[1].substr(0,2));
	int year =  stoi(input[1].substr(3,4));
	
	/*Print books published on or after date*/
	for(int i = 0; i < listOfISBN.size(); i++)
	{
		/*Exstract current book information*/
		Book* b = findBook(listOfISBN[i]);
		int m = stoi(b->date.substr(0,2));
		int y = stoi(b->date.substr(3,4));
		
		if(y >= year)
		{
			if(y == year) //if the same year, check the month
			{
				if(m >= month)
					b->printKnownInfo();
				else
					continue;
			}
			else
				b->printKnownInfo();
		}
		else
			continue;
	}
	
}

void PD(vector<string> input)
{
	Department d = input[1];
	
	/*Input Validatoin*/
	if (find(listOfDeparments.begin(), listOfDeparments.end(), d) == listOfDeparments.end())
	{
		cout << "Department " << d << " has not been added to the database yet\n";
		return;
	}
	
	for(int i = 0; i < booksInDepartment[d].size(); i++)
	{
		ISBN currisbn = booksInDepartment[d][i];
		findBook(currisbn)->printKnownInfo();
	}
}

void PM(vector<string> input)
{
	Department d = input[1];
	vector<Class*> cINd;
	double secMAX = 0, secMIN = 0, dMAX = 0, dMIN = 0;	//used in average calculation
	double numSec = 0; 									//number of sections in a department
	
	/*Creat a vector of classes in the given department
	  to help with min/max calculation*/
	for(int i = 0; i < listOfClasses.size(); i++)
	{
		if(listOfClasses[i].first == d)
			cINd.push_back(classDataBase[listOfClasses[i]]);
		else
			continue;
	}
	
	/*Find sections max/min and add it to secMAX/secMIN for average*/
	for(int i = 0; i < cINd.size(); i++)                      //Classes in the department
	{
		Class* currClass = cINd[i];
		numSec += currClass->sec.size();
		for(int j = 0; j < currClass->sec.size(); j++)        //Sections in the class
		{
			Section s = currClass->sec[j];
			double currmax = 0, currmin = 0; //min/max for section s
			for(int c = 0; c < currClass->booksInSection[s].size(); c++) //Books in section
			{
				Book* currBook = findBook(currClass->booksInSection[s][c].first);
				/*Find sum of all min/max costs for required books*/
				if(currClass->booksInSection[s][c].second == "R" ||
				   currClass->booksInSection[s][c].second == "r")
				{
					currmax += *max_element(currBook->cost.begin(), currBook->cost.end()); //most expensive version
					currmin += *min_element(currBook->cost.begin(), currBook->cost.end()); //cheapest version
				}
				/*Find sum of all max costs for optional books*/
				else if(currClass->booksInSection[s][c].second == "O" ||
						currClass->booksInSection[s][c].second == "o")
				{
					currmax += *max_element(currBook->cost.begin(), currBook->cost.end()); //most expensive version
				}
				else
					continue;
			}
			/*Sum all min/max costs for every section*/
			secMAX += currmax;
			secMIN += currmin;
		}
	}
		
	cout << fixed;
	cout << "Department: " << d << endl;
	cout << "Average Max: " << setprecision(2) << "$" << (secMAX/numSec) << endl;
	cout << "Average Min: " << setprecision(2) << "$" << (secMIN/numSec) << endl;
	
}
	
/*--------------------------------------------------------------------------*/
/* HELPER FUNCTION IMPLEMENTATION */
/*--------------------------------------------------------------------------*/

Book* findBook(string isbn)
{
	/*Input Validation*/
	auto check = DataBase.find(isbn);
	if(check == DataBase.end())
	{
		return NULL;
	}
	else
	{
		return DataBase[isbn];
	}
}

Class* findClass(ClassKey key)
{
	/*Input validation*/
	auto check = classDataBase.find(key);
	if(check == classDataBase.end())
	{
		return NULL;
	}
	else
	{
		return classDataBase[key];
	}
	
}
