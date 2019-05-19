#include "graphics.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "widget.hpp"
#include "list.hpp"
#include "numeric.hpp"
#include "gammadraw.hpp"
#include "gammamester.hpp"
#include <vector>
#include <sstream>
#include <iostream>
#include <strstream>
using namespace std;
using namespace genv;


numeric::numeric()
{

}
numeric::numeric(int x, int y,std::vector<std::string> numbers,int minimum,int maximum,int sx,int sy)
{
    this->x = x;
    this->y = y;
    this->sx = sx;
    this->sy = sy;
    this->numbers = numbers;
    this->counter=0;
    this->szamlalo;
    this->minimum = minimum;
    this->maximum = maximum;
    this->focus = false;

}
void numeric::draw()
    {
        gout<<color(255,255,255);
        gout<<move_to(x,y)<<box(sx,sy);
        if(focus)
        {
        gout<<color(255,250,205);
        gout<<move_to(x,y)<<box(sx,sy);
        gout<<color(255,255,255);
        }
        gout<<color(0,0,0);
        gout<<color(255,0,0);
        gout<<move_to(x+sx-40,y)<<box(40,sy/2);
        gout<<color(0,0,0);
        gout<<move_to(x+sx-25,y+7)<<box(10,1);
        gout<<move_to(x+sx-20,y+3)<<box(1,10);
        gout<<color(0,0,255);
        gout<<move_to(x+sx-40,y+15)<<box(40,15);
        gout<<color(0,0,0);
        gout<<move_to(x+sx-25,y+22)<<box(10,1);
        gout<<move_to(x+sx-66,y+18)<< text(to_string(counter));
    }

string numeric::returnchosen() // ez a függvény visszaadja az épp kiválasztott számot stringként ha kérik tõle
{
    return to_string(this->counter);
}


bool numeric::handle(genv::event ev, bool focused)
{
    this->focus = focused;
    if(ev.pos_x>x && ev.pos_x<x+sx && ev.pos_y>y && ev.pos_y<y+sy && ev.button==btn_left)
        {
            this->focus = true;
        }


    stringstream ss;
        if(ev.pos_x>x+sx-40 && ev.pos_x<x+sx && ev.pos_y>y && ev.pos_y<y+sy/2 && ev.button==btn_left)
        {
            counter++;
            numbers[0]=to_string(counter);
            //cout<<counter;
        }
//        if(focus == true && ev.button == btn_left && ev.pos_x<x || ev.pos_x>x+80 || ev.pos_y<y || ev.pos_y>y+30)
//        {
//            focus = false;
//
//        }
        if(ev.pos_x>x+40 && ev.pos_x<x+sx && ev.pos_y>y+sy/2 && ev.pos_y<y+sy && ev.button==btn_left)
        {
            counter--;
            numbers[0]=to_string(counter);
        }

        if(counter<=minimum)
        {
            counter=minimum;
        }
        if(counter>=maximum)
        {
            counter=maximum;
        }
        if(ev.keycode == key_up && focus == true)
        {
            counter++;
            numbers[0]=to_string(counter);
        }
        if(ev.keycode == key_pgup && focus == true)
        {
            counter = counter+10;
            numbers[0]=to_string(counter);
        }
        if(ev.keycode == key_down && focus == true)
        {
            counter--;
            numbers[0]=to_string(counter);
        }
        if(ev.keycode == key_pgdn && focus == true)
        {
            counter = counter-10;
            numbers[0]=to_string(counter);
        }
        return this->focus;
}
