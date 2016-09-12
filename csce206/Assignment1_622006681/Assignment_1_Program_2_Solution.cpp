/* Chris Comeaux 
622006681
Section 501
Dining Hall*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	
	// Input variables
	string Dining_Hall_Name;   //Holds name of dining hall
	const double OnCampus = 350.75;  // Initial cost of on campus plan in $ per semester
	const double OffCampus = 500.25; // Initial cost of off campus plan in $ per semester
	double Number_On;          // Number of on Campus plans sold
	double Number_Off;         // Number of off Campus plans sold
	
	// output variables
	double On_Revenue;          // On Campus plans Revenue
	double Off_Revenue;         // Off Campus plans Revenue
	double Total_Revenue;       // Total revenue earned in semester
	
		// info about program
		cout << " This program calculates the total revenue of\n";
		cout << " different dining halls depending on how many \n";
		cout << " OffCampus and OnCampus plans were sold\n";

		
		// input from user
		cout << "Please enter the name of the Dining Hall.\n";
		getline(cin, Dining_Hall_Name);
		cout << "Please enter the number of On Campus plans sold.\n";
		cin >> Number_On;
		cout << "Please enter the number of Off Campus plans sold.\n";
		cin >> Number_Off;
		
		// Calulate on campus revenue
		On_Revenue = OnCampus*Number_On;
		
		// Calculate off campus revenue
		Off_Revenue = OffCampus*Number_Off;
		
		// Calculate Total Revenue
		Total_Revenue = On_Revenue+Off_Revenue;
		
	// Output 
	cout << "Dining Hall Name:" << setw(35) << Dining_Hall_Name <<endl;
	cout << "OnCampus plans sold:" << setw (25) << Number_On <<endl;
	cout << "OffCampus plans sold:" << setw(24) << Number_Off <<endl;
	cout << setprecision(2) <<fixed;
	cout << "Revenue from OnCampus plans:" <<setw (13) <<"$" <<On_Revenue <<endl;
	cout << "Revenue from OffCampus plans:" <<setw(12) <<"$" <<Off_Revenue <<endl;
	cout << "Total Revenue earned in semester:" <<setw (8) <<"$" <<Total_Revenue <<endl;
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
