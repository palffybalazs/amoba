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
#include <cmath>
#include <iostream>

using namespace genv;
using namespace std;


mylist::mylist()
{

}
mylist::mylist(int x, int y, std::vector<std::string> options,int sx,int sy,int n)
{
    this->x = x;
    this->y = y;
    this->sx = sx;
    this->sy = sy;
    this->options = options;
    this->n = 2;
    this->start = 0;
    this->chosen = 1;
    this->focus = false;
    this->k = 0;
    this->hold = false;
    this->tmp = 1;
    this->offset = 0;
    this->teljeshossz = (n) * 20;
}
void mylist::draw()
{

    gout<<color(255,255,255);
    gout<<move_to(x,y)<<box(sx,sy);
    if(focus)
    {
        gout<<color(255,250,205);
        gout<<move_to(x,y)<<box(sx,sy);
    }
    gout<<color(0,0,200);
    gout<< move_to(x+sx-50,y)<<box(50,20);
    gout<<color(255,255,255);
    gout<< move_to(x+sx-45,y+12)<<text("press");
    gout<<color(0,0,0);
    gout<< move_to(x+20,y+12)<<text(options[0]);
    if(kint)
    {
        gout<< move_to(x+20,y+12)<<text(options[0]);
        gout<<color(255,255,255);
        gout<<move_to(x,y+20)<<box(sx-50,n*20);
        if(chosen != -1)
        {
            gout<<color(0,0,150);
            gout<<move_to(x,y+chosen*20)<<box(sx-70,20);
        }
        gout<<color(0,0,0);
        for(int i=start; i<start+n; i++)
        {
            gout<<color(0,0,0);
            gout<< move_to(x+20,y+32+(i-start)*20)<<text(options[i]);
        }


    }
}


string mylist::returnchosen()
{
    //cout<<"list: "<<this->start<<" "<<this->chosen<<" "<<options[this->start + this->chosen -1]<<" irtam am"<<endl;
    return this->options[this->start + this->chosen - 1]; //kivalasztom hogy melyiket adjuk vissza
}

bool mylist::handle(genv::event ev, bool focused)
{
    this->focus = focused; //beállítom amit kapok kintrõl
    if(ev.pos_x>x && ev.pos_x<x+sx && ev.pos_y>y && ev.pos_y<y+30 && ev.button==btn_left)
        {
            this->focus = true;
        }

    if(ev.pos_x>x+sx-50 && ev.pos_x<x+sx && ev.pos_y>y && ev.pos_y<y+20 && ev.button==btn_left)
    {
        kint = !kint;
    }

    if(ev.type==ev_key && kint==true && focus)
    {
        if(ev.keycode == key_down)
        {
                chosen++;
            if(chosen>n-1)
                {
                    chosen=n;
                    start++;
                }
                if(start>options.size()-n)
            {
                //cout<<"nagyobb";
                start=options.size()-n;
            }
             k = (start * (teljeshossz-10))/(options.size()-n);
//           k = k+n*20/options.size();
//           k=round(k);
//           cout<<k<<endl;
        }

        if(ev.keycode == key_up)
        {
            if(start<0)
                {
                start=0;
                //cout<<"kisebb";
                }


                chosen--;
            if(chosen<1)
                {
                    chosen=1;
                    if(start>0)
                    {
                        start--;
                        }
                }
                 k = (start * (teljeshossz-10))/(options.size()-n);
        }
    }
    if(kint== true && ev.pos_x>x && ev.pos_x<x+sx-70 && ev.pos_y>y+20 && ev.pos_y<y+(n+1)*20)
    {
        if(ev.button==btn_wheelup)
        {
            start--;
            if(start<0)
            {
                start=0;
                //cout<<"kisebb";
            }
            k = (start * (teljeshossz-10))/(options.size()-n);
        }
        if(ev.button==btn_wheeldown)
        {
            start++;
            if(start>options.size()-n)
            {
                //cout<<"nagyobb";
                start=options.size()-n;
            }
            k = (start * (teljeshossz-10))/(options.size()-n);

        }

    }
    for(int i=0; i<n+1; i++)
    {
        if( kint == true &&  ev.pos_x>x && ev.pos_x<x+sx-50 && ev.pos_y>y+i*20 && ev.pos_y<y+(i+1)*20 )
        {
            chosen = i;
        }
        if( kint == true &&  ev.pos_x>x && ev.pos_x<x+sx-70 && ev.pos_y>y+i*20 && ev.pos_y<y+(i+1)*20 && ev.button==btn_left )
        {
            chosen = i;
            if (chosen>0) //ha arra kattintok ami már ki van választva, hagyjuk
            {
                options[0] = options[start+chosen-1];
            }

            kint=false;
        }
    }

    //start = round((k/teljeshossz) * options.size());
    //cout<<start<<" "<<chosen<<" "<<teljeshossz<<" "<<options.size()<<" "<<k<<endl;
    //k = (start * (teljeshossz-10))/(options.size()-n-1);
    //cout<<start<<" "<<chosen<<" "<<teljeshossz<<" "<<options.size()<<" "<<k<<endl;
    return this->focus;
}
