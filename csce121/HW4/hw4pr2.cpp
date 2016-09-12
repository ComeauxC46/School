// Chris Comeaux
// CSCE 121-501
// Due: october 8, 2015
// hw4pr2.cpp
#include "std_lib_facilities_4.h"
#include "randint.h"

int main()
{
	//accumilator variables
	int zero = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;
	
	try
	{
		for(int i = 0;  i < 1000000; i++)
		{
			int x = randint ();
			if ( (x % 10) == 0)
				zero++;
			if ( (x % 10) == 1)
				one++;
			if ( (x % 10) == 2)
				two++;
			if ( (x % 10) == 3)
				three++;
			if ( (x % 10) == 4)
				four++;
			if ( (x % 10) == 5)
				five++;
			if ( (x % 10) == 6)
				six++;
			if ( (x % 10) == 7)
				seven++;
			if ( (x % 10) == 8)
				eight++;
			if ( (x % 10) == 9)
				nine++;
		}

		// output format: set left, width =10, fill is a blank space
		cout<<left <<setw(10) <<setfill(' ') <<"Date";
		cout<<"Fequency\n";
		
		cout<<left <<setw(10) <<setfill(' ') <<"0";
		cout<<left <<setw(10) <<setfill(' ') <<zero;
		cout<<left <<setw(10) <<setfill(' ') <<string(zero/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"1";
		cout<<left <<setw(10) <<setfill(' ') <<one;
		cout<<left <<setw(10) <<setfill(' ') <<string(one/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"2";
		cout<<left <<setw(10) <<setfill(' ') <<two;
		cout<<left <<setw(10) <<setfill(' ') <<string(two/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"3";
		cout<<left <<setw(10) <<setfill(' ') <<three;
		cout<<left <<setw(10) <<setfill(' ') <<string(three/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"4";
		cout<<left <<setw(10) <<setfill(' ') <<four;
		cout<<left <<setw(10) <<setfill(' ') <<string(four/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"5";
		cout<<left <<setw(10) <<setfill(' ') <<five;
		cout<<left <<setw(10) <<setfill(' ') <<string(five/2000, '*') <<endl;
			
		cout<<left <<setw(10) <<setfill(' ') <<"6";
		cout<<left <<setw(10) <<setfill(' ') <<zero;
		cout<<left <<setw(10) <<setfill(' ') <<string(six/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"7";
		cout<<left <<setw(10) <<setfill(' ') <<seven;
		cout<<left <<setw(10) <<setfill(' ') <<string(seven/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"8";
		cout<<left <<setw(10) <<setfill(' ') <<eight;
		cout<<left <<setw(10) <<setfill(' ') <<string(eight/2000, '*') <<endl;
		
		cout<<left <<setw(10) <<setfill(' ') <<"9";
		cout<<left <<setw(10) <<setfill(' ') <<nine;
		cout<<left <<setw(10) <<setfill(' ') <<string(nine/2000, '*') <<endl;
	}
	catch(...)
	{
		cerr<< "error occured";
	}
return 0;
}