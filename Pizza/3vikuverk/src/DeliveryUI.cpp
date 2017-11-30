#include "DeliveryUI.h"
#include "Display.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}

DeliveryUI::~DeliveryUI()
{
    //dtor
}
void DeliveryUI::displayDeliveryUI()
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
