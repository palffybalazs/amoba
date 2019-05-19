#ifndef GAMMAMESTER_HPP_INCLUDED
#define GAMMAMESTER_HPP_INCLUDED
#include "gamma.hpp"
#include "graphics.hpp"
#include <vector>
using namespace genv;

class gammamester
{
    private:
    std::vector<koord>v;

    public:
        gammamester();
        bool free_to_click(int v, int f, bool kor);
        bool gameover();
        int hanykellnyerni;
        std::vector<koord> mostani_allas();
        std::vector<koord> adat;
        bool win = false;
        int fugg;
        int viz;
        int counter;
};
#endif // NUMERIC_HPP_INCLUDED


