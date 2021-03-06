#include "Toppings.h"

Toppings::Toppings()
{
    //ctor
}

Toppings::~Toppings()
{
    //dtor
}

//this function prompts the toppings for the user
void Toppings::display_toppings(char input, int &price, string& topping){
    ifstream fin;
    string st;
    int counter = 1;
    char number_input = '0';
    int number = 0;
    bool pick = true;
//depending on what the user input the program opens the file that he asked for
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
// here the program promts the user the file that he asked for
    if(fin.is_open()){
        cout << "List of Toppings" << endl;
        cout << "Quit = q" << endl;

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
// here the user inputs the topping that he wants of the list
    while(pick == true){
        cout << "Pick a Topping: ";
        cin >> number_input;
        if(number_input == 'q' ||number_input == 'Q'){
            price = 0;
            topping = "";
            break;
        }
        number = number_input - '0';
        if(number > 0 && number < counter){
            pick = false;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }
    fin.close();
// in the code below im running through the file and adding the topping that the user
// picked to the topping variable so I can later add it to the name of topping vector
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

Toppings Toppings::add_toppings(int pizza_amount, int& topping_amount, Toppings pizza_top){
    Toppings make_pizza;
    make_pizza = pizza_top;
    string topping = "";
    int price = 0;
    char input = '0';
// here the user gets prompted with what topping choices he has
    while(input != 'q' || input != 'Q'){
        cout << "what kind of topping would you like to add?" << endl;
        cout << "Cheese = c | " << "Meat =  m | " << "Vegetables =  v | " << "Clear =  e | " << "Quit = q" << endl;
        cout << make_pizza;
        cout << "Pizza cost: " << pizza_amount + topping_amount << ".kr" << endl;
// here the user picks what kind of topping he wants to add or stop
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
        else if(input == 'E' || input == 'e'){
            make_pizza._name_of_topping.clear();
            topping_amount = 0;
        }
        if(input == 'M' || input == 'm' || input == 'V' || input == 'v' || input == 'C' || input == 'c'){
            display_toppings(input, price, topping);
            topping_amount += price;
            if(topping != ""){
                make_pizza._name_of_topping.push_back(topping);
            }
        }
        else if(input == 'q' || input == 'Q'){
            break;
        }
        else{
            cout << "Invalid input!" << endl;
        }
        system("CLS");
    }
    return make_pizza;
}

ostream& operator << (ostream& out, Toppings& top){
    out << "Toppings: ";
    for(unsigned int i = 0; i < top._name_of_topping.size(); i++){
            if(i == (top._name_of_topping.size()-1)){
                out << top._name_of_topping[i] << " ";
            }
            else{
                out << top._name_of_topping[i] << ", ";
            }
        }
        out << endl;
    return out;
}

