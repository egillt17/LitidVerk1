#include "Delivery_ui.h"


void Delivery_ui::deliveryMainUI() {    ///Pretty basic if/else commands in this function, to summarize we are figuring out which location the baker is located at and what
                                        ///he is doing at that location.
    char answer = '\0';

    while (true)
    {
        vector<Order> orders;
        PizzaService get;
        cout << "               Delivery Main Menu               " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What is you location? " << endl;
        cout << "| '1' to go to location 1" << endl << "| '2' to go to location 2" << endl << "| '3' to Quit" << endl;
        cin >> answer;

        if (answer == '1')
        {
            system("CLS");
            while (true)
            {
                cout << "                  Location 1                    " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| What would you like to do at location 1?" << endl;
                cout << "| '1' to get a list of all orders at location 1" << endl << "| '2' to get a list of ready orders for location 1" << endl << "| '3' to get up a specific order" <<
                endl << "| '4' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')
                {
                    system("CLS");
                    cout << "---Getting a list of all orders for location 1---" << endl;
                    orders = get.getOrders();
                    for (unsigned int i = 0; i < orders.size(); i++) {
                        if (orders[i].getLocation() == "location1") {
                            cout << (i+1) << ". " << orders[i];
                        }
                    }
                }
                else if (answer == '2')
                {
                    system("CLS");
                    cout << "---Getting a list of all ready orders for location 1---" << endl;
                    orders = get.getOrders();
                    for (unsigned int i = 0; i < orders.size(); i++) {
                        if (orders[i].getLocation() == "location1" && orders[i].getIsReady() == 'y') {
                            cout << (i+1) << ". " << orders[i];
                        }
                    }
                }
                else if (answer == '3')
                {
                    system("CLS");
                    char answer = '\0';

                    while (true)
                    {
                        cout << "| What would you like to do about that order?" << endl;
                        cout << "| '1' to mark an order paid for" << endl << "| '2' to mark an order delivered" << endl << "| '3' to Quit" << endl;

                        cin >> answer;
                        cout << endl;

                        if (answer == '1')
                        {
                            system("CLS");
                            cout << "---Marking an order paid for" << endl;
                            Order order;
                            order.setPaidFor('y');
                        }
                        else if (answer == '2')
                        {
                            system("CLS");
                            cout << "---Marking an order delivered---" << endl;
                            Order order;
                            order.setDelivered('y');
                        }
                        else if (answer == '3')
                        {
                            system("CLS");
                            break;
                        }
                        else
                        {
                            system("CLS");
                            cout << "| Wrong input, please try again" << endl << endl;
                        }
                    }
                }
                else if (answer == '4')
                {
                    system("CLS");
                    break;
                }
                else
                {
                    system("CLS");
                    cout << "| Wrong input, please try again" << endl << endl;
                }

            }
        }
        else if (answer == '2')
        {
            system("CLS");
            char answer = '\0';

            while (true)
            {
                cout << "                  Location 2                    " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| What would you like to do at location 2?" << endl;
                cout << "| '1' to get a list of all pending orders for location 2" << endl << "| '2' to get a list of all ready orders from location 2"
                     << endl << "| '3' to get up a specific order" << endl << "| '4' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')
                {
                    system("CLS");
                    cout << "---Getting a list of all orders for location 2---" << endl;
                    orders = get.getOrders();
                    for (unsigned int i = 0; i < orders.size(); i++) {
                        if (orders[i].getLocation() == "location2") {
                            cout << (i+1) << ". " << orders[i];
                        }
                    }
                }
                else if (answer == '2')
                {
                    system("CLS");
                    cout << "---Getting a list of all ready orders for location 2---" << endl;
                    orders = get.getOrders();
                    for (unsigned int i = 0; i < orders.size(); i++) {
                        if (orders[i].getLocation() == "location2" && orders[i].getIsReady() == 'y') {
                            cout << (i+1) << ". " << orders[i];
                        }
                    }
                }
                else if (answer == '3')
                {
                    system("CLS");
                    char answer = '\0';

                    while (true)
                    {
                        cout << "| What would you like to do about that order?" << endl;
                        cout << "| '1' to mark an order paid for" << endl << "| '2' to mark an order delivered" << endl << "| '3' to Quit" << endl;

                        cin >> answer;
                        cout << endl;

                        if (answer == '1')
                        {
                            system("CLS");
                            cout << "---Marking an order paid for---" << endl;
                            Order order;
                            order.setPaidFor('y');
                        }
                        else if (answer == '2')
                        {
                            system("CLS");
                            cout << "---Marking an order delivered---" << endl;
                            Order order;
                            order.setDelivered('y');
                        }
                        else if (answer == '3')
                        {
                            system("CLS");
                            break;
                        }
                        else
                        {
                            system("CLS");
                            cout << "| Wrong input, please try again" << endl << endl;
                        }
                    }
                }
                else if (answer == '4')
                {
                    system("CLS");
                    break;
                }
                else
                {
                    system("CLS");
                    cout << "| Wrong input, please try again" << endl << endl;
                }
            }
        }
        else if (answer == '3')
        {
            system("CLS");
            break;
        }
        else
        {
            system("CLS");
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}
