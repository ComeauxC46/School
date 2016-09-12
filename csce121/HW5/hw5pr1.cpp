// Chris Comeaux
// CSCE 121-510
// Due : October 18,2015
// Hw5pr1.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
	try 
	{
		if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",H112);
	  
		// object goint to represent the initials
		Lines C_first;
		Lines M_middle;
		Lines C_last;
		
		Simple_window win (Point(100,200),600,400,"Initials");
		
		//first letter
		C_first.add(Point(314,100),Point(284,100));
		C_first.add(Point(284,100),Point(284,150));
		C_first.add(Point(284,150),Point(314,150));
		win.attach(C_first);
		
		//second letter
		M_middle.add(Point(280,250),Point(284,200));
		M_middle.add(Point(284,200),Point(299,215));
		M_middle.add(Point(299,215),Point(314,200));
		M_middle.add(Point(314,200),Point(318,250));
		win.attach(M_middle);
		
		//last letter
		C_last.add(Point(314,300),Point(284,300));
		C_last.add(Point(284,300),Point(284,350));
		C_last.add(Point(284,350),Point(314,350));
		win.attach(C_last);
		
		
		win.wait_for_button();
		
		return 0;
	}
	
	catch(exception& e) 
	{
	cerr << "exception: " << e.what() << '\n';
	return 1;
	}
	catch (...) 
	{
		cerr << "Some exception\n";
		return 2;
	}