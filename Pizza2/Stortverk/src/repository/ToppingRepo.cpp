#include "ToppingRepo.h"

Toppings ToppingRepo::make_topping(string name, string price, int counter) {
    Toppings topping;
    int tempPrice = 0;
    stringstream sin(price);
    sin >> tempPrice;
    topping.set_topping(name);
    topping.set_price(tempPrice);

    return topping;
}

vector<Toppings> ToppingRepo::Read_toppings() {
    vector <Toppings> topping;
    Toppings test;
    int counter = 1;

    ifstream fin;
    string name = "";
    string price = "";

    fin.open("Toppings.txt");
    if(fin.is_open()) {
        while(!fin.eof()) {
            getline(fin, name, '.');
            if(name == ""){
                getline(fin, name, '.');
            }
            getline(fin, price, '.');
            topping.push_back(make_topping(name, price, counter));
            counter++;
        }
    }
    else {

    }

    for(unsigned int i = 0; i < topping.size(); i++) {
        cout << topping[i];
    }

    fin.close();
    return topping;
}
