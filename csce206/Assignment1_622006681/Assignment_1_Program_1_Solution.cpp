//Chris Comeaux 622006681 
//Section 501
//Average Calculations
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//input variables
	double Day_One;   //Number of miles ran on day one
	double Day_Two;  //Number of miles ran on day two
	double Day_Three; //Number of miles ran on day three
	double Day_Four;  //Number of miles ran on day four

	//output variables
	double sum;   //Total miles ran
	double average;  //Average miles
	
	//Collect input from user
		cout << "Hello! I hope you have had a good run!\n";
		cout << "Please enter the number of miles ran on your first run.\n";
		cin >> Day_One;
		cout << "Please enter the number of miles ran on your second run.\n";
		cin >> Day_Two;
		cout << "Please enter the number of miles ran on your third run.\n";
		cin >> Day_Three;
		cout << "Please enter the number of miles ran on your fourth run.\n";
		cin >> Day_Four;
	
	//Calulate the sum
	sum = Day_One + Day_Two + Day_Three + Day_Four;
	
	//Calculate the average
	average = sum/4.0;
	
	//Display output
		cout << "Great job! \n";
		cout << "Your total distance covered is: " << sum << setprecision(2) << fixed;
		cout << " miles" <<endl;
		cout << "Your average distance covered is: " << average << setprecision(2) << fixed;
		cout << " miles per day" << endl;
	
return 0;
}