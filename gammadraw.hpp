#ifndef GAMMADRAW_HPP_INCLUDED
#define GAMMADRAW_HPP_INCLUDED
#include "widget.hpp"
#include "graphics.hpp"
#include "gammamester.hpp"
#include <vector>
using namespace genv;
class gammadraw : public Widget
{

        public:
        gammadraw();
        gammadraw(std::string szin, std::string szam, gammamester* logika);
        void draw();
        bool handle(genv::event ev, bool focused);
        std::string returnchosen();
        std::vector<koord>adat;
        std::vector<koord> vissza();
        bool kor = true;
        int x;
        int y;
        std::string szin;
        std::string szam;
        std::string szamlalo;
       // std::string returnchosen();
        bool focus = false;
};
#endif // NUMERIC_HPP_INCLUDED
