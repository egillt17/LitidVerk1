#include "Toppings.h"

Toppings::Toppings() {
    _name = "";
    _price = 0;
}

Toppings::~Toppings() {
    //dtor
}

void Toppings::setName(string topping) {
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
    out << "Name: " << topping._name << " | " << "Price: " << topping._price << endl;
    return out;
}

ofstream& operator << (ofstream& out, const Toppings& topping) {
    out << "." << topping._name << "." << topping._price << endl;
    return out;
}
