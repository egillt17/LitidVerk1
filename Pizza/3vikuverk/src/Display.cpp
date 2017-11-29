#include "Display.h"

Display::Display()
{
    //ctor
}

Display::~Display()
{
    //dtor
}

void Display::displayMainUI()
{
    char input = ' ';
    cout << "Welcome! " << endl << endl;

    cout << "What is your role? " << endl;
    cout << "'m' for Manager" << endl << "'b' for Baker" << endl << "'c' for Cashier" << endl << "'q' for Quit" << endl;

    while (input != 'q')
    {
        if (input != 'q' || input != 'm' || input != 'b' || input != 'c')
        {
            cin >> input;

            if (input == 'm')
            {
                managerUI();
            }
            else if (input == 'b')
            {
                bakerUI();
            }
            else if (input == 'c')
            {
                cashierUI();
            }
            else if (input == 'q')
            {
            break;
            }
            else
            {
                cout << "Wrong input, try again " << endl;
            }
        }
    }
}

void Display::managerUI()
{
    char answer = ' ';
    cout << "Hello Manager!" << endl;
    cout << "What would you like to do? " << endl;
    cout << "'p' to add a new pizza " << endl << "'t' to add a new topping " << endl << "'P' to print all available pizzas " << endl << "'T' to print all available toppings"
         << "'q' to Quit " << endl << endl;

    cin >> answer;
    while (answer != 'q')
    {
        if (answer != 'q')
        {
            if (answer == 'p')
            {
                cout << "---Adding pizzas---" << endl;
            }
            else if (answer == 't')
            {
                cout << "---Adding toppings---" << endl;
            }
            else if (answer == 'P')
            {
                cout << "---Printing all pizzas---" << endl;
            }
            else if (answer == 'T')
            {
                cout << "---Printing all toppings---" << endl;
            }
            else
            {
                cout << "Wrong input, try again " << endl;
            }
        }
    }
}

void Display::bakerUI()
{
    cout << "Hello Baker!" << endl;
}
void Display::cashierUI()
{
    cout << "Hello Cashier!" << endl;
}
