#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"


int main()
{
	Simple_window win20 (Point(100,100),600,400,"color mixture");
	Vector_ref<Rectangle> rect;
	Rectangle x {Point{100,200},Point{200,300}};
	rect.push_back(x); // add named
	rect.push_back(new Rectangle{Point{50,60},Point{80,90}}); // add unnamed
	for (int i=0; i<rect.size(); ++i) rect[i].move(10,10); // use rect
	
	Vector_ref<Rectangle> vr;
	for (int i = 0; i<16; ++i)
	{
		for (int j = 0; j<16; ++j) 
		{
			vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
			vr[vr.size()-1].set_fill_color(Color{i*16+j});
			vr[vr.size()-1].set_color(Color::invisible);
			win20.attach(vr[vr.size()-1]);
			
		}
	}
win20.wait_for_button();
return 0;
}