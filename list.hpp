#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include <vector>

class mylist : public Widget
{
    private:
        std::vector<std::string> options;
    public:
        mylist();
        mylist(int x, int y, std::vector<std::string> options,int sx,int sy,int n);
        void draw();
        bool handle(genv::event ev, bool focused);
        std::string returnchosen();
        std::vector<koord> vissza();
        bool kint = false;
        int n;
        int start;
        int chosen;
        bool focus = false;
        double k = 1;
        bool hold = false;
        double tmp = 1;
        int teljeshossz;
        int offset;
};

#endif // LIST_HPP_INCLUDED
