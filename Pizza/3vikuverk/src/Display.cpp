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

    while (input != 'q')
    {
        cout << "---Main Menu---" << endl;
        cout << "What is your role? " << endl;
        cout << "'m' for Manager" << endl << "'b' for Baker" << endl << "'d' for Delivery Person" << endl << "'s' for Sales Person" << endl << "'q' for Quit" << endl;

        cin >> input;
        if (input != 'q')
        {
            if (input == 'm')
            {
                managerUI();
            }
            else if (input == 'b')
            {
                bakerUI();
            }
            else if (input == 'd')
            {
                deliveryUI();
            }
            else if (input == 's')
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

void Display::managerUI()
{
    char answer = ' ';

    while (answer != 'q')
    {
        cout << endl << "Hello Manager!" << endl;
        cout << "What would you like to do? " << endl;
        cout << "'p' to add a new pizza " << endl << "'t' to add a new topping " << endl << "'P' to print all available pizzas " << endl << "'T' to print all available toppings" << endl
             << "'q' to Quit " << endl;

        cin >> answer;
        if (answer != 'q')
        {
            if (answer == 'p')
            {
                cout << "---Adding new Pizza--- " << endl;
            }
            else if (answer == 't')
            {
                cout << "---Adding new Topping--- " << endl;
            }
            else if (answer == 'P')
            {
                cout << "---All Pizzas--- " << endl;
            }
            else if (answer == 'T')
            {
                cout << "---All Toppings--- " << endl;
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

    while (answer != 'q')
    {
        cout << endl << "Hello Baker!" << endl;
        cout << "What is you location? " << endl;
        cout << "'a' to go to location a" << endl << "'b' to go to location b" << endl << "'q' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer != 'q')
        {
            if (answer == 'a')
            {
                char answer = ' ';

                while (answer != 'q')
                {
                    cout << "---Goes to location a---" << endl;
                    cout << "What would you like to do at location a?" << endl;
                    cout << "'a' to get a list of all pending orders" << endl << "'b' to get a specific order up" << endl << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q')
                    {
                        if (answer == 'a')
                        {
                            cout << "---Getting a list of all orders---" << endl;
                        }
                        else if (answer == 'b')
                        {
                            char answer = ' ';

                            while (answer != 'q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order \"In the making\"" << endl << "'b' to mark an order Ready" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q')
                                {
                                    if (answer == 'a')
                                    {
                                        cout << "---Marking an order \"In the making\"---" << endl;
                                    }
                                    else if (answer == 'b')
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
            else if (answer == 'b')
            {
                cout << "---Goes to location b---" << endl;
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

    while (answer != 'q')
    {
        cout << endl << "Hello Delivery Person!" << endl;
        cout << "What is you location? " << endl;
        cout << "'a' to go to location a" << endl << "'b' to go to location b" << endl << "'q' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer != 'q')
        {
            if (answer == 'a')
            {
                char answer = ' ';

                while (answer != 'q')
                {
                    cout << "---Goes to location a---" << endl;
                    cout << "What would you like to do at location a?" << endl;
                    cout << "'a' to get a list of all orders" << endl << "'c' to get a list of all completed orders" << endl << "'b' to get a specific order up" << endl << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q')
                    {
                        if (answer == 'a')
                        {
                            cout << "---Getting a list of all orders---" << endl;
                        }
                        else if (answer == 'b')
                        {
                            char answer = ' ';

                            while (answer != 'q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order Paid" << endl << "'b' to mark an order Delivered" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q')
                                {
                                    if (answer == 'a')
                                    {
                                        cout << "---Marking an order Paid---" << endl;
                                    }
                                    else if (answer == 'b')
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
                        else if (answer == 'c')
                        {
                            cout << "---Get a list of all completed orders---" << endl;
                        }
                        else
                        {
                            cout << "Wrong input, try again" << endl;
                        }
                    }
                }
            }
            if (answer == 'b')
            {
                char answer = ' ';

                while (answer != 'q')
                {
                    cout << "---Goes to location b---" << endl;
                    cout << "What would you like to do at location b?" << endl;
                    cout << "'a' to get a list of all orders" << endl << "'c' to get a list of all completed orders" << endl << "'b' to get a specific order up" << endl << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q')
                    {
                        if (answer == 'a')
                        {
                            cout << "---Getting a list of all orders---" << endl;
                        }
                        else if (answer == 'b')
                        {
                            char answer = ' ';

                            while (answer != 'q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order Paid" << endl << "'b' to mark an order Delivered" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q')
                                {
                                    if (answer == 'a')
                                    {
                                        cout << "---Marking an order Paid---" << endl;
                                    }
                                    else if (answer == 'b')
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
                        else if (answer == 'c')
                        {
                            cout << "---Get a list of all completed orders---" << endl;
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

    while (answer != 'q')
    {
        cout << endl << "Hello Sales Person!" << endl;
        cout << "What would you like to do? " << endl;
        cout << "'a' to set up a new order" << endl << "'b' to add pizzas (and other things) to order" << endl << "'c' to get up total price of the order" << endl
             << "'d' to set and order to delivered or pick up" << endl << "'e' to mark an order paid for" << endl << "'f' to set a specific location for an order" << endl
             << "'g' to add comments" << endl << "'q' to Quit" << endl;
        cin >> answer;
        cout << endl;
        if (answer != 'q')
        {
            if (answer == 'a')
            {
                cout << "---Setting up a new order---" << endl;
            }
            else if (answer == 'b')
            {
                cout << "---Adding pizzas (and other things) to order---" << endl;
            }
            else if (answer == 'c')
            {
                cout << "---Getting total price of order---" << endl;
            }
            else if (answer == 'd')
            {
                cout << "---Setting and order to deliver og pickup---" << endl;
            }
            else if (answer == 'e')
            {
                cout << "---Marking an order paid for---" << endl;
            }
            else if (answer == 'f')
            {
                cout << "---Setting a specific location for order---" << endl;
            }
            else if (answer == 'g')
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
