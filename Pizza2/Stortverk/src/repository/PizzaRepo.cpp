#include "PizzaRepo.h"

vector <string> PizzaRepo::readLocations() {
    vector <string> locations;
    string location;
    ifstream fin;
    fin.open("Locations.txt");  /// opens location file
    if(fin.is_open()) { /// checks if open
        while(getline(fin, location)) { /// gets all the info from the file
            locations.push_back(location);  /// adds it to the vector
        }
    }
    fin.close();    ///closes file
    return locations;   /// returns vector
}

void PizzaRepo::addLocationToList(string location) {
    ofstream fout;
    fout.open("Locations.txt", ios::app);   /// opens location file and adds to the end of it
    if(fout.is_open()) {    /// checks if its open
        fout << location << endl;   /// adds the location to the end of the file
    }
    else {

    }
    fout.close();   /// closes file
}

void PizzaRepo::reWriteLocationList(vector <string> locations) {
    ofstream fout;
    fout.open("Locations.txt"); /// opens location file
    if(fout.is_open()) {    /// checks if its open
        for(unsigned int i = 0; i < locations.size(); i++) {    /// goes through the vector with all the locations
            fout << locations[i] << endl;   /// and adds all the locations to the file
        }
    }
    else {

    }
    fout.close();   /// closes file
}

void PizzaRepo::addOrderToList(Order order) {
    ofstream fout;
    fout.open("Orders.txt", ios::app);  /// opens order file
    if(fout.is_open()) {    /// checks if its open
        fout << order;  /// adds the order at the end of the file
    }
    else {

    }
    fout.close();   /// close file
}

vector <Order> PizzaRepo::readOrders() {
    vector <Order> orders;
    Order tempOrder;
    PizzaService get;
    ifstream fin;
    string st;
    vector <string> info;
    fin.open("Orders.txt"); /// opens order file
    if(fin.is_open()) { /// checks if its open
        while(!fin.eof()) { /// loop runs til it reaches the end of the file
            getline(fin, st);   /// gets each line from the file
            if(st == ":") { /// checks for delimiter
                tempOrder = get.fixOrderInfo(info); /// sends the info to be fixed and then added to a temp order variable
                orders.push_back(tempOrder);    /// adds the fixed order variable to the order vector
                info.clear();   /// clears the vector that had the info
            }
            else {  /// if it doesnt find the delimiter then it adds to the info vector
                info.push_back(st);
            }
        }
    }
    fin.close();    /// closes file
    return orders;  /// returns the orders
}

void PizzaRepo::reWriteOrders(vector <Order> orders) {
    ofstream fout;
    fout.open("Orders.txt");    /// opens order file
    if(fout.is_open()) {    /// checks if open
        for(unsigned int i = 0; i < orders.size(); i++) {   /// goes through all the orders
            fout << orders[i];  /// and re writes the list with them
        }
    }
    else {

    }
    fout.close();   /// file closes
}

vector <string> PizzaRepo::readPizzaSpecials() {
    vector <string> info;
    ifstream fin;
    string st;
    fin.open("Pizza_specials.txt"); /// opens pizza specials file
    if(fin.is_open()) { /// checks if its open
        while(getline(fin, st)) {   /// loop runs while there are lines to take out
            info.push_back(st); /// adds the line to this vector
        }
    }
    fin.close();    /// closes file
    return info;
}

void PizzaRepo::addPizzaSpecial(Pizza pizza) {
    ofstream fout;
    fout.open("Pizza_specials.txt", ios::app);  /// opens pizza special file
    if(fout.is_open()) {    /// checks if its open
        fout << pizza;  /// adds the pizza at the end of the file
    }
    else {

    }
    fout.close();   /// closes the file
}

void PizzaRepo::reWritePizzaSpecial(vector <Pizza> pizzas) {
    ofstream fout;
    fout.open("Pizza_specials.txt");    /// opens the pizza specials file
    if(fout.is_open()) {    /// checks if its open
        for(unsigned int i = 0; i < pizzas.size(); i++) {   /// goes through all the pizzas
            fout << pizzas[i];  /// and re writes them in the file
        }
    }
    else {

    }
    fout.close();   /// file closes
}

