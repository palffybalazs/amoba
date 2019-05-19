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

}
gammamester::gammamester(vector<koord>adat)
{
    this->adat = adat;
    this->win = win;
    this->fugg = fugg;
    this->viz = viz;
    this->counter = counter;
}

bool gammamester::handle(genv::event ev, bool focused)
{
    for(int i=0;i<adat.size();i++)
    {
    fugg = adat[i].f;
    viz = adat[i].v;
    for(int k =0;k<5;k++)
    {
     for(int j=0;j<adat.size();j++)
    {
     if(viz+k == adat[j].v && adat[i].kor==adat[j].kor)
     {
         counter++;
         cout<<counter<<endl;
     }
    }
    }
    }



return win;
}
