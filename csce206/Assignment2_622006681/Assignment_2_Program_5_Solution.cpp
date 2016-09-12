//Chris Comeaux 622006681
// Section 501
// Fanatic Jogger

#include <iostream>
using namespace std;

int main()
{

		//Define variables
		double total = 0.0;    // holds the total points earned during the week
		double milesRan = 0.0; // holds number of miles ran by the user for that day
		double product = 0.0;  // holds product for one mile to be added up for that one day
		double total1 = 0.0;   // holds total points on monday
		double total2 = 0.0;   // holds total points on tuesday
		double total3 = 0.0;   // holds total points on wednesday
		double total4 = 0.0;   // holds total points on thursday
		double total5 = 0.0;   // holds total points on friday
		double total6 = 0.0;   // holds total points on saturday
		double total7 = 0.0;   // holds total points on sunday
		
		
		
		// Define constants
		const double MON = 8.0,  // Holds base points for Monday
					 TUE = 13.0, // Holds base points for Tuesday
					 WED = 15.0, // Holds base points for Wednesday
					 THU = -5.0, // Holds base points for Thursday
					 FRI = 20.0, // Holds base points for Friday
					 SAT = -3.0, // Holds base points for Saturday
					 SUN = 9.0;  // Holds base points for Sunday 
		double day = 1;          // holds day number(monday =1 tues = 2 ect.)
					 
	//calculate total for each day 
	for (day; day <= 7; day++)
		{
		
			cout << "Please enter the number of miles ran on day " <<day <<endl;
			cin >> milesRan;
			
			if (day == 1)
			{ 
				for (int miles = 1; miles <= milesRan; miles++)
				{
					product = miles*MON;
					total1 += product;
					
				}
			  cout << "On Monday you have " <<total1 <<" points\n";
			}
			else if (day == 2)
			{ 
				for (int miles = 1; miles <= milesRan; miles++)
				{
					product = miles*TUE;
					total2 += product;
					
				}
				cout << "On Tuesday you have " <<total2 <<" points\n";
			}
			else if (day == 3)
			{ 
				for (int miles = 1; miles <= milesRan; miles++)
				{
					product = miles*WED;
					total3 += product;
					
				}
				cout << "On Wednesday you have " <<total3 <<" points\n";
			}
			else if (day == 4)
			{ 
				for (int miles = 1; miles <= milesRan; miles++)
				{
					product = miles*THU;
					total4 += product;
					
				}
				cout << "On Thursday you have " <<total4 <<" points\n";
			}
			else if (day == 5)
			{ 
				for (int miles = 1; miles <= milesRan; miles++)
				{
					product = miles*FRI;
					total5 += product;
					
				}
				cout << "On Friday you have " <<total5 <<" points\n";
			}
			else if (day == 6)
			{ 
				for (int miles = 1; miles <= milesRan; miles++)
				{
					product = miles*SAT;
					total6 += product;
					
				}
				cout << "On Saturday you have " <<total6 <<" points\n";
			}
			else if (day == 7)
			{ 
				for (int miles = 1; miles <= milesRan; miles++)
				{
					product = miles*SUN;
					total7 += product;
					
				}
				cout << "On Sunday you have " <<total7 <<" points\n";
			}
		}
		
		//display output to user
		total = total1+total2+total3+total4+total5+total6+total7;
		cout << "Your total points for the week is " <<total <<" points\n";
	
	return 0;
}
		
		