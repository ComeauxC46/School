// Chris Comeaux
// CSCE 121-510
// Due : October 18,2015
// Hw5pr2.cpp

#include "std_lib_facilities_4.h"

void fill_vector (vector<string>&); //function to fill vector
void search (const vector<string>&, int);

int main()

	try
	{
			vector<string>words; // create vector to hold the words
			fill_vector (words);
			
			//user input
			int position;
			cout<< "Please enter a position\n";
			
		while(cin>> position)
		{		
			//search the vector
			search(words, position);
			
			cout<< "Enter another position or 'q' to exit\n";
		}
		
	return 0;
	}
	catch (exception& e)
	{
		cerr << e.what() <<endl;
		return 1;
	}
	

void fill_vector (vector<string>& w)
{
	ifstream inf {"/usr/share/dict/words"}; // input object inf connected to /usr/share/dict/words
		if(!inf)
			error("cant open the input file");
	for ( string i; inf >> i;)
		w.push_back(i);
}

void search(const vector<string>& w, int p)
{
	int count; //accumilator variable
	p -= 1; // acount for one off error
	
	for( int i =0; i < w.size(); i++)
	{
		if (w[i].size() <= p) // if the word doesnt contain that many letters, skip it
			continue;
		//lower case
		if (w[i].at(p) == 'a' ||w[i].at(p) == 'e' ||w[i].at(p) == 'i' ||w[i].at(p) == 'o' ||w[i].at(p) == 'u')
			count++;
		//uppercase
		if (w[i].at(p) == 'A' ||w[i].at(p) == 'E' ||w[i].at(p) == 'I' ||w[i].at(p) == 'O' ||w[i].at(p) == 'U' )
			count++;
		
	}
	
	cout<<count <<" words in the dictionary have a vowel in position " <<p+1 <<endl;
}
			
			