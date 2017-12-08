#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H

#include "Toppings.h"
#include "TopService.h"
#include <fstream>
#include <sstream>


class ToppingRepo
{
    public:
        vector<Toppings> Read_toppings();
        void addToppingToList(Toppings topping);
        void reWriteToppingList(vector <Toppings> topping);

    private:
};

#endif // TOPPINGREPO_H
