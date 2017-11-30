#include "SalesUI.h"
#include "Display.h"

SalesUI::SalesUI()
{
    //ctor
}

SalesUI::~SalesUI()
{
    //dtor
}

void SalesUI::displaySalesUI()
{
    char answer = ' ';

    while (answer != 'q' || answer == 'Q')
    {
        cout << endl << "Hello Sales Person!" << endl;
        cout << "What would you like to do? " << endl;
        cout << "'a' to set up a new order" << endl << "'b' to add pizzas (and other things) to order" << endl << "'c' to get up total price of the order" << endl
             << "'d' to set and order to delivered or pick up" << endl << "'e' to mark an order paid for" << endl << "'f' to set a specific location for an order" << endl
             << "'g' to add comments" << endl << "'q' to Quit" << endl;
        cin >> answer;
        cout << endl;
        if (answer != 'q' || answer == 'Q')
        {
            if (answer == 'a' || answer == 'A')
            {
                cout << "---Setting up a new order---" << endl;
            }
            else if (answer == 'b' || answer == 'B')
            {
                cout << "---Adding pizzas (and other things) to order---" << endl;
            }
            else if (answer == 'c' || answer == 'C')
            {
                cout << "---Getting total price of order---" << endl;
            }
            else if (answer == 'd' || answer == 'D')
            {
                cout << "---Setting and order to deliver og pickup---" << endl;
            }
            else if (answer == 'e' || answer == 'E')
            {
                cout << "---Marking an order paid for---" << endl;
            }
            else if (answer == 'f' || answer == 'F')
            {
                cout << "---Setting a specific location for order---" << endl;
            }
            else if (answer == 'g' || answer == 'G')
            {
                cout << "---Adding comments---" << endl;
            }
            else
            {
                cout << "Wrong input, try again" << endl;
            }
        }
    }
}

