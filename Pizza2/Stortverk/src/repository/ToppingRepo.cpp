#include "ToppingRepo.h"

vector<Toppings> ToppingRepo::Read_toppings() {
    vector <Toppings> topping;
    TopService get;

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
            topping.push_back(get.make_topping(name, price));
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

void ToppingRepo::addToppingToList(Toppings topping) {
    ofstream fout;
    fout.open("Toppings.txt", ios::app);
    if(fout.is_open()) {
        fout << topping;
    }
    else {

    }
    fout.close();
}

void ToppingRepo::reWriteToppingList(vector <Toppings> topping) {
    ofstream fout;
    fout.open("Toppings.txt");
    if(fout.is_open()) {
        for(unsigned int i = 0; i < topping.size(); i++) {
            fout << topping[i];
        }
    }
    else {

    }
    fout.close();
}

