// Chris Comeaux 622006681
// Section 501
// Best Burger

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	//define constants
	const double COST = 10.0;  // Cost of one burger
	const double DISC1 = 0.10; // discount of first range
	const double DISC2 = 0.25; // discount of second range
	const double DISC3 = 0.50; // discount of third range
	const double DISC4 = 0.75; // discount of fourth range
	
	// define variables
	double quantity; // Number of burgers ordered
	double total_1;    // Holds total before discount is applied
	double mult_1;    // Holds cost multiplied by dicount
	double total_f;  // Holds final cost
	
	// program set-up and input
	cout << "This program will calculate the total";
	cout << " after a discount is applied.\n";
	cout << "Please enter the number of burgers ordered.\n";
	cin >> quantity;
	
	cout << setprecision(2) << fixed; // format output to 2 decimal places
	
	// Conditions and execution of program
	if (quantity >=0)
	 {
		if (quantity >= 100.0)
		{
			total_1 = quantity*COST;
			mult_1 = total_1*DISC4;
			total_f = total_1-mult_1;
			cout << "The total cost is $" <<total_f <<endl;
		}
		
		else if (quantity >50.0 && quantity <99.0) 
		{
			total_1 = quantity*COST;
			mult_1 = total_1*DISC3;
			total_f = total_1-mult_1;
			cout << "The total cost is $" <<total_f <<endl;
		}

		else if (quantity >20.0 && quantity <49.0)
		{
		
			total_1 = quantity*COST;
			mult_1 = total_1*DISC2;
			total_f = total_1-mult_1;
			cout << "The total cost is $" <<total_f <<endl;
		}	
	
		else if (quantity >10.0 && quantity <19.0)
		{
		
			total_1 = quantity*COST;
			mult_1 = total_1*DISC1;
			total_f = total_1-mult_1;
			cout << "The total cost is $" <<total_f <<endl;
		}	
		
		else 
			cout << "You must order at least 10 burgers to receive a discount\n";
	 }		
	
	else 
		cout << "Please enter a valid number (grater than 0). Thank you.\n";

return 0;
}		
			
			
			
			
			
