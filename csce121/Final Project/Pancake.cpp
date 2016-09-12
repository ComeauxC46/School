#include"Pancake.h"

/*------------------------------------------------------------------------------------------
PANCAKE IMPLEMENTAION*/

Pancake::Pancake(int width, int position)
    :len{width}, pos{position}
{
    pan.set_fill_color(len); //setting colors and fills for each of the pancakes
    pan.set_color(Color::invisible);
}

//*************************************************************************************************************
void Pancake::draw_lines() const 
{
    pan.draw();
}

//*************************************************************************************************************
void Pancake::move(int dx, int dy) 
{
    pan.move(dx, dy);
}