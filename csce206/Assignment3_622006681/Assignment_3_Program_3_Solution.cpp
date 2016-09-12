// Chris Comeaux 622006681
// Section 501
// Functions

#include <iostream>
#include <cstdlib>
using namespace std;

double Add (int=11, int=21);
double Add (double, double);
double Add (short, short);
double Add (int, double);
double Add (double, int);
double Add (int, short);
double Add (short, int);
void exitFunction ();




int main ()
{
	int choice; // choice for menu
	int integer1; // holds value of integer input by user
	int integer2; // holds value of integer input by user
	char char1; // holds value of character input by user
	char char2; // holds value of character input by user
	double doub1; // holds value of float input by user
	double doub2; // holds value of float input by user
	double total; // holds the total value
	
	// Choice constants
	const int CHOICE_1 = 1;
	const int CHOICE_2 = 2;
	const int CHOICE_3 = 3;
	const int CHOICE_4 = 4;
	const int CHOICE_5 = 5;
	const int CHOICE_6 = 6;
	const int CHOICE_7 = 7;
	const int CHOICE_8 = 8;
	const int QUIT = 9;
	
	
	do
	{	
      cout << "\t Please select what type of data type you would like to add\n";
	  cout << "\t **********************************************************\n\n";
	  cout << "\t1. int,int\n";
	  cout << "\t2. float, float\n";
	  cout << "\t3. char, char\n";
	  cout << "\t4. int, float\n";
	  cout << "\t5. float, int\n";
	  cout << "\t6. int, char\n";
	  cout << "\t7. char, int\n";
	  cout << "\t8. Default arguments\n";
	  cout << "\t9. Exit\n\n";
	  cout << "Please choose a number between 1-9.\n";
	  cin >> choice;
	

		// use switch statement for the choices
		switch (choice)
		{	
		
			case CHOICE_1:
				cout << "Please enter an integer.\n";
				cin >> integer1;
				cout << "Please enter another integer.\n";
				cin >> integer2;
				total = Add (integer1, integer2);
				cout << "The answer is " <<total <<endl <<endl;
				break;
				
			case CHOICE_2:
				cout << "Please enter an float value.\n";
				cin >> doub1;
				cout << "Please enter another float value.\n";
				cin >> doub2;
				total = Add (doub1, doub2);
				cout << "The answer is " <<total <<endl <<endl;
				break;	
			
			case CHOICE_3:
				cout << "Please enter an character.\n";
				cin >> char1;
				cout << "Please enter another character.\n";
				cin >> char2;
				total = Add (char1, char2);
				cout << "The answer is " <<total <<endl <<endl;
				break;
				
			case CHOICE_4:
				cout << "Please enter an integer.\n";
				cin >> integer1;
				cout << "Please enter float value.\n";
				cin >> doub1;
				total = Add (integer1, doub1);
				cout << "The answer is " <<total <<endl <<endl;
				break;
				
			case CHOICE_5:
				cout << "Please enter an float value.\n";
				cin >> doub1;
				cout << "Please enter integer.\n";
				cin >> integer2;
				total = Add (doub1, integer2);
				cout << "The answer is " <<total <<endl <<endl;
				break;
				
			case CHOICE_6:
				cout << "Please enter an integer.\n";
				cin >> integer1;
				cout << "Please enter character.\n";
				cin >> char1;
				total = Add (integer1, char1);
				cout << "The answer is " <<total <<endl <<endl;
				break;
				
			case CHOICE_7:
				cout << "Please enter an character.\n";
				cin >> char1;
				cout << "Please enter integer.\n";
				cin >> integer2;
				total = Add (char1, integer2);
				cout << "The answer is " <<total <<endl <<endl;
				break;
			
			case CHOICE_8:
				total = Add ();
				cout << "The answer is " <<total <<endl <<endl;
				break;
				
			case QUIT:
				exitFunction();
				break;
				
			default :
				cout << "Please enter a valid choice (1-9)\n\n";
		}
	} while (choice != QUIT);
return 0;
}		
		
		
	// define the functions
	double Add (int param1, int param2)
	 {
		double total = param1 + param2;
		return total;
	 }
	
	double Add (double param1, double param2)
	 {
		double total = param1 + param2;
		return total;
	 }
	 
	double Add (char param1, char param2)
	 {
		double total = param1 + param2;
		return total;
	 }
	 
	double Add (int param1, double param2)
	 {
		double total = param1 + param2;
		return total;
	 }
	 
	double Add (double param1, int param2)
	 {
		double total = param1 + param2;
		return total;
	 } 
	 
	double Add (int param1, char param2)
	 {
		double total = param1 + param2;
		return total;
	 }
	double Add (char param1, int param2)
	 {
		double total = param1 + param2;
		return total;
	 }

	void exitFunction()
	{
		cout << "The program is ending\n";
		exit(0);
	}
		
		
		
		
		
		
		

	  
	  