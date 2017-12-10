#include "ToppingRepo.h"

vector<Toppings> ToppingRepo::ReadToppings(int pick) {
    vector <Toppings> topping;
    TopService get;

    ifstream fin;
    string name = "";
    string price = "";

    if(pick == 1) {
        fin.open("Toppings.txt");
    }
    else if(pick == 2) {
        fin.open("Crust.txt");
    }
    else if(pick == 3) {
        fin.open("Sizes.txt");
    }
    else if(pick == 4) {
        fin.open("Sauce.txt");
    }
    else if(pick == 5) {
        fin.open("Extra.txt");
    }

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

    fin.close();
    return topping;
}

void ToppingRepo::addToppingToList(Toppings topping, int pick) {
    ofstream fout;

    if(pick == 1) {
        fout.open("Toppings.txt");
    }
    else if(pick == 2) {
        fout.open("Crust.txt");
    }
    else if(pick == 3) {
        fout.open("Sizes.txt");
    }
    else if(pick == 4) {
        fout.open("Sauce.txt");
    }
    else if(pick == 5) {
        fout.open("Extra.txt");
    }

    if(fout.is_open()) {
        fout << topping;
    }
    else {

    }
    fout.close();
}

void ToppingRepo::reWriteToppingList(vector <Toppings> topping, int pick) {
    ofstream fout;

    if(pick == 1) {
        fout.open("Toppings.txt");
    }
    else if(pick == 2) {
        fout.open("Crust.txt");
    }
    else if(pick == 3) {
        fout.open("Sizes.txt");
    }
    else if(pick == 4) {
        fout.open("Sauce.txt");
    }
    else if(pick == 5) {
        fout.open("Extra.txt");
    }

    if(fout.is_open()) {
        for(unsigned int i = 0; i < topping.size(); i++) {
            fout << topping[i];
        }
    }
    else {

    }
    fout.close();
}

