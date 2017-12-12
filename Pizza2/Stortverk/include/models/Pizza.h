#ifndef PIZZA_H
#define PIZZA_H

#include "Toppings.h"

class Pizza
{
    public:
        Pizza();
        void setPrice(int price);
        ///Set function to set the price of a pizza with the integer that was sent to the function
        void setSize(string size_of);
        ///Set function to set the size with the string that was sent to the function
        void setSauce(string sauce);
        ///Set function to set the sauce with the string that was sent to the function
        void setCrust(string crust);
        ///Set function to set the crust with the string that was sent to the function
        void setStatus(char status);
        ///Set function to set the status of a pizza to the char that was sent to the function
        void addTopping(Toppings topping);
        ///add function that adds the topping that was sent to the function to the pizza
        void clearTopping();
        ///Clear function to clear the toppings on a pizza
        int getToppingPrice();
        ///Get function that returs the total price of toppings on a pizza
        int getPrice();
        ///Get function that returns the total price of a pizza
        vector <Toppings> getToppings();
        ///Get function that returns a vector of toppings on the pizza
        string getSize();
        ///Get function that returns the size of a pizza
        string getSauce();
        ///Get function that returns the sauce of a pizza
        string getCrust();
        ///Get function that returns the crust of a pizza
        char getStatus();
        ///Get function that returns the status of a pizza
        friend ostream& operator << (ostream& out, Pizza& pizza);
        ///Function that overloads the ostream operator
        friend ofstream& operator << (ofstream& out, Pizza& pizza);
        ///Function that overloads the ofstream operator to write to a text file

    private:
        int _price;
        vector <Toppings> _topping;
        string _size;
        string _sauce;
        string _crust;
        char _status;

};

#endif // PIZZA_H
