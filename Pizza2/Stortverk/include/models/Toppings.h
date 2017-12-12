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
        ///Default constructor
        void setName(string topping);
        ///Set function that sets the name of the topping with the string that was sent to the function
        void setPrice(int price);
        ///Set function that sets the price of the topping with the int that was sent to the function
        string getName();
        ///Get function that returns the name of the topping
        int getPrice();
        ///Get function that returns the price of the topping
        friend ostream& operator << (ostream& out, const Toppings& topping);
        ///Function that overloads the ostream operator
        friend ofstream& operator << (ofstream& out, const Toppings& topping);
        ///Function that overloads the ofstream operator to write to a text file

    protected:

    private:
        string _name;
        int _price;
};

#endif // TOPPINGS_H
