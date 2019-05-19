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
        void negyzetracsrajzolo();
        void lepesrajzolo();
        void xrajzolo(koord actjelzes);
        void haromszograjzolo(koord actjelzes);
        std::string returnchosen();
        std::vector<koord>adat;
        bool kor = true;
        gammamester* logika;
        int x;
        int y;
        std::string szin;
        std::string szam;
        std::string szamlalo;
        int negyzetmeret;
        bool focus = false;
        bool vege = false;
};
#endif // NUMERIC_HPP_INCLUDED
