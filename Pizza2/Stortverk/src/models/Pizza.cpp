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

void Pizza::addTopping(Toppings topping) {
    _topping.push_back(topping);
}
void Pizza::clearTopping() {
    _topping.clear();
}

int Pizza::getToppingPrice() {
    int totalPrice = 0;
    for(unsigned int i = 0; i < _topping.size(); i++) {
        totalPrice += _topping[i].getPrice();
    }
    return totalPrice;
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

ostream& operator << (ostream& out, Pizza& pizza) {
    out << "Price: " << pizza._price << endl;
    out << "Toppings: ";
    if(pizza._topping.empty()) {
        out << endl;
    }
    else {
        for(unsigned int i = 0; i < pizza._topping.size(); i++) {
            if(i == (pizza._topping.size()-1)) {
                out << pizza._topping[i].getName() << endl;
            }
            else {
                out << pizza._topping[i].getName() << ", ";
            }
        }
    }
    out << "Size: " << pizza._size << endl;
    out << "Sauce: " << pizza._sauce << endl;
    out << "Crust: " << pizza._crust << endl;
    out << "Status: " << pizza._status << endl;
    return out;
}

ofstream& operator << (ofstream& out, Pizza& pizza) {
    out << "^" << pizza._price;
    out << "^" << pizza._size;
    out << "^" << pizza._sauce;
    out << "^" << pizza._crust;
    out << "^" << pizza._status << "^" << endl;
    if(pizza._topping.empty()) {
        out << "^" << "No toppings";
    }
    else {
        for(unsigned int i = 0; i < pizza._topping.size(); i++) {
            out << "^" << pizza._topping[i].getName();
        }
    }
    out << "^" << endl;
    return out;
}
