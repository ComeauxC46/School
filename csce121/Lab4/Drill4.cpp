#include "std_lib_facilities_4.h"

int main()
{
	double i1;
	double i2;
	double smallest;
	double largest;
	cout<< "Please enter a double\n";
	cin>> i1;
	smallest = i1;
	largest = i2;
	cout<< "please enter another double\n";
	while(cin>>i2)
	{
		if(i2<smallest)
			smallest=i2;
		if(i2>largest)
			largest=i2;
		
		cout<< "The smallest so if is: " <<smallest<<endl;
		cout<< "The largest so far is: " <<largest<<endl;
		cout<< "Please enter aother double enter | to exit\n";
	}
	
return 0;
	
}