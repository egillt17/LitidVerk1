#include "Baker_ui.h"


void Delivery_ui::deliveryMainUI() {        ///Pretty basic if/else commands in this function, to summarize we are figuring out which location the baker is located at and what
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

        locations = get.getLocation();                          ///Create a vector of locations based on the function getLocations in PizzaService class
        for(unsigned int i = 0; i < locations.size(); i++) {
            cout << "| " << (i+1) << ". " << locations[i] << endl;      ///printing all locations from the getLocations function
        }
        cout << "| " << locations.size() + 1 << ". to Exit" << endl;
        cin >> input;
        stringstream sin(input);            ///Using stringstream to turn the string input to an int
        sin >> number;

        if(number > 0 && number <= locations.size()) {
            location = locations[number-1];             ///checking if the input is valid according to the state of the locations text file
            locationMenu(location);                     ///and sends that to the locationMenu function
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

void Delivery_ui::locationMenu(string location) {        ///Takes in the location that was choosen

    system("CLS");

    vector<Order> orders;
    Order order;
    char answer = '\0';
    string stranswer = "";
    PizzaService get;
    unsigned int number = 0;

    while (true)
    {
        cout << "               Location: " << location << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What would you like to do at " << location << "?" << endl;
        cout << "| '1' to get a list of all orders at "<< location << endl << "| '2' to get a list of all ready orders at " << location << endl
             << "| '3' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer == '1') {
            system("CLS");
            cout << "| List of all orders for " << location << endl;
            orders = get.getAllOrdersforASpecificLocation(location);
                                                                                                    ///Getting all orders from the orders text file and
            for(unsigned int i = 0; i < orders.size(); i++){                                          ///Prints all orders from the chosen location
                    cout << (i+1) << ". " << orders[i] << endl;                                         ///Runs if the location matches
            }
            cout << (orders.size()+1) << ". " << "to Exit" << endl;
            cout << "| What order would you like to get up? ";
            cin >> stranswer;
            stringstream sin(stranswer);
            sin >> number;
            if(number > 0 && number <= orders.size()){
                cout << orders[number-1];

                while (true) {
                    system("CLS");
                    cout << "| What would you like to do about that order?" << endl;
                    cout << "| '1' to mark an order paid for" << endl << "| '2' to mark an order delivered" << endl << "| '3' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer == '1')                  ///Pretty straightforward, here we are changing the Progress variable in the Order class
                    {
                        system("CLS");
                        cout << "| Order marked paid for" << endl;
                        orders[number-1].setPaidFor('p');
                        get.reWriteOrdersService(orders, location);
                        system("Pause");
                    }
                    else if (answer == '2')
                    {
                        system("CLS");
                        cout << "| Order marked delivered" << endl;
                        order.setDelivered('y');
                        get.reWriteOrdersService(orders, location);
                        system("Pause");
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
            else if (number == orders.size()+1) {
                system("CLS");
                break;
            }
            else {
                cout << "| no can do!" << endl;
                system("pause");
            }
        }
        else if (answer == '2') {

            while(true) {
                system("CLS");
                cout << "| List of all ready orders for " << location << endl;
                orders = get.getReadyOrdersforASpecificLocation(location);
                                                                                                        ///Getting all ready orders from the orders text file and
                for(unsigned int i = 0; i < orders.size(); i++){                                          ///Prints all ready orders from the chosen location
                    cout << (i+1) << ". " << orders[i] << endl;                                         ///Runs if the location matches
                }
                cout << (orders.size()+1) << ". " << "to Exit" << endl;
                cout << "| What order would you like to get up? ";
                cin >> stranswer;
                stringstream sin(stranswer);
                sin >> number;
                if(number > 0 && number <= orders.size()){
                    cout << orders[number-1];

                    while (true) {

                        system("CLS");
                        cout << "| What would you like to do about that order?" << endl;
                        cout << "| '1' to mark an order paid for" << endl << "| '2' to mark an order delivered" << endl << "| '3' to Quit" << endl;

                        cin >> answer;
                        cout << endl;

                        if (answer == '1')                  ///Pretty straightforward, here we are changing the Progress variable in the Order class
                        {
                            cout << "| Order marked paid for" << endl;
                            orders[number-1].setPaidFor('p');
                            get.reWriteOrdersService(orders, location);
                            system("Pause");
                        }
                        else if (answer == '2')
                        {
                            cout << "| Order marked delivered" << endl;
                            orders[number-1].setDelivered('y');
                            get.reWriteOrdersService(orders, location);
                            system("Pause");
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
                else if (number == orders.size()+1) {
                    system("CLS");
                    break;
                }
                else {
                    cout << "| no can do!" << endl;
                    system("pause");
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
