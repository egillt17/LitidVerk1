#include "Toppings.h"

Toppings::Toppings() {
    _topp = "";
    _topPrice = 0;
}

Toppings::~Toppings() {
    //dtor
}

void Toppings::set_topping(string topping) {
    _topp = topping;
}

void Toppings::set_price(int price) {
    _topPrice = price;
}

ostream& operator << (ostream& out, const Toppings& topping) {
    out << "Name: " << topping._topp << endl;
    out << "Price: " << topping._topPrice << endl;
    return out;
}
