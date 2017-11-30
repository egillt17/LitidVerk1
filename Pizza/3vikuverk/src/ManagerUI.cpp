#include "ManagerUI.h"
#include "Display.h"
#include "Manager.h"
#include "Toppings.h"

ManagerUI::ManagerUI()
{
    //ctor
}

ManagerUI::~ManagerUI()
{
    //dtor
}

void ManagerUI::displayManagerUI()
{
    char answer = ' ';

    while (answer != 'q' || answer == 'Q')
    {
        cout << endl << "Hello Manager!" << endl;
        cout << "What would you like to do? " << endl;
        cout << "'a' to add a new pizza " << endl << "'b' to add a new topping " << endl << "'c' to print all available pizzas " << endl << "'d' to print all available toppings" << endl
             << "'e' to create a new combination or the menu" << endl << "'f' to put in new products, i.e. sodas & breadsticks" << endl << "'g' to set pricing for products"  << endl
             << "'h' to set delivery places" << endl << "'q' to Quit " << endl;

        cin >> answer;
        if (answer != 'q' || answer == 'Q')
        {
            if (answer == 'a' || answer == 'A')
            {
                cout << "---Adding new Pizza--- " << endl;
            }
            else if (answer == 'b' || answer == 'B')
            {
                Toppings toppings;
                toppings.add_toppings();
            }
            else if (answer == 'c' || answer == 'C')
            {
                cout << "---All Pizzas--- " << endl;
            }
            else if (answer == 'd' || answer == 'D')
            {
                cout << "---All Toppings--- " << endl;
            }
            else if (answer == 'e' || answer == 'E')
            {
                cout << "---Creating new combination for menu---" << endl;
            }
            else if (answer == 'f' || answer == 'F')
            {
                cout << "---Putting in new orders i.e. sodas & breadsticks---" << endl;
            }
            else if (answer == 'g' || answer == 'G')
            {
                cout << "---Setting prices for products---" << endl;
            }
            else if (answer == 'h' || answer == 'H')
            {
                cout << "---Setting delivery places---" << endl;
            }
            else
            {
                cout << "Wrong input, try again " << endl;
            }
        }
    }
}
