#include "Pizza.h"

Pizza::Pizza() {
    _price = 0;
    _topping.clear();
    _size = "Not picked";
    _sauce = "Pizza sauce";
    _crust = "Regular crust";
    _status = 'n';
}

Pizza::~Pizza() {
    //dtor
}

void Pizza::setPrice(int price) {
    _price = price;
}

void Pizza::setSize(string size_of) {
    _size = size_of;
}

void Pizza::setSauce(string sauce) {
    _sauce = sauce;
}

void Pizza::setCrust(string crust) {
    _crust = crust;
}

void Pizza::setStatus(char status) {
    _status = status;
}

int Pizza::getPrice() {
    return _price;
}

vector <Toppings> Pizza::getToppings() {
    return _topping;
}

string Pizza::getSize() {
    return _size;
}

string Pizza::getSauce() {
    return _sauce;
}

string Pizza::getCrust() {
    return _crust;
}

char Pizza::getStatus() {
    return _status;
}

ostream& operator << (ostream& out, const Pizza& pizza) {
    out << "Price: " << pizza._price << endl;
    out << "Toppings: ";
    for(unsigned int i = 0; i < pizza._topping.size(); i++) {
        if(i == (pizza._topping.size()-1)) {
            out << pizza._topping[i] << endl;
        }
        else {
            out << pizza._topping[i] << ", ";
        }
    }
    out << "Size: " << pizza._size << endl;
    out << "Sauce: " << pizza._sauce << endl;
    out << "Crust: " << pizza._crust << endl;
    out << "Status: " << pizza._status << endl;
    return out;
}

ofstream& operator << (ofstream& out, const Pizza& pizza) {
    out << "." << pizza._price;
    out << "." << pizza._size;
    out << "." << pizza._sauce;
    out << "." << pizza._crust;
    out << "." << pizza._status << endl;
    for(unsigned int i = 0; i < pizza._topping.size(); i++) {
        if(i == (pizza._topping.size()-1)) {
            out << pizza._topping[i] << endl;
        }
        else {
            out << pizza._topping[i] << ", ";
        }
    }
    return out;
}
