#include "Toppings.h"

Toppings::Toppings() {                          ///Default constructor that resets all private variables
    _name = "";
    _price = 0;
}

void Toppings::setName(string topping) {            ///Get and set functions
    _name = topping;
}

void Toppings::setPrice(int price) {
    _price = price;
}

string Toppings::getName() {
    return _name;
}
int Toppings::getPrice() {
    return _price;
}

ostream& operator << (ostream& out, const Toppings& topping) {
    out << "Name: " << topping._name << " | " << "Price: " << topping._price << endl;   ///Ostream operator overload
    return out;
}

ofstream& operator << (ofstream& out, const Toppings& topping) {
    out << "." << topping._name << "." << topping._price << endl;                       ///Ofstream operator overload using '.' as a delimiter
    return out;
}
