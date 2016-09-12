//Chris Comeaux 622006681
// Section 501
// Number loops

#include <iostream>
using namespace std;


		// Define veriables
		int count;            // Holds value to count repetition of loop
		int countEven = 0;    // Holds number of even numbers
		int countOdd = 0;     // Holds number of Odd numbers
		double Avg;           // Holds overall average
		double eAvg;          // Holds overall even average
		double oAvg;          // Holds overall odd average
		int number;           // Holds number entered
		double sum = 0;       // Holds sum of all numbers
		
int main ()
{
  do
  {
	//get user input
	cout << "Please enter a whole number that you would like to take the average of...\n";
	cin >> number;
	
		if (number > 0) // input validation
		 {
			for (count = 1; count <= number; count++)
			 {
				sum += count;
			 }
			 Avg = sum/number;
			 cout << "The total average is " <<Avg <<endl;
			 sum = 0.0;  // set sum back to 0
			 
			for (count = 1; count <= number; count++)
			 { 
				if (count % 2 == 0.0)
				{
					sum += count;
					countEven++;
				}
				
				else
				continue;
			 }
			 eAvg = sum/countEven;
			 cout << "The average of the even numbers is " <<eAvg <<endl;
			 sum = 0.0;   // set sum back to 0
			 
			for (count = 1; count <= number; count++)
			 { 
				if (count % 2 != 0.0)
				{
					sum += count;
					countOdd++;
				}
				else
				continue;
			 }
			 oAvg = sum/countOdd;
			 cout << "The average of the odd numbers is " <<oAvg <<endl <<endl; 
			 
			// Find highest average
			if (Avg >= eAvg && Avg >= oAvg)
				{	
					cout << "The overall average is the highest average";
					cout << " with a value :" <<Avg <<endl;
				}
			if (eAvg >= Avg && eAvg >= oAvg)
				{
					cout << "The Even average is the highest average";
					cout << " with a value :" <<eAvg <<endl;
				}					
			if (oAvg >= Avg && oAvg >= eAvg)
				{
					cout << "The Odd average is the highest average";
					cout << " with a value :" <<oAvg <<endl;
				}
				
			if (oAvg == Avg || oAvg == eAvg || Avg == eAvg)
					cout << "These values are the same and are the highest.\n\n";
				
			
			// Find the lowest value
			if (Avg <= eAvg && Avg <= oAvg)
				{	
					cout << "The overall average is the lowest average";
					cout << " with a value :" <<Avg <<endl;
				}
			if (eAvg <= Avg && eAvg <= oAvg)
				{
					cout << "The Even average is the lowest average";
					cout << " with a value :" <<eAvg <<endl;
				}					
			if (oAvg <= Avg && oAvg <= eAvg)
				{
					cout << "The Odd average is the lowest average";
					cout << " with a value :" <<oAvg <<endl;
				}
			if (oAvg == Avg || oAvg == eAvg || Avg == eAvg)
				cout << "These values are the same and are the lowest.\n\n";
				
		 }
				
			else
			cout << "Please enter a valid number: (1-infinity)\n\n";	  
  }while (number <= 0);
	  
  
return 0;	  
}
 			 
		 
		 
		 
	