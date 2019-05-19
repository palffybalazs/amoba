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
gammadraw::gammadraw(string szin, string szam)
{
    this->szam = szam;
    this->szin = szin;
    this->focus = false;
    int x=0;
    int y=1;
    this-> adat = adat;
    meret = stoi(szam);
}
void gammadraw::draw()
{

    for(int j=0;j<meret;j++)
    {

        for(int i=0;i<meret;i++)
    {
        x = i*30;
        gout<<color(255,0,0);
        gout<<move_to(x,j*30)<<box(30,30);
        gout<<color(0,0,0);
        gout<<move_to(x+2,j*30+2)<<box(27,27);
    }
    }
    for(int f=0;f<adat.size();f++)
    {
        if(loves && adat[f].kor == false)
    {
        if(szin == "kek")
        {
          gout<<color(0,255,0);
        }
        if(szin == "zold")
        {
          gout<<color(0,0,255);
        }
        gout<<move_to(adat[f].v*30,adat[f].f*30);
        gout<<line_to(adat[f].v*30+30,adat[f].f*30+30);
        gout<<move_to(adat[f].v*30+30,adat[f].f*30);
        gout<<line_to(adat[f].v*30,adat[f].f*30+30);

        //cout<<kor<<endl;
        //cout<<"nem kor";
    }
    if(loves && adat[f].kor == true)
    {
        if(szin == "kek")
        {
          gout<<color(0,0,255);
        }
        if(szin == "zold")
        {
          gout<<color(0,255,0);
        }
        gout<<move_to(adat[f].v*30,adat[f].f*30+30);
        gout<<line_to(adat[f].v*30+15,adat[f].f*30);
        gout<<line_to(adat[f].v*30+30,adat[f].f*30+30);
        gout<<move_to(adat[f].v*30,adat[f].f*30+30);
        gout<<line_to(adat[f].v*30+30,adat[f].f*30+30);
        //cout<<"kor";
        //cout<<kor<<endl;

    }
    }
}
string gammadraw::returnchosen() // ez a függvény visszaadja az épp kiválasztott számot stringként ha kérik tõle
{

}
vector<koord> gammadraw::vissza()
{
    return adat;
}
bool gammadraw::handle(genv::event ev, bool focused)
{
    once = true;
    for(int k=0;k<=meret;k++)
    {
        for(int l=0;l<=meret;l++)
        {
            if(ev.pos_x>l*30 && ev.pos_x<l*30+30 && ev.pos_y>k*30 && ev.pos_y<(k+1)*30 && ev.button==btn_left)
            {
                koord tmp;
                v = l*30;
                f = k*30;
                for(int i = 0;i<adat.size();i++)
                {
                       if(adat[i].f == k && adat[i].v == l)
                    {
                        once = false;;
                    }

                }
                if(once)
                {
                tmp.v = l;
                tmp.f = k;
                tmp.kor = kor;
                adat.push_back(tmp);
                loves = true;
                 if(kor==true)
                {
                    kor = false;
                }
                else
                {
                    kor = true;
                }
                }


                //cout<<kor<<endl;

                //cout<<kor<<endl;
            }
        }
    }
}
