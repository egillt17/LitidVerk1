#include "Display.h"
#include "ManagerUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include "SalesUI.h"

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

    while (input != 'q' && input != 'Q')
    {
        cout << "---Main Menu---" << endl;
        cout << "What is your role? " << endl;
        cout << "'m' for Manager" << endl << "'b' for Baker" << endl << "'d' for Delivery Person" << endl << "'s' for Sales Person" << endl << "'q' for Quit" << endl;

        cin >> input;
        if (input != 'q' && input != 'Q')
        {
            if (input == 'm' || input == 'M')
            {
                ManagerUI managerUI;
                managerUI.displayManagerUI();
            }
            else if (input == 'b'  || input == 'B')
            {
                BakerUI bakerUI;
                bakerUI.displayBakerUI();
            }
            else if (input == 'd' || input == 'D')
            {
                DeliveryUI deliveryUI;
                deliveryUI.displayDeliveryUI();
            }
            else if (input == 's' || input == 'S')
            {
                SalesUI salesUI;
                salesUI.displaySalesUI();
            }
            else
            {
                cout << "Wrong input, try again " << endl;
            }
        }
    }
}
