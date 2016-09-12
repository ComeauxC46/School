// Chris Comeaux
// CSCE 121-510
// Due : October 18,2015
// Hw5pr3.cpp

#include "std_lib_facilities_4.h"

int main()

	try
	{
		string in_name1, in_name2, out_name;
		cout<< "Please enter 3 file names (2 input files and 1 output file)\n"
			<< "File 1\n";
		cin >> in_name1;
		cout<< "File 2\n";
		cin >> in_name2;
		cout<< "File 3\n";
		cin >> out_name;
		
		ifstream inf1 {in_name1}; // open first file and assign object inf1--input file 1
		if (!inf1) error ("file one did not open correctly");
		
		ifstream inf2 {in_name2}; // open first file and assign object inf2--input file 2
		if (!inf2) error ("file two did not open correctly");
		
		ofstream opf {out_name}; // open first file and assign object opf--output file 
		if (!opf) error ("file three did not open correctly");
		
		int line = 1; // keep track of what line we are on
		
		while (!inf1.eof() && !inf2.eof())
		{
			string a, b;
			getline(inf1, a);
			getline(inf2, b);
			
			if (a.compare(b) != 0) //if the 
				opf << line++ <<":DIFF\n";
			else
				opf << line++ <<":OK\n";
			
		}
	return 0;
	}
	catch(exception& e)
	{
		cerr << e.what() <<endl;
	}
			