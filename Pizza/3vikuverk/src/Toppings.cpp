#include "Toppings.h"

Toppings::Toppings()
{
    _amount = 0;
}

void Toppings::display_toppings(char input){
    ifstream fin;
    string st;
    int counter = 1;
    int number = 0;

    if(input == 'M' || input == 'm'){
        fin.open("Meat.txt");
    }
    else if(input == 'V' || input == 'v'){
        fin.open("Vegetables.txt");
    }
    else if(input ==  'C' || input == 'c'){
        fin.open("Cheese.txt");
    }
    else{
        cout << "ERROR!!!" << endl;
    }

    if(fin.is_open()){
        cout << "List of Toppings" << endl;

        while(!fin.eof()){
            cout << counter << ". ";
            getline(fin, st);
            cout << st << endl;
            counter++;
        }
    }
    else{
        cout << "Unable to open documment" << endl;
    }
    while(number < 1 || number >= counter){
            cout << "Please enter a number: ";
            cin >> number;
            if(number < 1 || number >= counter){
                cout << "Invalid input!" << endl;
            }
        }
    fin.close();
}

Toppings Toppings::add_toppings(){
    Toppings make_pizza;
    char input = '0';
    while(input != 'q' || input != 'Q'){
        cout << "what kind of topping would you like to add?" << endl;
        cout << "Cheese = c" << endl << "Meat =  m" << endl << "Vegetables =  v" << endl << "Quit = q" << endl;
        cout << "Type: ";
        cin >> input;
        if(input == 'q' || input == 'Q'){
            break;
        }
        make_pizza.display_toppings(input);
    }

    return make_pizza;
}

Toppings::~Toppings()
{
    //dtor
}
