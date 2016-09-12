#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib
{

struct Light_bulb : Simple_window
{
	Light_bulb (Point xy, int w, int h, const string& title);
	Circle circle;
	
private:
	Button button_on_off;
	void on_off();
	static void cb_on_off(Address,Address pw);
	bool light_on = false;
};
}

	Light_bulb::Light_bulb(Point xy, int w, int h, const string& title)
	: Simple_window(xy,w,h,title),
	button_on_off{Point{800 - 70,0}, 70,20,"ON/OFF", cb_on_off},
	circle {Point{400,400}, 100}
	{
		attach(button_on_off);
		attach(circle);
	}
	
void Light_bulb:: on_off()
{
	light_on = !light_on;
	if(light_on)
		circle.set_fill_color(Color::yellow);
	else
		circle.set_fill_color(Color::invisible);
	
	redraw();
}

void Light_bulb :: cb_on_off(Address, Address pw)
{
	reference_to<Light_bulb>(pw).on_off();
}
	
	
int main()
{
	Light_bulb win (Point{100,100},800,800,"LIGHT!");
	return gui_main();
}