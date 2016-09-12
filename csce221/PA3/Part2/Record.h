//Record.h
#include <iostream> 
#include <string>

using namespace std;

class Record
{
	//private members
	string bookTitle;
	string authorName;
	string ISBN;
	string publishYear;
	string editionNumber;
public:
	//default constructor
	Record(): bookTitle(""), authorName(""), ISBN(""), publishYear(""), editionNumber("") {}
	
	//constructor
	Record(string bookTitle, string authorName, string ISBN, string publishYear, string editionNumber)
		  :bookTitle(bookTitle), authorName(authorName), ISBN(ISBN), publishYear(publishYear),
		  editionNumber(editionNumber) {}
		  
	// gain access to private members	  
	string getTitle() {return bookTitle;}
	string getAuthor() {return authorName;}
	string getISBN() {return ISBN;}
	string getYear() {return publishYear;}
	string getEdition() {return editionNumber;}
	
	//less than operator
	friend bool operator<(const Record& r1, const Record& r2);
	friend istream& operator>>(istream& in, Record& r);
	friend ostream& operator<<(ostream& out, Record& r);
};

//less then opeator Implementation
//O(1)
bool operator<(const Record& r1, const Record& r2)
{
	if (r1.bookTitle < r2.bookTitle)return true;
	else if (r1.authorName < r2.authorName) return true;
	else if (r1.ISBN < r2.ISBN) return true;
	else return false;
}

//input operator
//O(1)
istream& operator>>(istream& in, Record& r)
{
	getline(in,r.bookTitle); getline(in,r.authorName); getline(in,r.ISBN);
	getline(in,r.publishYear); getline(in,r.editionNumber);
	return in;
}

//output operator
//O(1)
ostream& operator<<(ostream& out, Record& r)
{
	out <<r.bookTitle <<endl <<r.authorName<<endl <<r.ISBN <<endl 
		<<r.publishYear <<endl <<r.editionNumber <<endl;
	return out;
}