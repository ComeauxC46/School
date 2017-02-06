/*
    File        : Book.H

    Author      : 
	
    Date        : 2017/02/01
	
	Description : Declaration of the Book and Class structures
				  Book  - Models a textbook used in school
				  Class - Models a college course

*/

#ifndef _Book_H_                   // include file only once
#define _Book_H_ 

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <map>				//Used ordered map to improve lookup time to O(1)
#include <algorithm>		//find and trasnform
#include <utility>          //pair
#include <iomanip>			//output formatting

using namespace std;


/*--------------------------------------------------------------------------*/
/* TYEPDEF */ 
/*--------------------------------------------------------------------------*/

typedef string Department; 
typedef string ISBN;
typedef string Section;
typedef pair<Department,string> ClassKey; //class key formed from department and class number

/*--------------------------------------------------------------------------*/
/* FORWARDS */ 
/*--------------------------------------------------------------------------*/

class Book; 
class Class; 

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

extern map<ISBN, Book*>               DataBase;               //Associates an ISBN with a Book
extern map<Department, vector<ISBN> > booksInDepartment;      //All books in a specific department
extern map<ClassKey, Class*>          classDataBase;          //All books in a specific department

extern vector<ClassKey>               listOfClasses;          //Holds a list of all classes defined
extern vector<Department>             listOfDeparments;       //Holds a list of all deparments defined
extern vector<ISBN>                   listOfISBN;             //Holds a list of all ISBN defined 


/*--------------------------------------------------------------------------*/
/* CLASS   C L A S S */
/*--------------------------------------------------------------------------*/

class Class{
	
private:

	
	ClassKey key;			//Key used to differentiate between classes easier
	Department code;
	string courseNum;
	string courseName;
	vector<Section> sec;    //Sections associated with a class  
	
	/*Maps a class section number with all required and optional books*/
	map<Section, vector<pair<ISBN,string> > > booksInSection;
	
public:

	/*Constructors*/
	Class();
	Class(string code, string Num, string Name);
	
	/*Member Functions*/
	void printKnownInfo();
	/*Prints all info defined for a certain book
	  Uninitilized information will be ignored*/
	
	/*Allow command functoins access to private members*/
	friend void C(vector<string> input);
	friend void A(vector<string> input);
	friend void GC(vector<string> input);
	friend void GS(vector<string> input);
	friend void PC();
	friend void PM(vector<string> input); //Declared/Defined in BOOK FRIEND FUNCTIONS
};

/*--------------------------------------------------------------------------*/
/* CLASS FRIEND FUNCTIONS*/
/*--------------------------------------------------------------------------*/

/* Description of command functions provided in README.txt*/
void C(vector<string> input);
void A(vector<string> input);
void GC(vector<string> input);
void GS(vector<string> input);
void PC();

/*--------------------------------------------------------------------------*/
/* CLASS   B O O K */
/*--------------------------------------------------------------------------*/

class Book{

private:

	/*Characteristics of a Book*/
	ISBN isbn;
	string title;
	string author;
	string edition;
	string date;		                 //Must be in MM/YYYY format
	vector<double> cost = {0, 0, 0, 0};  /*Vector of 4 amounts:
										   [0] - cost of new book
										   [1] - cost of used book
										   [2] - cost of rented book
										   [3] - cost of electronic edition*/	

public:

	/*Public Members*/
	vector<ClassKey> courses;
	/*Just as Class knows which books is associated with it,
	  Books know ehich classes it is assigned to*/
	  
	/*Constructors*/
	Book();
	Book(string isbn, string t);
	
	/*Member Functions*/
	void printKnownInfo();
	/*Prints all info defined for a certain book
	  Uninitilized information will be ignored*/
	
	/*Allow command functoins access to private members*/
	friend void B(vector<string> input);
	friend void D(vector<string> input);
	friend void M(vector<string> input);
	friend void GB(vector<string> input);
	friend void PB();
	friend void PY(vector<string> input);
	friend void PD(vector<string> input);
	friend void PM(vector<string> input);
};

/*--------------------------------------------------------------------------*/
/* INPUT COMMAND FUNCTIONS*/
/*--------------------------------------------------------------------------*/

/* Description of command functions provided in README.txt*/
void B(vector<string> input);
void D(vector<string> input);
void M(vector<string> input);
void GB(vector<string> input);
void PB();
void PY(vector<string> input);
void PD(vector<string> input);
void PM(vector<string> input);

/*--------------------------------------------------------------------------*/
/* HELPER FUNCTIONS*/
/*--------------------------------------------------------------------------*/

Book* findBook(string isbn);
/* Takes an ISBN as a string and returns
   a pointer to the defined book with
   that ISBN. Returns NULL if failed.
*/

Class* findClass(ClassKey key);
/* Takes an ClassKey  and returns
   a pointer to the defined book with
   that key. Returns NULL if failed.
*/

#endif