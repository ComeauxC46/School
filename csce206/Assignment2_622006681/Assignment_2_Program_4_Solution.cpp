//Chris Comeaux
//622006681
//Section 501
//TAMU Mobile

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	//define the constants
	const double PAC_A = 5.75,  // Holds the rate per month for package A
				 PAC_B = 14.95, // Holds the rate per month for package B
				 PAC_C = 18.95, // Holds the rate per month for package C
				 PAC_D = 30.00; // Holds the rate per month for package D
				 
	const double PAC_A_EXTRA = 6.75,  // Holds the rate per month for additional hours in package A
				 PAC_B_EXTRA = 19.95, // Holds the rate per month for additional hours in package B
				 PAC_C_EXTRA = 25.95; // Holds the rate per month for additional hours in package C
				 
	const int CHOICE_A = 1;        // Holds A for package A
	const int CHOICE_B = 2;        // Holds B for package B
	const int CHOICE_C = 3;        // Holds C for package C
	const int CHOICE_D = 4;        // Holds D for package D
	const int CHOICE_E = 5;        // Holds E for Quit
	
	//user defined variables
	int choice;        // Holds the choice 
	double hours;       // Holds the total number of hours used
	double base_hours;  // Holds up to the maximum hours used
	double extra_hours;  // Holds the additional hours used
	double sum1;        // Holds the cost of base hours times normal per hour rate
	double sum2;        // Holds the cost of extra hours times extra hour rate
	double total;       // Holds the total cost of bill
	double discount;    // Hold how much customer gets off if eligible for discount
	
		// creat manue
		cout << "\t\tLIST OF PACKAGES\n\n";
		cout << "1. Package A\n";
		cout << "2. Package B\n";
		cout << "3. Package C\n";
		cout << "4. Package D\n";
		cout << "5. QUIT\n\n";
		cout << "Please enter either 1, 2, 3, or 4 depending on which package you have\n";
		cout << "Or enter 5 to quit the program\n\n";
		cin >> choice;
		
		// following code takes input and generates total cost
		switch (choice)
		{
			case CHOICE_A: 
				cout << "Please enter the number of hours used this month\n";
				cin >> hours;
				extra_hours = hours-15.0; // 15 is the max hours for Package A
					if (extra_hours > 0.0)
					 {
						base_hours = hours-extra_hours;
						sum1 = base_hours*PAC_A;
						sum2 = extra_hours*PAC_A_EXTRA;
						total = sum1+sum2;
					 }
					
					else 
					 total = hours*PAC_A;
				break;
			
			case CHOICE_B: 
				cout << "Please enter the number of hours used this month\n";
				cin >> hours;
				extra_hours = hours-20.0; // 20 is the max hours for Package B
					if (extra_hours > 0.0)
					 {
						base_hours = hours-extra_hours;
						sum1 = base_hours*PAC_B;
						sum2 = extra_hours*PAC_B_EXTRA;
						total = sum1+sum2;
					 }
					
					else 
					 total = hours*PAC_B;
				break;
				
			case CHOICE_C: 
				cout << "Please enter the number of hours used this month\n";
				cin >> hours;
				extra_hours = hours-25.0; // 20 is the max hours for Package C
					if (extra_hours > 0.0)
					 {
						base_hours = hours-extra_hours;
						sum1 = base_hours*PAC_C;
						sum2 = extra_hours*PAC_C_EXTRA;
						total = sum1+sum2;
					 }
					
					else 
					 total = hours*PAC_C;
				break;
			
			case CHOICE_D: 
				cout << "Please enter the number of hours used this month\n";
				cin >> hours;
				total = hours*PAC_D;
				break;
				
			case CHOICE_E:
				cout << "Program Ending...\n";
				break;
				
			default:
				cout << "Please enter a valid number (1-5) and restart the program.\n";
		}
		
		// calculate discount if the the costumer qualifies 
		if (choice != CHOICE_D && total >= 30.00)
		 {	
			cout << "You are eligible for a %10 discount!\n";
			discount = total*0.1; // 10 % discount
			total -= discount;
		 }
		 
	cout <<setprecision (2) << showpoint << fixed; // Make output to 2 decimal places
	
	// display output to user
	if (choice >= CHOICE_A && choice <= CHOICE_D)	
		cout << "Your monthly bill will cost: $" <<total <<endl;
return 0;
}