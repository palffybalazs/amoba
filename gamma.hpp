#ifndef GAMMA_HPP_INCLUDED
#define GAMMA_HPP_INCLUDED
#include "graphics.hpp"
#include <vector>
using namespace genv;

class gamma
{
protected:
int x,y;
int sx,sy;
public:
    //Widget(int x, int y, int sx, int sy);
    //Widget();
    //virtual bool choosed(int mouse_x, int mouse_y);
  //virtual string choosen();
    virtual bool handle(genv::event ev, bool focused) = 0;



   // virtual void handle(genv::event ev) = 0;
};
#endif // GAMMA_HPP_INCLUDED
