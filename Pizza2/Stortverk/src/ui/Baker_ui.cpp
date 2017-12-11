#include "Baker_ui.h"


void Baker_ui::bakerMainUI() {          ///Pretty basic if/else commands in this function, to summarize we are figuring out which location the baker is located at and what
                                        ///he is doing at that location.
    char answer = '\0';

    while (true)
    {
        vector<Order> orders;
        Order order;
        vector<string> locations;
        PizzaService get;
        unsigned int number = 0;
        string answer;
        char locAnswer = (char)answer;
        cout << "                Bakers Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What is you location? " << endl;

        locations = get.getLocation();
        for (unsigned int i = 0; i < locations.size(); i++) {
            cout << (i+1) << ". " << locations[i] << endl;
        }

        cout << "Pick a Location: " ;
        cin >> locAnswer;
        stringstream sin(Answer);
            sin >> number;
            if(number > 0 && number <= locations.size()){
                order.setLocationForOrder(locations[number-1]);
            }
            else {
                cout << "Wrong input, please try again" << endl;
                system("pause");
            }

        if (locAnswer == '1')
        {
            system("CLS");
            while (true)
            {
                cout << "                  Location 1                    " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| What would you like to do at location 1?" << endl;
                cout << "| '1' to get a list of all pending orders at location 1" << endl << "| '2' to get a specific order up" << endl << "| '3' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')
                {
                    system("CLS");
                    cout << "---Getting a list of all pending orders for location 1---" << endl;
                    orders = get.getOrders();
                    for (unsigned int i = 0; i < orders.size(); i++) {
                        if (orders[i].getLocation() == "location1" && orders[i].getIsReady() == 'n') {
                            cout << (i+1) << ". " << orders[i] << endl;
                        }
                    }
                }
                else if (answer == '2')
                {
                    system("CLS");
                    char answer = '\0';

                    while (true)
                    {
                        cout << "| What would you like to do about that order?" << endl;
                        cout << "| '1' to mark an order \"In progress\"" << endl << "| '2' to mark an order Ready" << endl << "| '3' to Quit" << endl;

                        cin >> answer;
                        cout << endl;

                        if (answer == '1')
                        {
                            system("CLS");
                            cout << "---Marking an order \"In progress\"---" << endl;
                            Order order;
                            order.setInProgress('y');
                        }
                        else if (answer == '2')
                        {
                            system("CLS");
                            cout << "---Marking an order Ready---" << endl;
                            Order order;
                            order.setIsReady('y');
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
        else if (locAnswer == '2')
        {
            system("CLS");
            char answer = '\0';

            while (true)
            {
                cout << "                  Location 2                    " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| What would you like to do at location 2?" << endl;
                cout << "| '1' to get a list of all pending orders for location 2" << endl << "| '2' to get a specific order up" << endl << "| '3' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')
                {
                    system("CLS");
                    cout << "---Getting a list of all pending orders for location 2---" << endl;
                    orders = get.getOrders();
                    for (unsigned int i = 0; i < orders.size(); i++) {
                        if (orders[i].getLocation() == "location2" && orders[i].getIsReady() == 'n') {
                            cout << (i+1) << ". " << orders[i] << endl;
                        }
                    }
                }
                else if (answer == '2')
                {
                    system("CLS");
                    char answer = '\0';

                    while (true)
                    {
                        cout << "| What would you like to do about that order?" << endl;
                        cout << "| '1' to mark an order \"In progress\"" << endl << "| '2' to mark an order Ready" << endl << "| '3' to Quit" << endl;

                        cin >> answer;
                        cout << endl;

                        if (answer == '1')
                        {
                            system("CLS");
                            cout << "---Marking an order \"In progress\"---" << endl;
                            Order order;
                            order.setInProgress('y');
                        }
                        else if (answer == '2')
                        {
                            system("CLS");
                            cout << "---Marking an order Ready---" << endl;
                            Order order;
                            order.setIsReady('y');
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
