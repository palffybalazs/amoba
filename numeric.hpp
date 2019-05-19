#ifndef NUMERIC_HPP_INCLUDED
#define NUMERIC_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
using namespace genv;
class numeric : public Widget
{
        private:
        std::vector<std::string> numbers;
        public:
        numeric();
        numeric(int x, int y,std::vector<std::string> numbers,int minimum,int maximum,int sx,int sy);
        void draw();
        bool handle(genv::event ev, bool focused);
        std::string returnchosen();
        std::vector<koord> vissza();
        int counter;
        int minimum;
        int maximum;
        std::string szamlalo;
        bool focus = false;
};
#endif // NUMERIC_HPP_INCLUDED
