// Chris Comeaux 622006681
// Section 501
// Time Breaker

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	// Define constants
	const int MIN = 60.0;     // number of seconds in a minute
	const int HOURS = 3600.0; // number of seconds in an hour
	const int DAY = 86400.0;  // number of seconds in a day
	const int HPD = 24.0;     // number of hours in a day
	const int MPH = 60.0;     // number of minutes per hour
	
	// Define variables used for user input
	unsigned int sec; //hold number of seconds the user inputs
	
	// Define output variables
	int answer;     // hold number of minutes, hours, or days
	int remainder1; // holds first remainder
	int remainder2; // holds second remainder
	int remainder3; // holds third remainder
	
		// Definition of program and initial input
		cout << "Howdy! This program will convert the number \n";
		cout << "of seconds you enter into either minutes, hours, or days!\n";
		cout << "Please enter any amount of seconds\n";
		cin >> sec;
	
	
		// Define program output and conditions
		if (sec >= MIN)
			{
			  if (sec >= DAY)
			  { answer = sec/DAY;
			    remainder1 = (sec/HOURS)%HPD;
				remainder2 = (sec/MIN)%MPH;
				remainder3 = sec%MIN;
				cout <<answer <<" days, " <<remainder1 << " hours, " << remainder2 <<" minutes, " <<remainder3 <<" seconds\n";
			  }
			  else if (sec >= HOURS)
			  { answer = sec/HOURS;
				  remainder1 = (sec/MIN)%MPH;
				  remainder2 = sec%MIN;
				  cout <<answer <<" hours, " <<remainder1 << " minutes " <<remainder2 <<" seconds\n";
			  }
			  else if (sec >= MIN)
			  { answer = sec/MIN;
				  remainder1 = sec%MIN;
				  cout <<answer <<" minutes, " <<remainder1 << " seconds\n";
			  }
			} 
		else 
			cout <<sec <<" seconds\n";
			
return 0;
}
	