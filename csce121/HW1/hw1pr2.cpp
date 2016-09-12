// Chris Comeaux 
// CSCE 121-501
// Due: September 15, 2015
// hw1pr2.cpp

#include "std_lib_facilities_4.h"

int main()
{
	
	//define varibles used in program
	double chord;
	const double DIAM = 14;
	double angle; // circle central angle
	const double RADIUS = 7;
	double seg_area;
	const double PI = 3.14159265358;
	double area = PI*(RADIUS*RADIUS);
	double ratio;
	double percent;

	cout<< "Pizza diameter is " <<DIAM <<"\".\n";
	cout<< "Please enter the length of the chord\n";
	while(cin>> chord)
	{
		// input validation
		while(chord > 14 || chord < 0)
		{
			cout<< "Please enter a mesurment less than 14 and greater than 0.\n";
			cin>>chord;
		}
			
		// compute angle
		angle = 2*asin((chord/(2*RADIUS))); // derived from http://mathworld.wolfram.com/CircularSegment.html
		
		// compute segment angle
		seg_area = (1.0/2)*(RADIUS*RADIUS)*(angle-(sin(angle))); //derived from http://mathworld.wolfram.com/CircularSegment.html
		
		// compute segment to cirle ratio
		ratio = (seg_area/area);
		
		// compute percent
		percent = ratio * 100;
		
		// round decimal
		percent = round(percent);
		
		cout<< "That cuts off " <<percent <<"% of the pizza\n";
		cout<< "Please enter the length of the chord or enter q to exit.\n";
	}
	
return 0;
}