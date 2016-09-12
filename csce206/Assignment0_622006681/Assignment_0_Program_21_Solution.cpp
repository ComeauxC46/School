// This program calculates hourly wages, including overtime.
#include <iostream>
using namespace std;

	int main()          
{
	double regularWages,
	   
		basePayRate = 18.25,             
		regularHours = 40.0,                
		overtimeWages,                       
		overtimePayRate = 27.78,        
		overtimeHours = 10,                
		totalWages;                           
     
	regularWages = basePayRate * regularHours; 			  
	overtimeWages = overtimePayRate * overtimeHours;
	totalWages = regularWages + overtimeWages;
	cout << "Wages for this week are $" << totalWages << endl;
    return 0;
	} 
