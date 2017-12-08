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
        void set_topping(string topping);
        void set_price(int price);
        friend ostream& operator << (ostream& out, const Toppings& topping);

    protected:

    private:
        string _topp;
        int _topPrice;
};

#endif // TOPPINGS_H
