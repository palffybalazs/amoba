#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include <vector>
using namespace genv;
struct koord
{
    int v;
    int f;
    bool kor;
};
class Widget
{
protected:
int x,y;
int sx,sy;
public:
    //Widget(int x, int y, int sx, int sy);
    //Widget();
    //virtual bool choosed(int mouse_x, int mouse_y);
  //virtual string choosen();
    virtual void draw() = 0;
    virtual bool handle(genv::event ev, bool focused) = 0;
    virtual std::string returnchosen() = 0;

   // virtual void handle(genv::event ev) = 0;
};


#endif // WIDGET_HPP_INCLUDED
