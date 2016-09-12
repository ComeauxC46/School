// Chris Comeaux 
// CSCE 121-501
// Due: September 15, 2015
// hw1pr1.cpp
#include "std_lib_facilities_4.h"


// puzzle initilized into a two dimentional array
char puzzle[11][16] = {' ',' ',' ',' ',' ','1',' ',' ',' ','4','5',' ',' ',' ','8',' ',
					   ' ',' ',' ',' ',' ','K',' ','3','M','C','C','A','R','T','H','Y',
					   '1','A','L','L','E','N',' ',' ',' ','O','O',' ',' ',' ','O','6',
					   '6','B','A','C','K','U','S',' ',' ','O','C',' ',' ',' ','Q','W',
					   ' ',' ',' ',' ','3','T',' ',' ',' ','K','K',' ',' ',' ','R','I',
					   '9','2','B','A','C','H','M','A','N',' ','E',' ',' ',' ','E','R',
					   'B',' ','R',' ','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','T',
					   'L',' ','O',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',
					   'U',' ','O',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					   'M',' ','K',' ',' ',' ',' ',' ',' ','4','P','E','R','L','I','S',
					   ' ','2','S','U','T','H','E','R','L','A','N','D',' ',' ',' ',' '};
int main()
{
	// instructions 
	cout<< "\t****CROSSWORD PUZZLE****\n";
	cout<< "ACROSS\n";
	cout<< "1. Optomizing compilers and automatic parallel execution\n";
	cout<< "2. Sketchpad, computer graphics";
	cout<< "3. \"The Present State of Research on Artificial Intellegence\"\n";
	cout<< "4. Programming techniques and compiler construction\n";
	cout<< "5. Database Technology\n";
	cout<< "6. Designed high level programming system (FORTRAN)\n\n";
	cout<< "DOWN\n";
	cout<< "1. \"Art of Computer Programming\"\n";
	cout<< "2. Software Engineering\n";
	cout<< "3. theory and practice of database management system\n";
	cout<< "4. \"The Complexity of Theorum Proving Procidures\"\n";
	cout<< "5. compilers, architecture of large system, RISC\n";
	cout<< "6. EVLER, ALGOL-W, MODULA,PASCAL\n";
	cout<< "7. automatic-cosing systems, error-detecting/error-correcting codes\n";
	cout<< "8. definition and design of programming languages\n";
	cout<< "9. computatuinal complexity theory\n";
	
	// nested for loop to ouput 11 by 16
	for( int c1=0; c1<=10; c1++) // increments colums
	{
		for(int c2=0; c2<=15; c2++) // increments rows
		{
		cout<< puzzle[c1][c2];
		cout<< " "; //adds a space between the elements and makes output easier to read
		}
		cout <<endl;
	}
	
return 0;
}
	