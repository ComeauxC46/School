// Chris Comeaux
// CSCE 121-510
// Due : October 18,2015
// Hw5pr4.cpp

#include "std_lib_facilities_4.h"

void search (const string, int);

int main()

	try
	{
			//user input
			int position;
			string letters;
			cout<< "Please enter a position and a list of characters to search for\n";
			
		while(cin>> position >>letters)
		{		
			//search the vector
			search(letters, position);
			
			cout<< "Enter another position and another string or CTRL + C to exit\n";
		}
		
	return 0;
	}
	catch (exception& e)
	{
		cerr << e.what() <<endl;
		return 1;
	}

void search(const string s, int p)
{			
	int count; //accumilator variable
	p -= 1; // acount for one off error
	ifstream inf {"/usr/share/dict/words"}; // input object inf connected to /usr/share/dict/words
	if(!inf)
		error("cant open the input file");
	for ( string i; inf >> i;)
	{
			if (i.size() <= p) // if the word doesnt contain that many letters, skip it
				continue;
			for(int c = 0; c < s.size(); c++)
			{
				//lowercase
				if(i.at(p) == s.at(c)) //compare each character of the input string with the character at position p
					count++;
				//uppercase
				if(i.at(p) == toupper(s.at(c))) //compare each uppercase character of the input string with the character at position p
					count++;
			}
	}
	
	cout<<count <<" words in the dictionary have one of the letters " <<s <<" in position " <<p+1 <<endl;
}
			