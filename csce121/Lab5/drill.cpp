#include "std_lib_facilities_4.h"

int main()
{
	//varibles used
	const char cel = 'c';
	const char fah = 'f';
	char test;
	double degree;
	double answer;
	//get user input
	cout<< "This prgram will convert celcius to fahrenheit or vise verse.\n";
	cout<< "Please enter c if you want to convert from celcius to fahrenheit\n";
	cout<< "and enter f if you want to convert from fahrenheit to celcius\n";
	cin>> test;
	cout<< "Please enter the value.\n";
	cin>> degree;
	
	//switch statement
	switch (test)
	{
	case cel:
		answer = degree*(9.0/5)+32;
		cout<< "The converteed tempature is " <<answer <<"F"<<endl;
		break;
	case fah:
		answer = (degree-32)*(5.0/9);
		cout<< "The converteed tempature is " <<answer <<"C"<<endl;
		break;
	default:
		cout<< "The character entered was not valid\n";
	
	}
return 0;
}
