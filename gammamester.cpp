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
    bool once = true;
    for(int i = 0; i<this->adat.size(); i++)
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
    string nyertesszin;
    vector<koord> iranyok;
    koord tmp;
    tmp.v = 1;
    tmp.f = 0;
    iranyok.push_back(tmp); //jobbra
    tmp.v = 1;
    tmp.f = 1;
    iranyok.push_back(tmp); //jobbra le
    tmp.v = 0;
    tmp.f = 1;
    iranyok.push_back(tmp); //le
    tmp.v = 1;
    tmp.f = -1;
    iranyok.push_back(tmp);  //jobbra fel

    for (int i = 0; i<adat.size(); i++) //minden letett jelbol indulva
    {
        for (int g = 0; g<iranyok.size(); g++) //minden iranyba (balra, fel, balra le, balra fel nem kell nezni, ugyanaz mint jobbra, le, jobbra le, stb.)
        {
            int stepv = iranyok[g].v;
            int stepf = iranyok[g].f;
            int hanyvanegysorban = 0;
            for (int tav = 0; tav<this->hanykellnyerni; tav++)
            {
                bool vanodarakva = false;
                for (int h = 0; h<adat.size(); h++)
                {
                    if((adat[h].v == adat[i].v + tav*stepv &&
                            adat[h].f == adat[i].f + tav*stepf &&
                            adat[h].kor == adat[i].kor))
                    {
                        vanodarakva = true;
                    }
                }
                if (vanodarakva)
                {
                    hanyvanegysorban++;
                }
            }
            if(hanyvanegysorban == this->hanykellnyerni)
            {
                this->win = true;
                if(adat[i].kor)
                {
                    this->nyertesszin = "haromszog jelu jatekos";
                }
                else
                {
                    this->nyertesszin = "x jelu jatekos";
                }
            }
        }
    }

    if(this->win)
    {
        cout<<"nyert a(z) "<<nyertesszin<<endl;
    }

    return this->win;
}
