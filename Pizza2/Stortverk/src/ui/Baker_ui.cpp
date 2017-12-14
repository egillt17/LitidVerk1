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
    PizzaService get;
    Order order;
    char answer;
    unsigned int number = 0;
    bool changed = false;

    while (true)
    {
        system("CLS");
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
            cout << "         All unfinished pizzas at " << location << endl;
            cout << "------------------------------------------------" << endl;
            orders = get.getUnfinishedOrdersforASpecificLocation(location);
                                                                                            ///Getting all pending orders from the orders text file and
            for(unsigned int i = 0; i < orders.size(); i++) {                               ///Prints all orders from the chosen location
                cout << "Order number " << (i+1) << "." << endl;
                vector <Pizza> temp = orders[i].getPizzas();
                for(unsigned int j = 0; j < temp.size(); j++){
                    cout << endl << "Pizza number " << (j+1) << "." << endl;
                    cout << temp[j];
                }
                cout << "| Anything you would like to change with this order? " << endl;
                cout << "| '1' to change status " << endl;
                cout << "| any other key to continue " << endl;
                cin >> stranswer;
                stringstream sin(stranswer);
                sin >> number;
                if(number == 1 ) {
                    changed = true;
                    changeStatus(temp);
                    orders[i].setPizzas(temp);
                }
                else {

                }
            }
            if(changed == true) {
                get.reWriteOrdersService(orders, location);
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

void Baker_ui::changeStatus(vector <Pizza>& pizzas) {
    system("CLS");
    string stranswer = "";
    int number = 0;
    for(unsigned int i = 0; i < pizzas.size(); i++) {
        cout << pizzas[i];
        cout << "| Anything you would like to change with this order? " << endl;
        cout << "| '1' to change status " << endl;
        cout << "| any other key to continue " << endl;
        cin >> stranswer;
        stringstream sin(stranswer);
        sin >> number;
        if(number == 1 ) {
            cout << "| '1' to change status to ready " << endl;
            cout << "| '2' to change status to in progress " << endl;
            cout << "| '3' to go back " << endl;
            cout << "| any other key to continue" << endl;
            cin >> stranswer;
            stringstream sin(stranswer);
            sin >> number;
            if(number == 1) {
                pizzas[i].setStatus('r');
            }
            else if(number == 2) {
                pizzas[i].setStatus('i');
            }
            else if(number == 3) {
                break;
            }
        }
        else {

        }
    }
}

