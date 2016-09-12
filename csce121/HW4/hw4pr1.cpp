// Chris Comeaux
// CSCE 121-501
// Due: october 8, 2015
// hw4pr1.cpp
#include "std_lib_facilities_4.h"
#include "randint.h"

int main()
{	
	//acumilators
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

		cout << "There were " <<zero <<" 0's\n";
		cout << "There were " <<one <<" 1's\n";
		cout << "There were " <<two <<" 2's\n";
		cout << "There were " <<three <<" 3's\n";
		cout << "There were " <<four <<" 4's\n";
		cout << "There were " <<five <<" 5's\n";
		cout << "There were " <<six <<" 6's\n";
		cout << "There were " <<seven <<" 7's\n";
		cout << "There were " <<eight <<" 8's\n";
		cout << "There were " <<nine <<" 9's\n";
	}
	
	catch(...)
	{
		cerr << "Error occured";
	}
return 0;
}