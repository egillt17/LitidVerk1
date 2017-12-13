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
        else if (number == locations.size()+1) {        ///If the number is 1 over the location.size() then the UI will exit
            system("CLS");
            break;
        }
        else {
            system("CLS");
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}

void Baker_ui::locationMenu(string location) {              ///Takes in the location that was choosen

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
        cout << "| '1' to get a list of all pending pizzas at "<< location << endl << "| '2' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer == '1')
        {
            string stranswer = "";
            system("CLS");
<<<<<<< HEAD
            cout << "---Getting a list of all pending orders for " << location << endl;
             orders = get.getOrders();                                                       ///Getting all pending orders from the orders text file and
            for (unsigned int i = 0; i < orders.size(); i++) {                              ///Prints all orders from the chosen location
                if (orders[i].getLocation() == location && orders[i].getProgress() == 'w') {
                    cout << (i+1) << ". " << orders[i] << endl;
                }
=======
            cout << "         All unfinished pizzas at " << location << endl;
            cout << "------------------------------------------------" << endl;
            ///orders = get.getOrdersforASpecificLocation(location);                           ///Getting all pending orders from the orders text file and
            cout << orders.size() << endl;
            for(unsigned int i = 0; i < orders.size(); i++) {                              ///Prints all orders from the chosen location
                    cout << "lala" << endl;
                    cout << orders[i];
            }
            cout << "What pizza would you like to get up?";
            cin >> stranswer;
            stringstream sin(stranswer);
            unsigned int number = 0;
            sin >> number;
            if(number > 0 && number <= orders.size()){
                cout << orders[number-1];
            }
            else {
                cout << "no can do!" << endl;
                system("pause");
>>>>>>> e7a5a0b298fa93a610df928dbc3bbb1c927aa123
            }
            char answer = '\0';

            while (true)
            {
                cout << "| What would you like to do about that pizza?" << endl;
                cout << "| '1' to mark it \"In progress\"" << endl << "| '2' to mark it Ready" << endl << "| '3' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')                                              ///Pretty straightforward, here we are changing the Progress variable in the Order class
                {
                    system("CLS");
                    cout << "---Marking a pizza \"In progress\"---" << endl;
                    Order order;
                    order.setProgress('y');
                }
                else if (answer == '2')
                {
                    system("CLS");
                    cout << "---Marking a pizza Ready---" << endl;
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
        else if (answer == '2')
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


