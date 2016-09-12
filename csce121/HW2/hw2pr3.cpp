//Chris Comeaux 
//CSCE 121 - 501
// Due: September 22, 2015
// hw2pr3.cpp

#include "std_lib_facilities_4.h"
double get_income(); //function prototype	

// used for exceptions
string badI = "This input is not valid. Please enter a number grater than 0 and run the program again.\n";// used to throw an exception
class e{}; //used to trow to exit

int main()
{
	// Variables needed
	double liv;
	double income;
	double ten_p; //value of 10 percent of the income

	

	try
	{
		income = get_income();
		
	
		while(cin)
		{
			//calculations
			liv = income*.8;
			ten_p = income*.1;
			
			cout<<setprecision(2)<<fixed; //fomating output two 2 decimal points
			cout<< "You should give away about $" <<ten_p <<", save about $";
			cout<< ten_p <<", and live on about $" <<liv <<endl;
			
			income = get_income();

		}
	}
	catch(string x)// catches bad input
	{
		cerr<<x;
		exit(1); //exits the program so it doesnt run with the bad input
	}
		
	catch(...) // exits program
	{
		exit(1);
	}
	
return 0;
}

double get_income()
{
	double i;
	cout<< "\nPlease enter the amout of income in dollars or a character to exit.\n";
	cin>> i;
	if (!cin)
		throw e{}; // if a character then exit
	if (i <= 0)
		throw badI;
	return i;
}
