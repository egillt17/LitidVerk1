#include "Manager.h"

Manager::Manager()
{
    //ctor
}

Manager::~Manager()
{
    //dtor
}

Toppings Manager::managerAddToppings()
{
    Toppings toppings;  ///Create an instance of Toppings and the call a member function within that class, then Return the toppings variable.
    toppings.add_toppings();
    return toppings;
}

void Manager::managerPrintPizzas()
{
    ifstream fin;
    string st;
    int counter = 1;

    fin.open("AllPizzas.txt"); ///Check if AllPizzas is open and if it is then runs the commands below, else cout "Unable to open document".

    if(fin.is_open()){
        cout << "List of all Pizzas available" << endl;

        while(!fin.eof()){  ///Create a while loop that loops until the document ends, We have a counter running throught the whole program to make it easier to define each pizza
            cout << counter << ". ";
            getline(fin, st);
            cout << st << endl;
            counter++;
        }
    }
    else{
        cout << "Unable to open documment" << endl;
    }
}

void Manager::managerPrintToppings()
{
    ifstream fin;
    string st;
    int counter = 1;
    int meatCost = 50;
    int vegCost = 40;
    int cheeseCost = 30;    ///We dicided the pricing for the different categories of toppings.

        fin.open("Meat.txt");
        cout << endl;
        cout << "List of meat toppings: " << endl;

        if(fin.is_open()){ ///Checking if meat.txt is open

        while(!fin.eof()){  ///While the file meat.txt has not ended the while loop loops.
            cout << counter << ". ";
            getline(fin, st);
            cout << st << " " << meatCost << ".kr" << endl;
            counter++; ///This is the counter to make it easier to define each topping
        }
        fin.close();
        cout << endl;
        }
        else{
            cout << "Unable to open documment" << endl;
        }

        fin.open("Vegetables.txt");
        cout << "List of vegetable toppings: " << endl;

        if(fin.is_open()){  ///Checking if vegetables.txt is open

        while(!fin.eof()){  ///While the file vegetables.txt has not ended the while loop loops.
            cout << counter << ". ";
            getline(fin, st);
            cout << st << " " << vegCost << ".kr" << endl;
            counter++;  ///Counter
        }
        cout << endl;
        fin.close();
        }
        else{
            cout << "Unable to open documment" << endl;
        }

        fin.open("Cheese.txt");
        cout << "List of cheese toppings: " << endl;

        if(fin.is_open()){  ///If Cheese.txt is open then runs the commands below, if not the error message

        while(!fin.eof()){  ///While the file vegetables.txt has not ended the while loop loops.
            cout << counter << ". ";
            getline(fin, st);
            cout << st << " " << cheeseCost << ".kr" << endl;
            counter++;
        }
        fin.close();
        }
        else{
            cout << "Unable to open documment" << endl;
        }
}

