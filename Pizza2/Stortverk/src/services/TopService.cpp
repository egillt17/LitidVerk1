#include "TopService.h"

vector <Toppings> TopService::getToppingList(int pick) {
   vector <Toppings> toppingList;
   toppingList.clear();
   ToppingRepo get;
   toppingList = get.ReadToppings(pick);

    return toppingList;
}

void TopService::addTopping(string name, string price, int pick) {
    Toppings topping;
    ToppingRepo get;
    topping = make_topping(name, price);

    if(!toppingCheck(topping, pick)) {
        get.addToppingToList(topping, pick);
    }

}

bool TopService::removeTopping(string name, int pick) {
    vector <Toppings> toppingList;
    ToppingRepo get;
    toppingList = getToppingList(pick);

    for(unsigned int i = 0; i < toppingList.size(); i++) {
        if(!name.compare(toppingList[i].getName())) {
            toppingList.erase (toppingList.begin()+i);
            get.reWriteToppingList(toppingList, pick);
            return true;
        }

    }
    return false;
}

Toppings TopService::make_topping(string name, string price) {
    Toppings topping;
    int tempPrice = 0;
    stringstream sin(price);
    sin >> tempPrice;
    topping.setName(name);
    topping.setPrice(tempPrice);

    return topping;
}

bool TopService::toppingCheck(Toppings topping, int pick) {
    vector <Toppings> toppingList;
    ToppingRepo get;
    toppingList = getToppingList(pick);

    for(unsigned int i = 0; i < toppingList.size(); i++) {
        if(topping.getName().compare(toppingList[i].getName())) {
            toppingList[i] = topping;
            get.reWriteToppingList(toppingList, pick);
            return true;
        }

    }

    return false;
}
