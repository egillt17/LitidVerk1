#include "Display.h"
#include "ManagerUI.h"

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
                bakerUI();
            }
            else if (input == 'd' || input == 'D')
            {
                deliveryUI();
            }
            else if (input == 's' || input == 'S')
            {
                salesUI();
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
    char answer = ' ';

    while (answer != 'q' || answer == 'Q')
    {
        cout << endl << "Hello Baker!" << endl;
        cout << "What is you location? " << endl;
        cout << "'a' to go to location a" << endl << "'b' to go to location b" << endl << "'q' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer != 'q' || answer == 'Q')
        {
            if (answer == 'a' || answer == 'A')
            {
                char answer = ' ';

                while (answer != 'q' || answer == 'Q')
                {
                    cout << "---Goes to location a---" << endl;
                    cout << "What would you like to do at location a?" << endl;
                    cout << "'a' to get a list of all pending orders at location a" << endl << "'b' to get a specific order up" << endl << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q' || answer == 'Q')
                    {
                        if (answer == 'a' || answer == 'A')
                        {
                            cout << "---Getting a list of all orders for location a---" << endl;
                        }
                        else if (answer == 'b' || answer == 'B')
                        {
                            char answer = ' ';

                            while (answer != 'q' || answer == 'Q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order \"In the making\"" << endl << "'b' to mark an order Ready" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q' || answer == 'Q')
                                {
                                    if (answer == 'a' || answer == 'A')
                                    {
                                        cout << "---Marking an order \"In the making\"---" << endl;
                                    }
                                    else if (answer == 'b' || answer == 'B')
                                    {
                                        cout << "---Marking an order Ready---" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong answer, try again" << endl;
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "Wrong input, try again" << endl;
                        }
                    }
                }

            }
            else if (answer == 'b' || answer == 'B')
            {
                char answer = ' ';

                while (answer != 'q' || answer == 'Q')
                {
                    cout << "---Goes to location b---" << endl;
                    cout << "What would you like to do at location b?" << endl;
                    cout << "'a' to get a list of all pending orders for location b" << endl << "'b' to get a specific order up" << endl << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q' || answer == 'Q')
                    {
                        if (answer == 'a' || answer == 'A')
                        {
                            cout << "---Getting a list of all orders for location b---" << endl;
                        }
                        else if (answer == 'b' || answer == 'B')
                        {
                            char answer = ' ';

                            while (answer != 'q' || answer == 'Q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order \"In the making\"" << endl << "'b' to mark an order Ready" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q' || answer == 'Q')
                                {
                                    if (answer == 'a' || answer == 'A')
                                    {
                                        cout << "---Marking an order \"In the making\"---" << endl;
                                    }
                                    else if (answer == 'b' || answer == 'B')
                                    {
                                        cout << "---Marking an order Ready---" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong answer, try again" << endl;
                                    }
                                }
                            }

                        }
                        else
                        {
                            cout << "Wrong input, try again" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "Wrong location, try again" << endl;
            }
        }
    }
}

void Display::deliveryUI()
{
    char answer = ' ';

    while (answer != 'q' || answer == 'Q')
    {
        cout << endl << "Hello Delivery Person!" << endl;
        cout << "What is you location? " << endl;
        cout << "'a' to go to location a" << endl << "'b' to go to location b" << endl << "'q' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer != 'q' || answer == 'Q')
        {
            if (answer == 'a' || answer == 'A')
            {
                char answer = ' ';

                while (answer != 'q' || answer == 'Q')
                {
                    cout << "---Goes to location a---" << endl;
                    cout << "What would you like to do at location a?" << endl;
                    cout << "'a' to get a list of all orders for location a" << endl << "'c' to get a list of all completed orders for location a" << endl << "'b' to get a specific order up" << endl
                         << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q' || answer == 'Q')
                    {
                        if (answer == 'a' || answer == 'A')
                        {
                            cout << "---Getting a list of all orders for location a---" << endl;
                        }
                        else if (answer == 'b' || answer == 'B')
                        {
                            char answer = ' ';

                            while (answer != 'q' || answer == 'Q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order Paid" << endl << "'b' to mark an order Delivered" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q' || answer == 'Q')
                                {
                                    if (answer == 'a' || answer == 'A')
                                    {
                                        cout << "---Marking an order Paid---" << endl;
                                    }
                                    else if (answer == 'b' || answer == 'B')
                                    {
                                        cout << "---Marking an order Delivered---" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong answer, try again" << endl;
                                    }
                                }
                            }
                        }
                        else if (answer == 'c' || answer == 'C')
                        {
                            cout << "---Get a list of all completed orders for location a---" << endl;
                        }
                        else
                        {
                            cout << "Wrong input, try again" << endl;
                        }
                    }
                }
            }
            if (answer == 'b' || answer == 'B')
            {
                char answer = ' ';

                while (answer != 'q' || answer == 'Q')
                {
                    cout << "---Goes to location b---" << endl;
                    cout << "What would you like to do at location b?" << endl;
                    cout << "'a' to get a list of all orders for location b" << endl << "'c' to get a list of all completed orders for location b" << endl << "'b' to get a specific order up" << endl
                         << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q' || answer == 'Q')
                    {
                        if (answer == 'a' || answer == 'A')
                        {
                            cout << "---Getting a list of all orders for location b---" << endl;
                        }
                        else if (answer == 'b' || answer == 'B')
                        {
                            char answer = ' ';

                            while (answer != 'q' || answer == 'Q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order Paid" << endl << "'b' to mark an order Delivered" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q' || answer == 'Q')
                                {
                                    if (answer == 'a' || answer == 'A')
                                    {
                                        cout << "---Marking an order Paid---" << endl;
                                    }
                                    else if (answer == 'b' || answer == 'B')
                                    {
                                        cout << "---Marking an order Delivered---" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong answer, try again" << endl;
                                    }
                                }
                            }
                        }
                        else if (answer == 'c' || answer == 'C')
                        {
                            cout << "---Get a list of all completed orders for location b---" << endl;
                        }
                        else
                        {
                            cout << "Wrong input, try again" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "Wrong location, try again" << endl;
            }
        }
    }
}

void Display::salesUI()
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
