#include "Toppings.h"

Toppings::Toppings()
{
    _price = 0;
}

void Toppings::display_toppings(){
    ifstream fin;
    string st;

    fin.open("Toppings.txt");
    if(fin.is_open()){
        cout << "List of Toppings" << endl;
        while(!fin.eof()){
            getline(fin, st);
            cout << st;
        }
    }

}

Toppings add_toppings(){
    Toppings make_pizza;
    char input;
    make_pizza.display_toppings();


    return make_pizza;
}

Toppings::~Toppings()
{
    //dtor
}
