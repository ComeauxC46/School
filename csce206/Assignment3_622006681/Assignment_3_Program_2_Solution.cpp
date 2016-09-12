//Chris Comeaux 622006681
//Section 501
//File Operations

#include <iostream>
#include <fstream>
using namespace std;



//global variables to calculate average
double sum = 0.0;   // create variable to hold sum which allows to calculate average
double count = 0.0;  // hold how many times program runs to help calculate the average
double avg;         // holds overall average

int main ()
{
	// Explain program
	cout << "This program takes all the multiples of number 1-8, 11, 13 ";
	cout << "and displays them and the total average in an file called number.txt\n\n";
	cout << "Calculating output.....\n\n";
	cout << "Please refer to the text file named numbers\n";
	
	// Create file object and file name
	ofstream outFile;
	outFile.open("numbers.txt");
	
	//generate output
	for (int num = 1; num <= 13; num++) // create for loop to increment number being multiplied
		{
			double answer =0.0; // create variable to hold each answer

		  if (num == 10 || num ==12) // skips 10 & 12
			continue;
		  else
			{
				for (int mult = 0; answer <= 500.0; mult++) // loop for the multiplier
				  {
					answer = num*mult;
					if (answer <= 500.0)  // only print, average numbers <=500.0
						{
							outFile <<answer <<endl;
							sum += answer;
							count++;
						}
				  }
			}
		}	

		// display average
		avg = sum/count;
		outFile << "The average for all the numbers is: " <<avg <<endl;
		
	outFile.close();  //Close the program
return 0;
}
		
