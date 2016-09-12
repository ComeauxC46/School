// Chris Comeaux 622006681
// Section 501
// Geometry Calculator

#include <iostream>        
using namespace std;

int main ()
{

	// Define constants
	const double PI = 3.14159; // hold the value for pi
	const int CIRC = 1,        // Holds choice to calculate area of circle
	          RECT = 2,        // Holds choice to calculate area of rectangle
	          TRIA = 3,        // Holds choice to calculate area of triangle
	          QUIT = 4;        // Holds choice quit program
	
	// Define veriables
	double r;      // Holds the radius of circle
	double length; // Holds the length of a rectangle
	double width;  // Holds the width of a rectangle
	double base;   // Holds the base of a triangle
	double height; // Holds the height of a triangle
	double Area;   // Holds the answer for Area
	int choice;    // Holds value of choice
	
	// create menu
	cout << "\t\tGeometry Calculator\n\n";
	cout << "\t1. Calculate the Area of a Circle\n";
	cout << "\t2. Calculate the Area of a Rectangle\n";
	cout << "\t3. Calculate the Area of a Triangle\n";
	cout << "\t4. Quit\n\n";
	cout << "Enter your choice (1-4):\n";
	cin >> choice;
	
	//Creat output
	switch (choice)
	{
		case CIRC: 
			cout <<"What is the radius of the circle?\n";
			cin >>r;
			Area = PI*(r*r); //calculate area using formula
			cout << "The area of the circle is " <<Area <<endl;
			break;
		
		case RECT:
			cout << "What is the length of the rectangle?\n";
			cin >> length;
			cout << "what is the width of the rectangle?\n";
			cin >> width;
			Area = width*length; //calculate area using formula
			cout << "The area of the rectangle is " <<Area <<endl;
			break;
		
		case TRIA:
			cout << "What is the length of the base?\n";
			cin >> base;
			cout << "What is the height of the triangle?\n";
			cin >> height;
			Area = base*height*0.5; //calculate area using formula
			cout << "The area of the triangle is " <<Area <<endl;
			break;
			
		case QUIT:
			cout<< "The program is ending...\n";
			break;
			
		default:
			cout << "Please restart the program and enter a valid number (1-4).\n";
	}
return 0;
}
			
					
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	