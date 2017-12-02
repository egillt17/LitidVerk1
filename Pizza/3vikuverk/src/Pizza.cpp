#include "Pizza.h"

Pizza::Pizza()
{
    _amount = 0;
    _size_of_pizza = "Not picked";
    _sauce = "Pizza sauce";
    _crust = "Reguler";
}

Pizza::~Pizza()
{
    //dtor
}

void Pizza::make_pizza(){
    Pizza pizza;
    Toppings add_toppings;
    char input = '0';
    int size_amount = 0;
    int top_amount = 0;
    string add;
    while(input != 'q' || input != 'Q'){
        cout << "what kind of topping would you like to add?" << endl;
        cout << "Size = i | " << "Sauce = s | " << "Toppings = t | " << "Pizza crust = c | " << "Quit = q" << endl;
        cout << "Picked toppings: " << pizza._topping_on_pizza;
        cout << "Picked size: " << pizza._size_of_pizza << endl;
        cout << "picked sauce: " << pizza._sauce << endl;
        cout << "picked crust: " << pizza._crust << endl;
        cout << "Pizza cost: " << pizza._amount << endl;

        cout << "Type: ";
        cin >> input;
        if(input == 'i' || input == 'I'){
            pizza.display_sizes(add, size_amount);
            pizza._amount = size_amount + top_amount;
            pizza._size_of_pizza = add;
        }
        else if(input == 's' || input == 'S'){
            pizza.display_sauce(add);
            pizza._sauce = add;
        }
        else if(input == 't' || input == 'T'){
            system("CLS");
            int amount_without_top = pizza._amount - top_amount;
            pizza._topping_on_pizza = add_toppings.add_toppings(amount_without_top, top_amount, pizza._topping_on_pizza);
            pizza._amount = size_amount + top_amount;
        }
        else if(input == 'c' || input == 'C'){
            pizza.display_crust(add);
            pizza._crust = add;
        }
        else if(input == 'q' || input == 'Q'){
            break;
        }
        else{
            cout << "Invalid input!" << endl;
        }
        system("CLS");
    }

}

void Pizza::display_sizes(string& add,int& amount){
    ifstream fin;
    string st;
    bool pick = true;
    int counter = 1;
    int number = 0;
    int price = 1000;
    fin.open("pizza_sizes.txt");
    if(fin.is_open()){
        cout << "List of Sizes" << endl;
        while(!fin.eof()){
            cout << counter << ". ";
            getline(fin, st);
            cout << st << " " << price << ".kr" << endl;
            price += 200;
            counter++;
        }
    }
    fin.close();
    while(pick == true){
        cout << "What size would you like: ";
        cin >> number;
        if(number > 0 && number < counter){
            pick = false;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }

    counter = 1;
    price = 1000;
    fin.open("pizza_sizes.txt");
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, st);
            if(counter == number){
                add = st;
                amount = price;
            }
            price += 200;
            counter++;
        }
    }
    fin.close();

}

void Pizza::display_sauce(string& add){
    ifstream fin;
    string st;
    bool pick = true;
    int counter = 1;
    int number = 0;
    fin.open("Sauce.txt");
    if(fin.is_open()){
        cout << "List of Sizes" << endl;
        while(!fin.eof()){
            cout << counter << ". ";
            getline(fin, st);
            cout << st << endl;
            counter++;
        }
    }
    fin.close();
    while(pick == true){
        cout << "What size would you like: ";
        cin >> number;
        if(number > 0 && number < counter){
            pick = false;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }

    counter = 1;
    fin.open("Sauce.txt");
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, st);
            if(counter == number){
                add = st;
            }
            counter++;
        }
    }
    fin.close();

}

void Pizza::display_crust(string& add){
    ifstream fin;
    string st;
    bool pick = true;
    int counter = 1;
    int number = 0;
    fin.open("Crust.txt");
    if(fin.is_open()){
        cout << "List of crust types" << endl;
        while(!fin.eof()){
            cout << counter << ". ";
            getline(fin, st);
            cout << st << endl;
            counter++;
        }
    }
    fin.close();
    while(pick == true){
        cout << "What kind of crust would you like: ";
        cin >> number;
        if(number > 0 && number < counter){
            pick = false;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }

    counter = 1;
    fin.open("Crust.txt");
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, st);
            if(counter == number){
                add = st;
            }
            counter++;
        }
    }
    fin.close();

}

