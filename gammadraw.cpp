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
int v=0;
int f=0;
bool loves = false;
bool once = false;
int meret;


gammadraw::gammadraw()
{

}
gammadraw::gammadraw(string szin, string szam, gammamester* logika)
{
    this->szam = szam;
    this->szin = szin;
    this->focus = false;
    this->negyzetmeret = 30;
    this->x=0;
    this->y=1;
    this->logika = logika;
    meret = stoi(szam);
}
void gammadraw::draw()
{

    for(int j=0; j<meret; j++)
    {

        for(int i=0; i<meret; i++)
        {
            x = i*this->negyzetmeret;
            gout<<color(255,0,0);
            gout<<move_to(x,j*this->negyzetmeret)<<box(this->negyzetmeret,this->negyzetmeret);
            gout<<color(0,0,0);
            gout<<move_to(x+2,j*this->negyzetmeret+2)<<box(27,27);
        }
    }
    vector<koord> mostani_allas = logika->mostani_allas();
    for(int f=0; f<mostani_allas.size(); f++)
    {
        if(loves && mostani_allas[f].kor == false)
        {
            if(szin == "kek") //ha kekkel vagyunk, ellenfel zold
            {
                gout<<color(0,255,0);
            }
            if(szin == "zold")
            {
                gout<<color(0,0,255);
            }
            gout<<move_to(mostani_allas[f].v*this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret);
            gout<<line_to(mostani_allas[f].v*this->negyzetmeret+this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret+this->negyzetmeret);
            gout<<move_to(mostani_allas[f].v*this->negyzetmeret+this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret);
            gout<<line_to(mostani_allas[f].v*this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret+this->negyzetmeret);

            //cout<<kor<<endl;
            //cout<<"nem kor";
        }
        if(loves && mostani_allas[f].kor == true)
        {
            if(szin == "kek")
            {
                gout<<color(0,0,255);
            }
            if(szin == "zold")
            {
                gout<<color(0,255,0);
            }
            cout<<mostani_allas[f].v<<" "<<mostani_allas[f].f<<endl;
            gout<<move_to(mostani_allas[f].v*this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret+this->negyzetmeret);
            gout<<line_to(mostani_allas[f].v*this->negyzetmeret+15,mostani_allas[f].f*this->negyzetmeret);
            gout<<line_to(mostani_allas[f].v*this->negyzetmeret+this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret+this->negyzetmeret);
            gout<<move_to(mostani_allas[f].v*this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret+this->negyzetmeret);
            gout<<line_to(mostani_allas[f].v*this->negyzetmeret+this->negyzetmeret,mostani_allas[f].f*this->negyzetmeret+this->negyzetmeret);
            //cout<<"kor";
            //cout<<kor<<endl;

        }
    }
}
string gammadraw::returnchosen()
{

}

bool gammadraw::handle(genv::event ev, bool focused)
{
    once = true;
    for(int k=0; k<=meret; k++)
    {
        for(int l=0; l<=meret; l++)
        {
            if(ev.pos_x>l*this->negyzetmeret &&
               ev.pos_x<l*this->negyzetmeret+this->negyzetmeret &&
               ev.pos_y>k*this->negyzetmeret && ev.pos_y<(k+1)*this->negyzetmeret &&
               ev.button==btn_left)
            {
                once = this->logika->free_to_click(l, k, kor);
                if(once)
                {
                    loves = true;
                    kor = !kor;
                }
                else
                {
                    cout<<"ROSSZ HELY";
                }
            }
        }
    }
}
