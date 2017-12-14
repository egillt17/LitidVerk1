#include "PizzaRepo.h"

vector <string> PizzaRepo::readLocations() {
    vector <string> locations;
    string location;
    ifstream fin;
    fin.open("Locations.txt");
    if(fin.is_open()) {
        while(getline(fin, location)) {
            locations.push_back(location);
        }
    }
    fin.close();
    return locations;
}

void PizzaRepo::addLocationToList(string location) {
    ofstream fout;
    fout.open("Locations.txt", ios::app);
    if(fout.is_open()) {
        fout << location << endl;
    }
    else {

    }
    fout.close();
}

void PizzaRepo::reWriteLocationList(vector <string> locations) {
    ofstream fout;
    fout.open("Locations.txt");
    if(fout.is_open()) {
        for(unsigned int i = 0; i < locations.size(); i++) {
            fout << locations[i] << endl;
        }
    }
    else {

    }
    fout.close();
}

void PizzaRepo::addOrderToList(Order order) {
    ofstream fout;
    fout.open("Orders.txt", ios::app);
    if(fout.is_open()) {
        fout << order;
    }
    else {

    }
    fout.close();
}

vector <Order> PizzaRepo::readOrders() {
    vector <Order> orders;
    Order tempOrder;
    PizzaService get;
    ifstream fin;
    string st;
    vector <string> info;
    fin.open("Orders.txt");
    if(fin.is_open()) {
        while(!fin.eof()) {
            getline(fin, st);
            if(st == ":") {
                tempOrder = get.fixOrderInfo(info);
                orders.push_back(tempOrder);
                info.clear();
            }
            else {
                info.push_back(st);
            }
        }
    }
    fin.close();
    return orders;
}

void PizzaRepo::reWriteOrders(vector <Order> orders) {
    ofstream fout;
    fout.open("Orders.txt");
    if(fout.is_open()) {
        for(unsigned int i = 0; i < orders.size(); i++) {
            fout << orders[i];
        }
    }
    else {

    }
    fout.close();
}

vector <string> PizzaRepo::readPizzaSpecials() {
    vector <string> info;
    ifstream fin;
    string st;
    fin.open("Pizza_specials.txt");
    if(fin.is_open()) {
        while(getline(fin, st)) {
            info.push_back(st);
        }
    }
    fin.close();
    return info;
}

void PizzaRepo::addPizzaSpecial(Pizza pizza) {
    ofstream fout;
    fout.open("Pizza_specials.txt", ios::app);
    if(fout.is_open()) {
        fout << pizza;
    }
    else {

    }
    fout.close();
}

void PizzaRepo::reWritePizzaSpecial(vector <Pizza> pizzas) {
    ofstream fout;
    fout.open("Pizza_specials.txt");
    if(fout.is_open()) {
        for(unsigned int i = 0; i < pizzas.size(); i++) {
            fout << pizzas[i];
        }
    }
    else {

    }
    fout.close();
}

