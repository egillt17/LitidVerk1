#ifndef TOPSERVICE_H
#define TOPSERVICE_H

#include "Toppings.h"
#include "ToppingRepo.h"


class TopService
{
    public:
        vector <Toppings> getToppingList();
        void addTopping(string name, string price);
        Toppings make_topping(string st, string price);


    private:
        bool toppingCheck(Toppings topping);
};

#endif // TOPSERVICE_H
