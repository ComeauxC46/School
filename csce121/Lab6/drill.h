#include "std_lib_facilities_4.h"
void choice(char, double);
int main()
{
	//varibles used
	
	char test;
	double degree;
	
	//get user input
	cout<< "This prgram will convert celcius to fahrenheit or vise verse.\n";
	cout<< "Please enter c if you want to convert from celcius to fahrenheit\n";
	cout<< "and enter f if you want to convert from fahrenheit to celcius\n";
	cin>> test;
	cout<< "Please enter the value.\n";
	cin>> degree;
	try
	{
		choice(test, degree);
	}
	catch(badC)
	{
		cerr<< "The degree cannot be below absolute 0(-273.15C)\n";
	}
	catch(badF)
	{
		cerr<< "The degree cannot be below absolute 0(-459.67F)\n";
	}

return 0;
}

void choice(char test, double degree)
{
	double answer;
	double absC = -273.15;
	double absF = -459.67;
	const char cel = 'c';
	const char fah = 'f';
	//switch statement
	
		switch (test)
		{
		case cel:
			if(degree < absC)
				throw badC;
			answer = degree*(9.0/5)+32;
			cout<< "The converteed tempature is " <<answer <<"F"<<endl;
			break;
		case fah:
			if(degree < absF)
				throw badF;
			answer = (degree-32)*(5.0/9);
			cout<< "The converteed tempature is " <<answer <<"C"<<endl;
			break;
		default:
			cout<< "The character entered was not valid\n";
		}
}