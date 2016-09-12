//Chris Comeaux
//CSCE 121-501
//Due: September 29, 2015
//hw3pr1.cpp

#include "std_lib_facilities_4.h"

double my_sqrt_1(double);// function prototype

//used for exceptions
string badI;
string x = "This is not a valid value\n"; // used to throw exception

int main()
{
	try
	{
		for(auto k: {-100, -10, -1, 0, 1, 10, 100})
		{
			double n; //holds answer
			n = M_PI*pow(10.0,k);
			cout<<"When k = " <<k <<" n = "<<n;
			cout<< "\tsqrt(n) = " <<sqrt(n);
			cout<< "\tmy_sqrt_1(n) =" <<my_sqrt_1(n) <<endl<<endl;
		}
	}
	catch(...)
	{
		cerr<< x;
	}
	
return 0;
}

double my_sqrt_1(double n)
{
	double lBound;
	double uBound;
	double midPt;
	
	//test to se if bad input if not change error number to 0 so the while loop terminates
	if (n < 0) 
		throw badI;

	// compute square root
	if (n<1)
		lBound = n;
	else 
		lBound = 1.0+(n-1)/2.0-((n-1)*(n-1))/8.0;
	
	uBound = (n+1)/2.0;
	
	for (int c = 1; c <=10; c++)
	{
		midPt = (lBound + uBound)/2.0;
		if ((midPt*midPt)> n)
			uBound = midPt;
		if ((midPt*midPt)< n)
			lBound = midPt;
	}
return midPt;
}
	