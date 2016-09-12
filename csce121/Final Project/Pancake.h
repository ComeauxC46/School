#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;
 
struct Pancake : Shape 
{
    Pancake(int width, int position); //constructor
    void draw_lines() const;
    void move(int dx, int dy);

    int len; int pos;
    Ellipse pan{Point{300,pos*40+150},len*20, 20};
};