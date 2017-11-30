#include "Toppings.h"

Toppings::Toppings()
{
    _amount = 0;
}

void Toppings::display_toppings(char input, int price, string& topping){
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
        cout << "Invalid input!" << endl;
    }

    if(fin.is_open()){
        cout << "List of Toppings" << endl;

        while(!fin.eof()){
            cout << counter << ". ";
            getline(fin, st);
            cout << st << " " << price << ".kr" << endl;
            counter++;
        }
    }
    else{
        cout << "Unable to open documment" << endl;
    }
    cout << "Pick a Topping: ";
    cin >> number;
    fin.close();
    counter = 1;
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
        cout << "Invalid input!" << endl;
    }
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, st);
            if(counter == number){
                topping = st;
            }
            counter++;
        }
    }
    fin.close();
}

Toppings Toppings::add_toppings(){
    Toppings make_pizza;
    string topping;
    int price = 0;
    char input = '0';

    while(input != 'q' || input != 'Q'){
        cout << "what kind of topping would you like to add?" << endl;
        cout << "Cheese = c | " << "Meat =  m | " << "Vegetables =  v | " << "Quit = q" << endl;
        cout << "picked toppings: ";
        for(unsigned int i = 0; i < make_pizza._name_of_topping.size(); i++){
            if(i == (make_pizza._name_of_topping.size()-1)){
                cout << make_pizza._name_of_topping[i] << " ";
            }
            else{
                cout << make_pizza._name_of_topping[i] << ", ";
            }
        }
        cout << endl << "Total amount: " << make_pizza._amount << endl;
        cout << "Type: ";
        cin >> input;
        if(input == 'M' || input == 'm'){
            price = 50;
        }
        else if(input == 'V' || input == 'v'){
            price = 40;
        }
        else if(input == 'C' || input == 'c'){
            price = 30;
        }
        if(input == 'M' || input == 'm' || input == 'V' || input == 'v' || input == 'C' || input == 'c'){
            display_toppings(input, price, topping);
        }
        else if(input == 'q' || input == 'Q'){
            break;
        }
        else{
            cout << "Invalid input!" << endl;
        }
        make_pizza._amount += price;
        make_pizza._name_of_topping.push_back(topping);
        system("CLS");
    }
    for(unsigned int i = 0; i < make_pizza._name_of_topping.size(); i++){
        if(i == (make_pizza._name_of_topping.size()-1)){
           cout << make_pizza._name_of_topping[i] << " ";
        }
        else{
            cout << make_pizza._name_of_topping[i] << ", ";
        }
    }
    cout << endl << "Total amount: " << make_pizza._amount;
    return make_pizza;
}

Toppings::~Toppings()
{
    //dtor
}
