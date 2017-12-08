#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H

#include "Toppings.h"
#include <fstream>
#include <sstream>


class ToppingRepo
{
    public:
        Toppings make_topping(string st, string price, int counter);
        vector<Toppings> Read_toppings();

    private:
};

#endif // TOPPINGREPO_H
