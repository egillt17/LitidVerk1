#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H

#include "Toppings.h"
#include "TopService.h"
#include <fstream>
#include <sstream>


class ToppingRepo
{
    public:
        vector<Toppings> ReadToppings(int pick);
        void addToppingToList(Toppings topping, int pick);
        void reWriteToppingList(vector <Toppings> topping, int pick);

    private:

};

#endif // TOPPINGREPO_H
