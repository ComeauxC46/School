
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Point.h"
#include "Window.h"
#include "GUI.h"

int main(){ 
Simple_window win00(Point(0,0),600,600,"Flip Nation");

	Rectangle rect00{Point{0,0},600,600};
		rect00.set_fill_color(Color::white);
		
	Text go {Point{550,20},"Next->"};
		go.set_color(Color::green);
		
	Text names {Point{120,200},
	"Christopher Comeaux, Andrew Garcia, Tyler Creamer"};
	
	Text section {Point{260,150},"121-501"};
	
	Text tital {Point{190,100},"Flip Nation: A Pancake Game"};
	
win00.attach(rect00);
win00.attach(names);
win00.attach(go);
win00.attach(section);
win00.attach(tital);

win00.wait_for_button();

Simple_window win01(Point(0,0),600,600,"Flip Nation");
	
	Rectangle rect01{Point{0,0},600,600};
		rect01.set_fill_color(Color::white);
	
	Text explnation0 {Point{40,100},
"To start the game, choose a number of pancakes (colored ellipses)	from 3 to 9."};
	Text explnation1 {Point{40,130},
"This is done by entering the number in the box at the top of the screen."};
	Text explnation2 {Point{40,160},
"You play the game by inverting the stack of pancakes above and including"};
	Text explnation3 {Point{40,190},
"the pancake you select. This is done by choosing a pancake and clicking"};
	Text explnation4 {Point{40,220},
"the Flip button next to it. When you make the stack ordered from "};
	Text explnation5 {Point{40,250},
"smallest to largest descending, YOU WIN, and a score will be given after."};

		
	Text start {Point{550,20},"Start->"};
		start.set_color(Color::green);
		
win01.attach(rect01);
win01.attach(explnation0);
win01.attach(explnation1);
win01.attach(explnation2);
win01.attach(explnation3);
win01.attach(explnation4);
win01.attach(explnation5);

win01.attach(start);
	
win01.wait_for_button();

return 0;
}