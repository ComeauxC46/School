#include "PancakeWin.h"

struct Splash_Window : Graph_lib::Window
{
	Splash_Window(Point xy, int w, int h, const string& title);
	
private:
	Text names; 
	Text section;
	Text Title;
	Image Stack;
	
	Button start_button;
	
	int start(); // go to the intructional screen
	
	static void cb_start (Address, Address pw) {reference_to<Splash_Window>(pw).start();};
};


struct Instruction_Window : Graph_lib::Window
{
	Instruction_Window(Point xy, int w, int h, const string& title);
private:
	Text instructions;
	Text explnation0;
	Text explnation1;
	Text explnation2;
	Text explnation3;
	Text explnation4;
	Text explnation5;
	Text explnation6;
	Text explnation7;
	Text explnation8;
	
	Button Start_button; // start the game
	
	int Start();
	
	static void cb_Start (Address, Address pw) {reference_to<Instruction_Window>(pw).Start();};
};

