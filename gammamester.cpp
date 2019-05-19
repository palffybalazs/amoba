#include "graphics.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "widget.hpp"
#include "list.hpp"
#include "numeric.hpp"
#include "gammadraw.hpp"
#include "gammamester.hpp"
#include "gamma.hpp"
#include <vector>
#include <sstream>
#include <iostream>
#include <strstream>
using namespace std;
using namespace genv;


gammamester::gammamester()
{
    this->hanykellnyerni = 5;
}

vector<koord> gammamester::mostani_allas()
{
    return this->adat;
}

bool gammamester::free_to_click(int v, int f, bool kor)
{
    cout<<"gammamester vagyok "<<v<<" "<<f<<endl;
    bool once = true;
                for(int i = 0;i<this->adat.size(); i++)
                {
                    if(this->adat[i].f == f && this->adat[i].v == v)
                    {
                        once = false;
                    }
                }
    if (once)
    {
        koord tmp;
        tmp.v = v;
        tmp.f = f;
        tmp.kor = kor;
        this->adat.push_back(tmp);
    }
    return once;
}
bool gammamester::gameover()
{
    win = true;
    for (int i = 0;i<adat.size(); i++)
    {

            stepv = 1;
            stepv = 0;
            for (int h = 0; h<adat.size(); h++)
            {
                if(!(adat[h].v == adat[i+hossz*stepv].v &&
                   adat[h].f == adat[i+hossz*stepf].f &&
                   adat[h].f == adat[i+hossz*stepf].f))
            }
    }

    if(win)
    {
        cout<<"gyozelem"<<endl;
    }
    else
    {
        cout<<"mehet tovabb"<<endl;
    }
    return win;
}
