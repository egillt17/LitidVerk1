#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <iostream>

using namespace std;

class Pizza
{
    public:
        Pizza();
        ~Pizza();
        void make_pizza();

    private:
        Toppings topping_on_pizza;
        int size_of_pizza;
        string sauce;

};

#endif // PIZZA_H
