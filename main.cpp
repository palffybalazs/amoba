#include "graphics.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include "widget.hpp"
#include "list.hpp"
#include "numeric.hpp"
#include "gammadraw.hpp"
#include "gammamester.hpp"
#include <iostream>
#include <fstream>
using namespace genv;
using namespace std;
const double XX=900;
const double YY=900;
int main()
{
    bool mehet = false;
    string szin;
    string szam;
    gout.open(XX,YY);
    event ev;
    vector<Widget*> w;
    vector<string> options;
    vector<string> numbers;
    vector<koord>adatok;
    string szoveg;
    string szoveg2;
    string a = "15";
    numbers.push_back(a);
    options.push_back(a);
    vector<string> options2;
    string p="zold";
    string k="kek";
    options2.push_back(p);
    options2.push_back(k);
    Widget* w1 = new mylist(300,1,options2,300,20,3);
    Widget* w2 = new numeric(1,1,numbers,15,30,80,30);
    w.push_back(w1);
    w.push_back(w2);
    int fokuszalt_szama = 0;
    gammamester* logika;

    while(gin >> ev)
    {
        gout<<color(0,0,0);
        gout<<move_to(0,0)<<box(XX,YY);
        if(mehet == false)
        {
             for(int i=0; i<w.size(); i++)
        {
            bool ezvanfokuszban = (i == fokuszalt_szama); //ha i = a fokuszalttal, akkor odaadom a handlenek
            bool ker_fokuszt = w[i]->handle(ev, ezvanfokuszban);

            if (ker_fokuszt)
            {
                fokuszalt_szama = i; //ha a handle true-t ad vissza, bele lett kattintva, akkor legyen i a kivalasztott
            }
            w[i]->draw();
            szin = w[0]->returnchosen();
            szam = w[1]->returnchosen();
        }
        if(ev.keycode==key_tab)
        {
            fokuszalt_szama = (fokuszalt_szama + 1)%w.size(); //tabra n�velem a kiv�lasztott sz�m�t, ha t�l nagy, vissza null�ra moddal
        }
            gout<<color(255,255,255);
            gout<<move_to(240,100)<<box(120,20);
            gout<<color(0,0,0);
            gout<<move_to(280,113)<<text("Mehet");
            if(ev.pos_x>240 && ev.pos_x<360 && ev.pos_y>100 && ev.pos_y<120 && ev.buttot)
            {
                logika = new gammamester(); //game logic started
                mehet = true;
                Widget* w3 = new gammadraw(szin, szam, logika);
                w.push_back(w3);
            }
        }
        else // ha mar megy a jatek
        {
            bool kappa = true;
            w[2]->draw();
            w[2]->handle(ev,kappa);
        }
        gout<<refresh;
    }
    return 0;
}
