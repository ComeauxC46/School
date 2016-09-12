// Chris Comeaux 622006681
// Section 501
// Rainfall Statistics 

#include <iostream>
#include <string>
using namespace std;

void initialize_Array (double[], int, string[]); // initilizes rainMonth array
void display (const double[], int, string[]); // displays output
void min_max (const double [], int, string []); // computes min and max

int main()
{
	// creat arrays
	const int NUM_MON = 12;   // number of months
	string nameMonth[NUM_MON] = {"January", "February", "March", "April", 
								 "May", "June", "July", "August",
								 "September", "October", "November", "December"};
	double rainMonth[NUM_MON] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
								 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,}; // array that will hold monthly rainfall
	// initilize rainMonth
	initialize_Array(rainMonth, NUM_MON, nameMonth);
	
	// display output
	display(rainMonth, NUM_MON, nameMonth);
	min_max(rainMonth, NUM_MON, nameMonth);
	
return 0;
}

void initialize_Array (double rainFall[], int monthNum, string name[])
{
	
	cout <<"Please enter the total rainfall for each month (in inches)...\n";
	for(int count = 0; count < monthNum; count++)
	{
		cout << name[count] <<":";
		cin >> rainFall[count];
		while (rainFall[count] < 0)
		{
			cout <<"Rainfall cannot be negative, please enter a valid number\n";
			cin >> rainFall [count];
		}
	}
}

void display (const double rainFall[], int monthNum, string name[])
{
	double total = 0; // accumulator variable
	double avg;       // holds value of the average monthly rainfall
	
	cout <<"\t\tRainfall For Each Month\n";
	// display monthly rainfall
	for(int count = 0; count < monthNum; count++)
	{	
		cout << name[count]; 
		if(count >= 2 && count <=7) // align all output into 1 column 
			cout <<":\t\t"; 
		else
			cout <<":\t";
		cout<< rainFall[count] <<" inches" << endl;
	}
	cout << endl;
	
	// total rainfall	
	for(int count = 0; count < monthNum; count++)
		total += rainFall[count];
	cout <<"Total rainfall for the year:\t " << total <<" inches" <<endl;
	
	// calculate/display average rainfall
	avg = total/monthNum;
	cout <<"Average monthly rainfall:\t " <<avg << " inches" <<endl << endl;
}
	
void min_max (const double rainFall[], int monthNum , string name[])
{
	double lowest = rainFall[0];
	double highest = rainFall[0];
	string lMonth = name[0];
	string hMonth = name[0];
	
	for(int count = 1; count < monthNum; count++)
	{
		if (rainFall[0] > rainFall[count])
		{
			lowest = rainFall[count];
			lMonth = name[count];
		}
	}
	
	for(int count = 1; count < monthNum; count++)
	{
		if (rainFall[0] < rainFall[count])
		{	
			highest = rainFall[count];
			hMonth = name[count];
		}
	}
	cout <<"Highest Rainfall recorded is " << highest;
	cout <<" inches in the month of " << hMonth << " inches" << endl;
	cout <<"Lowest Rainfall recorded is " << lowest;
	cout <<" inches in the month of " << lMonth << " inches" << endl;
}
	
		
	
	
	
	
	