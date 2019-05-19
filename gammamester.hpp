#ifndef GAMMAMESTER_HPP_INCLUDED
#define GAMMAMESTER_HPP_INCLUDED
#include "gamma.hpp"
#include "graphics.hpp"
#include <vector>
using namespace genv;

class gammamester : public gamma
{
    private:
    std::vector<koord>v;

    public:
        gammamester();
        gammamester(std::vector<koord>adat);
        bool free_to_click(int v, int f, bool kor);
        bool handle(genv::event ev, bool focused);
        std::vector<koord> mostani_allas();
        std::vector<koord>adat;
        bool win = false;
        int fugg;
        int viz;
        int counter;
};
#endif // NUMERIC_HPP_INCLUDED


