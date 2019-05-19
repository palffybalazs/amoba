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

vector<koord> gammamester::mostani_allas()
{
    return this->adat;
}

bool gammamester::free_to_click(int v, int f, bool kor)
{
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
bool gammamester::handle(genv::event ev, bool focused)
{

return win;
}
