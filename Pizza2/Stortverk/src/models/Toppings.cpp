#include "Toppings.h"

Toppings::Toppings() {
    _topp.clear();
}

Toppings::~Toppings() {
    //dtor
}

void Toppings::add_topping(string topping) {
    _topp.push_back(topping);
}

void Toppings::clear_topping() {
    _topp.clear();
}
