#include "Baker_ui.h"


void Baker_ui::bakerMainUI() {          ///Pretty basic if/else commands in this function, to summarize we are figuring out which location the baker is located at and what
                                        ///he is doing at that location.
    while (true)
    {
        vector<string> locations;
        unsigned int number;
        string input;
        string location;
        PizzaService get;

        cout << "                Bakers Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What is you location? " << endl;

        locations = get.getLocation();
        for(unsigned int i = 0; i < locations.size(); i++) {
            cout << "| " << (i+1) << ". " << locations[i] << endl;
        }
        cout << "| " << locations.size() + 1 << ". to Exit" << endl;
        cin >> input;
        stringstream sin(input);
        sin >> number;

        if(number > 0 && number <= locations.size()) {
            location = locations[number-1];
            locationMenu(location);
        }
        else if (number == locations.size()+1) {
            system("CLS");
            break;
        }
        else {
            system("CLS");
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}

void Baker_ui::locationMenu(string location) {

    system("CLS");

    vector<Order> orders;
    Order order;
    char answer;
    PizzaService get;

    while (true)
    {
        cout << "               Location: " << location << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What would you like to do at " << location << "?" << endl;
        cout << "| '1' to get a list of all pending orders at "<< location << endl << "| '2' to get a specific order up" << endl << "| '3' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer == '1')
        {
            system("CLS");
            cout << "---Getting a list of all pending orders for " << location << endl;
            orders = get.getOrders();
            for (unsigned int i = 0; i < orders.size(); i++) {
                if (orders[i].getLocation() == location && orders[i].getProgress() == 'w') {
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
                    order.setProgress('y');
                }
                else if (answer == '2')
                {
                    system("CLS");
                    cout << "---Marking an order Ready---" << endl;
                    Order order;
                    order.setProgress('r');
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


