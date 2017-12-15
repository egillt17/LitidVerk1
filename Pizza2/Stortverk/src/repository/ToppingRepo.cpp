#include "ToppingRepo.h"

vector<Toppings> ToppingRepo::ReadToppings(int pick) {
    vector <Toppings> topping;
    TopService get;

    ifstream fin;
    string name = "";
    string price = "";

    if(pick == 1) {             /// depending on what the pick was it will open different files
        fin.open("Toppings.txt");   /// opens the topping file
    }
    else if(pick == 2) {
        fin.open("Crust.txt");  /// opens the crust file
    }
    else if(pick == 3) {
        fin.open("Sizes.txt");  /// opens the size file
    }
    else if(pick == 4) {
        fin.open("Sauce.txt");  /// opens the sauce file
    }
    else if(pick == 5) {
        fin.open("Extra.txt");  /// opens the extras file
    }

    if(fin.is_open()) { /// checks if the file was successfully opened
        while(!fin.eof()) { /// goes through the entire file
            getline(fin, name, '.');    /// gets line and checks for delimiter
            if(name == ""){ /// checks if the line is empty
                getline(fin, name, '.');    /// if it is then it gets it again
            }
            getline(fin, price, '.');   /// gets price because it is alway written after the name
            topping.push_back(get.make_topping(name, price));   /// turns it into a topping variable and adds it to the vector
        }
    }
    else {

    }

    fin.close();    /// closes file
    return topping;
}

void ToppingRepo::addToppingToList(Toppings topping, int pick) {
    ofstream fout;

    if(pick == 1) {             /// depending on what the pick was it will open different files
        fout.open("Toppings.txt", ios::app);    /// opens topping file
    }
    else if(pick == 2) {
        fout.open("Crust.txt", ios::app);   /// opens crust file
    }
    else if(pick == 3) {
        fout.open("Sizes.txt", ios::app);   /// opens size file
    }
    else if(pick == 4) {
        fout.open("Sauce.txt", ios::app);   /// opens sauce file
    }
    else if(pick == 5) {
        fout.open("Extra.txt", ios::app);   /// opens extras file
    }

    if(fout.is_open()) {    /// checks if file was successfully opened
        fout << topping;    /// if it was then it adds the topping variable to the list
    }
    else {

    }
    fout.close();   /// closes the file
}

void ToppingRepo::reWriteToppingList(vector <Toppings> topping, int pick) {
    ofstream fout;

    if(pick == 1) {      /// depending on what the pick was it will open different files
        fout.open("Toppings.txt");  /// opens topping file
    }
    else if(pick == 2) {
        fout.open("Crust.txt"); /// opens crust file
    }
    else if(pick == 3) {
        fout.open("Sizes.txt"); /// opens size file
    }
    else if(pick == 4) {
        fout.open("Sauce.txt"); /// opens sauce file
    }
    else if(pick == 5) {
        fout.open("Extra.txt"); /// opens extras file
    }

    if(fout.is_open()) {    /// checks if the file was successfully opened
        for(unsigned int i = 0; i < topping.size(); i++) {  /// if it was then it goes through the topping vector
            fout << topping[i]; /// and rewrites it in the file
        }
    }
    else {

    }
    fout.close();   /// closes the file
}

