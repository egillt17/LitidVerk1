#include "Pizza.h"

Pizza::Pizza() {
    _person = "";
    _price = 0;
    _topping.clear();
    _size = "";
    _sauce = "";
    _cheese = "";
    _crust = "";
    _status = 'n';
}

Pizza::~Pizza() {
    //dtor
}

void Pizza::set_person(string person) {
    _person = person;
}

void Pizza::set_price(int price) {
    _price = price;
}

void Pizza::set_size(string size_of) {
    _size = size_of;
}

void Pizza::set_sauce(string sauce) {
    _sauce = sauce;
}

void Pizza::set_cheese(string cheese) {
    _cheese = cheese;
}

void Pizza::set_crust(string crust) {
    _crust = crust;
}

void Pizza::set_status(char status) {
    _status = status;
}
