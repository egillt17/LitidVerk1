#include "Toppings.h"

Toppings::Toppings()
{
    _amount = 0;
}

//this function prompts the toppings for the user
void Toppings::display_toppings(char input, int price, string& topping){
    ifstream fin;
    string st;
    int counter = 1;
    int number = 0;
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
    cout << "Pick a Topping: ";
    cin >> number;
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

Toppings Toppings::add_toppings(){
    Toppings make_pizza;
    string topping;
    int price = 0;
    char input = '0';
// here the user gets prompted with what topping choices he has
    while(input != 'q' || input != 'Q'){
        cout << "what kind of topping would you like to add?" << endl;
        cout << "Cheese = c | " << "Meat =  m | " << "Vegetables =  v | " << "Quit = q" << endl;
        cout << "picked toppings: ";
// in the for loop the toppings that the user has picked get printed out on the screen  for him to view
        for(unsigned int i = 0; i < make_pizza._name_of_topping.size(); i++){
            if(i == (make_pizza._name_of_topping.size()-1)){
                cout << make_pizza._name_of_topping[i] << " ";
            }
            else{
                cout << make_pizza._name_of_topping[i] << ", ";
            }
        }
// here the program prints out the total cost of all the toppings that the user has picked
        cout << endl << "Total amount: " << make_pizza._amount << endl;
        cout << "Type: ";
// here the user picks what kind of topping he wants to add or stop
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
// here the price gets added to the total amount
        make_pizza._amount += price;
// here the topping that the user picked gets added to the name of toppings list
// so that it can be printed out later
        make_pizza._name_of_topping.push_back(topping);
        system("CLS");
    }
    return make_pizza;
}

Toppings::~Toppings()
{
    //dtor
}
