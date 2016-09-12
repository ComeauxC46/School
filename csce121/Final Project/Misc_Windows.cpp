#include "Misc_Windows.h"

/*----------------------------------------------------------------------------------

SPLASH WINDOW IMPLEMENTATION*/

Splash_Window::Splash_Window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	names {Point{120,200},"Christopher Comeaux, Andrew Garcia, Tyler Creamer"},
	section {Point{210,150},"Group 26: CSCE 121-501"},
	Title {Point{150,100},"Flip Nation: A Pancake Game"},
	start_button {Point{530,0},70, 20, "Start",cb_start},
	Stack{Point{125,250},"stack.gif"}

	{
		Title.set_font_size(20);
		Title.set_font(FL_BOLD);
		names.set_font_size(15);
		names.set_font(FL_ITALIC);
		attach(names);
		attach(section);
		attach(Title);
		attach(start_button);
		attach(Stack);
	}

//**********************************************************************************************************************************
int Splash_Window::start() //closes the splash window and brings up the instructions
{
	hide();
	Instruction_Window win01(Point(100,100),600,600,"Flip Nation");
	return gui_main();
}

/*--------------------------------------------------------------------------------------------------------------

INSTRUCTION WINDOW IMPLEMENTATION*/	

Instruction_Window::Instruction_Window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	instructions {Point{220,60}, "INSTRUCTIONS!"},
	explnation0 {Point{40,100},"To start the game, choose a number of pancakes (colored ellipses)	from 2 to 9."},
	explnation1 {Point{40,130},"This is done by entering the difficulty in the box, labeled Difficulty, at the "},
	explnation2 {Point{40,160},"top of the screen. You play the game by inverting the stack of pancakes until"},
	explnation3 {Point{40,190}," they are in order from smallest to largest descending. To do this, press the "},
	explnation4 {Point{40,220},"'Flip' button next to the pancake you would like to flip. When the is stack ordered from"},
	explnation5 {Point{40,250},"smallest to largest descending, YOU WIN! The minimal number or flips, your current"},
	explnation6 {Point{40,280},"flip count, and your current total score will be displayed as you play. However, if you"},
	explnation7 {Point{40,310},"use too many flips you lose and must restart by adding a new difficulty. GOOD LUCK :)"},
	explnation8 {Point{40,340},"NOTE: The first button flips the top 2 pancakes, the second flips the top 3 ect."},
	Start_button{Point{530,0},70, 20, "Start",cb_Start}

	{
		instructions.set_font_size(20);
		instructions.set_font(FL_HELVETICA_BOLD);
		attach(instructions);
		attach(explnation0);
		attach(explnation1);
		attach(explnation2);
		attach(explnation3);
		attach(explnation4);
		attach(explnation5);
		attach(explnation6);
		attach(explnation7);
		attach(explnation8);
		attach(Start_button);
	}
	
//*************************************************************************************************************************************	
int Instruction_Window::Start()
{
	hide();
	Pancake_Window win{Point{100,100},650,650,"Pancakes"}; // closes the instructions and brings up the game window
	return gui_main();
}

