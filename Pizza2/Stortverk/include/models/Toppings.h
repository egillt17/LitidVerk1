#ifndef TOPPINGS_H
#define TOPPINGS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Toppings
{
    public:
        Toppings();
        virtual ~Toppings();
        void add_topping(string topping);
        void clear_topping();

    protected:

    private:
        vector <string> _topp;
};

#endif // TOPPINGS_H
