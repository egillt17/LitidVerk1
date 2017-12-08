#ifndef TOPPINGS_H
#define TOPPINGS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Toppings
{
    public:
        Toppings();
        virtual ~Toppings();
        void setName(string topping);
        void setPrice(int price);
        string getName();
        int getPrice();
        friend ostream& operator << (ostream& out, const Toppings& topping);
        friend ofstream& operator << (ofstream& out, const Toppings& topping);

    protected:

    private:
        string _name;
        int _price;
};

#endif // TOPPINGS_H
