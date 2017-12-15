#include "Manager_ui.h"
/// including the manager_ui.h file

/// enumerator to choose in the topping model class
enum Pick {toppingsPick = 1, crustPick, sizesPick, saucePick, extraPick};

/// Main manager UI
void Manager_ui::managerMainUI(){
    char input = '\0';
    while(true) {
        cout << endl;
        cout << "               Manager Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' for Pizza specials management" << endl;
        cout << "| '2' for Toppings management" << endl;
        cout << "| '3' for Extra management" << endl;
        cout << "| '4' for Location management" << endl;
        cout << "| '5' for Crust, Sauce and Size management" << endl;
        cout << "| '6' to view sales" << endl;
        cout << "| '7' to exit to the Main menu" << endl;
        cout << "| Input : ";
        cin >> input;
        /// If else to choose which is function or UI to call
        if(input == '1') {
            system("cls");
            managePizzaUI();
        }
        else if(input == '2'){
            system("cls");
            manageToppingUI();
        }
        else if(input == '3') {
            system("cls");
            manageExtraUI();
        }
        else if(input == '4') {
            system("cls");
            manageLocationUI();
        }
        else if(input == '5') {
            system("cls");
            manageSettingUI();
        }
        else if(input == '6') {
            system("cls");
            manageSalesUI();
        }
        else if(input == '7') {
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl;
            cout << "| ";
            system("pause");
            system("cls");
        }
    }
}

/// This is a menu that puts special menu item pizzas to a list
void Manager_ui::managePizzaUI() {
    char input = '\0';
    PizzaService pizza_specials;    /// Makes pizza_special variable from PizzaService class
    
    while(true){    /// submenu for the Pizza Management
        system("CLS");
        cout << "          -Manager - Pizza management-          " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display Pizza list " << endl;
        cout << "| '2' Input new Pizza to list" << endl;
        cout << "| '3' Remove Pizza from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;
        if (input == '1'){  /// to display the pizza special menu
            system("cls");
            cout << endl;
            cout << "              -Display Pizza list-              " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            vector<Pizza> tmpPizzas = pizza_specials.getPizzaSpecials();    /// makes a vector of Pizza, called tmpPizzas - all special pizzas goes into that vector
            for(unsigned int i = 0; i < tmpPizzas.size(); i++) {    /// looped through the list
                cout << "|          Pizza number: " << (i+1) << endl;
                cout << tmpPizzas[i];
                cout << "|-----------------------------------------------" << endl;
            }
            cout << "| ";
            system("PAUSE");
        }
        else if(input == '2') { /// the code below works just like the code in Sales_ui.cpp class
            Validate validate;  /// this is to validate the price (if input is new price)
            system("cls");
            string answer = ""; 
            string price = "";
            unsigned int number;    /// this holds the list number value, to pick from a list.
            unsigned int newPrice;  ///  var to hold the new input price
            int sizePrice = 0;  /// holds the price for size
            int saucePrice = 0; /// holds the price for sauce
            int crustPrice = 0; /// hold the crust price
            int toppingPrice = 0;   /// holds the toppings price
            int totalPrice = 0; /// to hold total price
            bool specialPrice = false;  /// setting the special price of menu item
            Pizza tmpPizza;     /// tmpPizza of the class Pizza
            TopService get;     /// to handle toppings
            vector <Toppings> topping;      /// Make vector of the class toppings;
            topping = get.getToppingList(1);
            while(true){
                system("cls");
                if(!specialPrice) {     /// if we choose to set another price instead of accumulated price
                    totalPrice = sizePrice + saucePrice + crustPrice + toppingPrice;    /// this won't calculate, only the new price is set
                }
                tmpPizza.setPrice(totalPrice);  /// this accumulates all prices
                char input = '\0';
                cout << endl;
                cout << "           -Input new Pizza to list-            " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| Current pizza :" << endl;
                cout << tmpPizza;
                cout << "|" << endl;
                cout << "| '1' Set Size" << endl;
                cout << "| '2' Set Crust" << endl;
                cout << "| '3' Set Sauce" << endl;
                cout << "| '4' Add 1 topping to pizza" << endl;
                cout << "| '5' Clear all toppings" << endl;
                cout << "| '6' Set new price" << endl;
                cout << "| '7' Add pizza to 'Pizza Specials' " << endl;
                cout << "| '8' Cancel and go back to main manager menu" << endl;
                cout << "| Input : ";
                cin >> input;
                if(input == '1') {
                    cout << "                  -Set Size-                    " << endl;
                    cout << "------------------------------------------------" << endl;
                    topping = get.getToppingList(sizesPick);   /// gets the list of sizes
                    for(unsigned int i = 0; i < topping.size(); i++) {  /// displays the list
                        cout << "| " << (i+1) << ". " << topping[i];
                    }
                    cout << "| Pick a size: ";
                    cin >> answer;
                    stringstream sin(answer);                   
                    sin >> number;                                 
                    if(number > 0 && number <= topping.size()) {        /// this picks the number of the list of toppings
                        tmpPizza.setSize(topping[number-1].getName());  /// now the tmpPizza has this new size
                        sizePrice = topping[number-1].getPrice();         /// and it accumulates the new price
                    }
                    else {  ///  error if input is wrong
                        cout << "| Invalid Input" << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if(input == '2'){      /// same as size, but with crust
                    cout << "                  -Set Crust-                    " << endl;
                    cout << "------------------------------------------------" << endl;
                    topping = get.getToppingList(crustPick);    /// gets the list of crust
                    for(unsigned int i = 0; i < topping.size(); i++) {
                        cout << "| " << (i+1) << ". " << topping[i];
                    }
                    cout << "| Pick a crust: ";
                    cin >> answer;
                    stringstream sin(answer);                   
                    sin >> number;
                    if(number > 0 && number <= topping.size()){ /// to pick the number of the list
                        tmpPizza.setCrust(topping[number-1].getName()); /// tmpPizza has now the picked crust
                        crustPrice = topping[number-1].getPrice();  /// accumulates the new price
                    }
                    else {
                        cout << "| Invalid Input" << endl;
                        cout << "| ";
                        system("pause");
                    }
                }           /// same as with size / crust but now with Sauce, works the same
                else if (input == '3') {
                    cout << "                  -Set Sauce-                    " << endl;
                    cout << "------------------------------------------------" << endl;
                    topping = get.getToppingList(saucePick);    /// gets the list of sauces
                    for(unsigned int i = 0; i < topping.size(); i++) {
                        cout << "| " << (i+1) << ". " << topping[i];
                    }
                    cout << "| Pick a sauce: ";
                    cin >> answer;
                    stringstream sin(answer);  
                    sin >> number;
                    if(number > 0 && number <= topping.size()){
                        tmpPizza.setSauce(topping[number-1].getName());     /// tmpPizza has now the new sauce
                        saucePrice = topping[number-1].getPrice();          /// accumulates the price
                    }           
                    else {
                        cout << "| Invalid Input" << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if(input == '4'){
                    cout << "               -Add toppings-                    " << endl;
                    cout << "------------------------------------------------" << endl;
                    topping = get.getToppingList(toppingsPick);     /// to get the toppings list
                    for(unsigned int i = 0; i < topping.size(); i++) {
                        cout << "| " << (i+1) << ". " << topping[i];    /// display the toppings
                    }
                    cout << "| Pick a Topping: ";
                    cin >> answer;
                    stringstream sin(answer);                  
                    sin >> number;
                    if(number > 0 && number <= topping.size()){     /// pick one topping of the list
                        tmpPizza.addTopping(topping[number-1]);     /// accumulates the topping to the pizza 
                        toppingPrice = tmpPizza.getToppingPrice();  /// accumulates the topping price
                    }
                    else {
                        cout << "| Invalid Input" << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if (input == '5') {    /// this is handy to clear all the toppings of the pizza, if manager made a mistake
                    tmpPizza.clearTopping();             /// clears toppings          
                    toppingPrice = tmpPizza.getToppingPrice();  /// clears the accumulated price of toppings
                }
                else if (input == '6') {    /// to input another price other than accumulated price
                    cout << "| Input special price: ";
                    cin >> price;
                    try {   /// this validates the price if it contains only digits
                        validate.validateNum(price);
                        stringstream sin(price);
                        sin >> newPrice;    
                        specialPrice = true;    /// setting the special price bool
                        totalPrice = newPrice;  /// total price is not the new price
                        cout << "| New price set successfully" << endl;
                        cout << "| ";
                        system("pause");
                    }
                    catch (InvalidNumExceptions e) {    /// catches the invalid number exception error
                        cout << e.getMessage() << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if(input == '7'){  /// error message if manager tries to submit the new pizza without making the size of pizza first
                    if(!tmpPizza.getSize().compare("Not picked")) {
                        cout << "| You have to pick a size to add the pizza" << endl;     
                        system("pause");
                        break;
                    }
                    else {  /// the new pizza will now be added to the special pizza list,
                    pizza_specials.addPizzaSpecialToList(tmpPizza);
                    cout << "| Pizza successfully added to list" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                    }
                }
                else if(input == '8') { /// goes to the Pizza management  menu
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '3') { /// this removes a special pizza from a list
            vector<Pizza> tmpPizzas = pizza_specials.getPizzaSpecials();    /// get the special pizza list and adds them to a temPizza vector
            
            system("cls");
            string answer = "";
            unsigned int number = 0;    /// to store the value of the removed pizza in the list
            cout << endl;
            cout << "             -Remove Pizza from list-           " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            
            for(unsigned int i = 0; i < tmpPizzas.size(); i++) {
                cout << "|          Pizza number: " << (i+1) << endl;   /// display the special pizza list
                cout << tmpPizzas[i];
                cout << "|-----------------------------------------------" << endl;
                
            }
            cout << "|'0' to exit" << endl; 
            cout << "| Pick a pizza to remove: ";
            cin >> answer; 
                
            stringstream sin(answer);                   
            sin >> number;                             
            if(number > 0 && number <= tmpPizzas.size()) {  /// if you pick a number from the list
                    tmpPizzas.erase (tmpPizzas.begin()+(number-1)); /// the item from the list will be removed
                    pizza_specials.reWritePizzaService(tmpPizzas);  /// writes the new list to service class and down to repo
                    cout << "| Pizza successfully removed" << endl;
                    cout << "| ";
                    system("pause");
            }
            else if (number == 0) { /// goes out without removing anything
                cout << "| Nothing removed" << endl;
                cout << "| ";
                system("pause");
            }
            else {  /// 
                cout << "| Invalid Input " << endl;
                cout << "| ";
                system("pause");
            }
        }
        else if(input == '4') { /// goes back to the Main Manager UI
            cout << "| ";
            system("cls");
            break;            
        }
    }
}

/// This Ui manages topping
void Manager_ui::manageToppingUI() {
    char input = '\0';
    TopService get; /// makes a get variable of the TopService class
    Validate validate;/// makes a validate variable of the Validate class
    vector <Toppings> topping;  /// Makes a topping vector of the Toppings class
    string top = "";
    string price = "";

    /// Sub menu of the manager UI to manage toppings
    while(true) {
        system("cls");
        cout << endl;
        cout << "         -Manager - Toppings management-        " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display topping list " << endl;
        cout << "| '2' Input new topping to list" << endl;
        cout << "| '3' Remove topping from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;

        /// displays list of toppings
        if(input == '1') {
            system("cls");
            cout << endl;
            cout << "             -Display topping list-        " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            topping = get.getToppingList(toppingsPick);    /// reads the topping list, (toppingsPick) is enumeration
            for(unsigned int i = 0; i < topping.size(); i++) {  /// sort through
                cout << topping[i];     /// prints it to the screen
            }
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        /// Sub UI to input new topping to the list
        else if(input == '2'){
            while(true) {
                system("cls");
                cout << endl;
                cout << "              -Input new topping-               " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| Name: ";
                cin.ignore();
                getline(cin, top);  /// Input name
                try {
                    validate.validateName(top);    /// tries to validate the name in the validation class
                    cout << "| Price: ";
                    cin >> price;       /// name goes through, input price
                    try {
                        validate.validateNum(price);        /// validates price ( only digits )
                        get.addTopping(top, price, toppingsPick);   /// to service class to add topping to the list
                        break;
                    }
                    catch(InvalidNumExceptions e) { /// catches the error message if invalid number
                        cout << e.getMessage() << endl; /// prints it out

                    }
                }
                catch(InvalidNameException e) { /// catches the error message if invalid name
                    cout << e.getMessage() << endl; /// prints it out
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        /// UI to remove a topping from the list
        else if(input == '3'){
            string answer = "";
            unsigned int number;
            while(true){
                system("cls");
                cout << endl;
                cout << "           -Remove topping from list-         " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| " << endl;
                topping = get.getToppingList(toppingsPick); /// display the list of toppings, easier to write the topping to remove
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << "| " << i+1 << ". " << topping[i].getName() << endl;
                }
                cout << "| " << endl;
                cout << "| '0' Nothing will be removed" << endl;
                cout << "| What topping would you like to remove? ";
                cin >> answer;
                stringstream sin(answer);                   
                sin >> number;                                 
                if(number > 0 && number <= topping.size()) {        /// this picks the number of the list of toppings
                    top = topping[number-1].getName();              /// puts the name of picked topping to varialbe top
                    get.removeTopping(top, toppingsPick);           /// goes to service to remove topping from list
                    cout << "| Topping succesfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else if(number == 0) {  /// to go back and remove nothing, and display notification
                    cout << "| Nothing removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else {  ///  error if input is wrong
                    cout << "| Invalid Input" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}

/// UI to manage all the extra, soda or sides
void Manager_ui::manageExtraUI(){
    char input = '\0';
    TopService get;
    Validate validate;
    vector <Toppings> topping;
    string top = "";
    string price = "";

    while(true) {
        system("cls");
        cout << endl;
        cout << "          -Manager - Extras management-         " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display extras list " << endl;
        cout << "| '2' Input new extras to list" << endl;
        cout << "| '3' Remove extras from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;

        /// UI to display the list of extras
        if(input == '1') {
            system("cls");
            cout << endl;
            cout << "             -Display extras list-              " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            topping = get.getToppingList(extraPick);    /// Gets the extra topping list from service
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << topping[i]; /// prints out the list on the screen
            }
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        /// Sub ui to input new extras
        else if(input == '2'){
            while(true) {
                system("cls");
                cout << endl;
                cout << "              -Input new extras-                " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| Name: ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top); /// validate the name
                    cout << "| Price: ";
                    cin >> price;
                    try {
                       validate.validateNum(price); /// validate the price
                        get.addTopping(top, price, extraPick);  /// if validated, added to the extra list
                        break;
                    }
                    catch(InvalidNumExceptions e){  /// number exception error message

                        cout << e.getMessage() << endl;
                    }
                }
                catch(InvalidNameException e){          /// name exception error message
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        /// UI to remove extras from the list
        else if(input == '3'){
            while(true){
                string answer = "";
                unsigned int number = 0;
                system("cls");
                cout << endl;
                cout << "            -Remove extras from list-           " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| " << endl;
                topping = get.getToppingList(extraPick);
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << "| " << i+1 << ". " << topping[i].getName() << endl;     /// this is the same as displaying extras list
                }                                                       /// helps to find the item you wan't to remove
                cout << "| " << endl;
                cout << "| '0' Will remove nothing" << endl;
                cout << "| What extras would you like to remove? ";
                cin >> answer;
                stringstream sin(answer);                   
                sin >> number;                                 
                if(number > 0 && number <= topping.size()) {        /// this picks the number of the list of toppings
                    top = topping[number-1].getName();              /// puts the name of picked topping to varialbe top
                    get.removeTopping(top, extraPick);           /// goes to service to remove topping from list
                    cout << "| Extra succesfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else if(number == 0) {  /// to go back and remove nothing, and display notification
                    cout << "| Nothing removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else {  ///  error if input is wrong
                    cout << "| Invalid Input" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}

/// UI to manage locations
void Manager_ui::manageLocationUI(){
    char input = '\0';
     PizzaService get;  /// get variable of PizzaService class
     Validate validate; /// validate variable of Validate class
    vector <string> locations;  /// location vector of string type
    string location;

    while(true) {
        system("cls");
        cout << endl;
        cout << "         -Manager - Location management-        " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display locations list " << endl;
        cout << "| '2' Input new locations to list" << endl;
        cout << "| '3' Remove locations from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;
        /// To display the list of locations
        if(input == '1') {
            system("cls");
            cout << endl;
            cout << "            -Display locations list-            " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "|" << endl;
            locations = get.getLocation();      /// get the list from the service class
            for(unsigned int i = 0; i < locations.size(); i++) {
                cout << "| Address " << i+1 << ": " << locations[i] << endl;
            }       /// prints out the locations to the screen
            cout << "|" << endl;
            cout << "| ";
            system("pause");
        }
        /// UI to input new locations
        else if(input == '2'){
            while(true){
                system("cls");
                cout << endl;
                cout << "             -Input new locations-              " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| Input location and address number" << endl;
                cout << "| Or input location only" << endl;
                cout << "| " << endl;
                cout << "| Address: ";
                cin.ignore();
                getline(cin, location);
                try {   /// to validate the name of the location (location and address number / or just location)
                    validate.validateLocation(location);
                    get.addLocation(location);  /// if it validates, it writes to the location list
                    cout << "| Location succesfully added" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                catch(InvalidLocationException e){  /// else it prints out location exception error message
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        /// UI to remove location from a list
        else if(input == '3'){
            while(true){
                system("cls");
                string answer = "";
                unsigned int number = 0;
                cout << endl;
                cout << "          -Remove location from list-           " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "|" << endl;
                locations = get.getLocation();
                for(unsigned int i = 0; i < locations.size(); i++) {
                    cout << "| " << i+1 << ": " << locations[i] << endl;    /// gets the list and displays the list
                }
                cout << "|" << endl;
                cout << "| '0' Will remove nothing" << endl;
                cout << "| What location would you like to remove? ";
                cin >> answer;
                stringstream sin(answer);                   
                sin >> number;                                 
                if(number > 0 && number <= location.size()) {        /// this picks the number of the list of location
                    location = locations[number-1];              /// puts the name of picked location to varialbe top
                    get.removeLocation(location);           /// goes to service to remove location from list
                    cout << "| Item succesfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else if(number == 0) {  /// to go back and remove nothing, and display notification
                    cout << "| Nothing removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else {  ///  error if input is wrong
                    cout << "| Invalid Input" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl << endl;
            cout << "| ";
            system("pause");
        }
    }
}

/// UI manager to manage the pizza setting (sauce, crust and size)
void Manager_ui::manageSettingUI() {
    char input = '\0';
    int pick = 0;
    Validate validate;  /// validate variable of the Validate class
    TopService get; /// get variable of TopService class
    vector <Toppings> topping;  /// topping vector of Toppings class
    string top = "";
    string price = "";

    while(true) {
        system("cls");
        cout << endl;
        cout << "   -Manager - Crust, Sauce and Size management- " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|  " << endl;
        cout << "| '1' Display list " << endl;
        cout << "| '2' Input new item to list" << endl;
        cout << "| '3' Remove item from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;
        /// to display the list of crust, sauce or size
        if(input == '1') {
            system("cls");
            pick = crustSauceSize();   /// this function is a submenu that picks (sauce, crust or size)
            cout << endl;
            cout << "                -Display list-                  " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            topping = get.getToppingList(pick); /// gets the list from the topping, (pick) is either crust, size or sauce
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << topping[i]; /// prints out the list to the screen
            }
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        /// UI to input new item on the list
        else if(input == '2'){
            while(true){
                system("cls");
                pick = crustSauceSize(); // 2 - crust 4 - sauce 3 - size
                string name[5] = {"", "", "crust", "size", "sauce"};    /// name of the picked item, to be displayed on the menu header
                system("cls");
                cout << endl;
                cout << "               -Input new " << name[pick] << "-"<< endl;   /// displays the picked item to input
                cout << "------------------------------------------------" << endl;
                cout << "|Name : ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top); /// validates the name
                    cout << "| Price: ";
                    cin >> price;
                    try {
                        validate.validateNum(price);     /// validates the price
                        get.addTopping(top, price, pick);
                        cout << "| " << name[pick] << " successfully added" << endl;    /// if it validates everything
                        cout << "| ";
                        system("pause");
                        break;
                    }
                    catch (InvalidNumExceptions e){ /// get the invalid number exception error message
                        cout << e.getMessage() << endl;
                        break;
                    }
                }
                catch (InvalidNameException e){
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '3'){
            while(true) {
                system("cls");
                pick = crustSauceSize();
                system("cls");
                string answer = "";
                unsigned int number = 0;
                cout << endl;
                cout << "            -Remove item from list-             " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "|" <<  endl;
                topping = get.getToppingList(pick);
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << "| " << i+1 << ". " << topping[i].getName() << endl;     /// this is the same as displaying extras list
                }                                                       /// helps to find the item you wan't to remove
                cout << "| " << endl;
                cout << "| '0' Will remove nothing" << endl;
                cout << "| What item would you like to remove? ";
                cin >> answer;
                stringstream sin(answer);                   
                sin >> number;                                 
                if(number > 0 && number <= topping.size()) {        /// this picks the number of the list of toppings
                    top = topping[number-1].getName();              /// puts the name of picked topping to varialbe top
                    get.removeTopping(top, pick);           /// goes to service to remove topping from list
                    cout << "| Item succesfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else if(number == 0) {  /// to go back and remove nothing, and display notification
                    cout << "| Nothing removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                else {  ///  error if input is wrong
                    cout << "| Invalid Input" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "Wrong input, please try again" << endl << endl;
        }
    }
}

/// menu to view total sales number / view old delivered orders / view average order price
void Manager_ui::manageSalesUI() {
    char input = '\0';  /// to input in the submenu
    PizzaService sales_numbers; ///  makes a variable of PizzaService class
    vector<Order> old_orders = sales_numbers.getOldOrders();   /// makes a vector of Order class called old orders, pulls old orders from sales_numbers
    int totalSales = sales_numbers.TotalSales();    /// total sales number
    int averageSales = sales_numbers.AverageOrderPrice();   /// average sales number
    
    while(true){    /// submenu
        system("CLS");
        cout << endl;
        cout << "        -Manager - View sales and orders-       " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display delivered orders list " << endl;
        cout << "| '2' View total income numbers" << endl;
        cout << "| '3' Average order numbers" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input; 
        if (input == '1'){  /// to view old orders that have been delivered loops through the list
            system("cls");
            for(unsigned int i = 0; i < old_orders.size();i++){
                cout << "|          Order Number : " << i+1 << endl;
                cout << "| " << old_orders[i];
                cout << "|-----------------------------------------------" << endl;
                cout << "| ";
                system("pause");
            }
        }
        else if(input =='2') {  /// submenu to view total sales numbers
            system("cls");
            cout << endl;
            cout << "        -Manager - total income numbers-        " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "|" <<endl;
            cout << "| Total sales numbers :" << totalSales << endl;
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        else if (input == '3') {    /// submenu to view average order sales number
            system("cls");
            cout << endl;
            cout << "        -Manager -Average order numbers-        " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "|" <<endl;
            cout << "| Total average order numbers :" << averageSales << endl;
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        else if( input == '4') {    /// goes back to manager menu
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl;  /// throws an error if wrong input
            cout << "| ";
            system("pause");
            system("cls");
        }
    }
}
/// Submenu that picks the sauce, crust or size
int Manager_ui::crustSauceSize() {
    char input = '0';
    int pick = 0;
        while(true) {
        cout << endl;
        cout << "      -Which one would you like to manage?-     " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "|  " << endl;
        cout << "| 1. Crust" << endl;
        cout << "| 2. Sauce" << endl;
        cout << "| 3. Size" << endl;
        cout << "| 4. to Exit" << endl;
        cout << "| " << endl;
        cout << "| Input : ";
        cin.ignore();
        cin >> input;

        if(input == '1') {
            pick = crustPick;   /// enum
            system("cls");
            break;
        }
        else if(input == '2') {
            pick = saucePick;   /// enum
            system("cls");
            break;
        }
        else if(input == '3') {
            pick = sizesPick;   /// enum
            system("cls");
            break;
        }
        else if (input == '4') {
            system("CLS");
            manageSettingUI();
        }
        else {
            system("CLS");
            cout << "| Wrong input, please try again" << endl;
        }
    }
    return pick;
}
