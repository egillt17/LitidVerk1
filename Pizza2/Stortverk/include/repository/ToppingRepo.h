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
        /// reads a topping list the pick is for which list it will open
        void addToppingToList(Toppings topping, int pick);
        /// adds a topping to the list and the pick is  for which list it will be added too
        void reWriteToppingList(vector <Toppings> topping, int pick);
        /// rewrites topping list the pick is for which list it will rewrite

    private:

};

#endif // TOPPINGREPO_H
