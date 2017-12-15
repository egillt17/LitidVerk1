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
        cout << "| '6' to exit to the Main menu" << endl;
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

void Manager_ui::managePizzaUI() {
    char input = '\0';
    PizzaService pizza_specials;
    
    while(true){
        system("CLS");
        cout << "          -Manager - Pizza management-          " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display Pizza list " << endl;
        cout << "| '2' Input new Pizza to list" << endl;
        cout << "| '3' Remove Pizza from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;
        if (input == '1'){
            system("cls");
            cout << endl;
            cout << "              -Display Pizza list-              " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            vector<Pizza> tmpPizzas = pizza_specials.getPizzaSpecials();
            for(unsigned int i = 0; i < tmpPizzas.size(); i++) {
                cout << "|          Pizza number: " << (i+1) << endl;
                cout << tmpPizzas[i];
                cout << "|-----------------------------------------------" << endl;
            }
            cout << "| ";
            system("PAUSE");
        }
        else if(input == '2') {
            Validate validate;
            system("cls");
            string answer = "";
            string price = "";
            unsigned int number;
            unsigned int newPrice;
            int sizePrice = 0;
            int saucePrice = 0;
            int crustPrice = 0;
            int toppingPrice = 0;
            int totalPrice = 0;
            bool specialPrice = false;
            Pizza tmpPizza;
            TopService get;
            vector <Toppings> topping;
            topping = get.getToppingList(1);
            while(true){
                system("cls");
                if(!specialPrice) {
                    totalPrice = sizePrice + saucePrice + crustPrice + toppingPrice;
                }
                tmpPizza.setPrice(totalPrice);
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
                    topping = get.getToppingList(3);
                    for(unsigned int i = 0; i < topping.size(); i++) {
                        cout << "| " << (i+1) << ". " << topping[i];
                    }
                    cout << "| Pick a size: ";
                    cin >> answer;
                    stringstream sin(answer);                   
                    sin >> number;                              
                    if(number > 0 && number <= topping.size()) {
                        tmpPizza.setSize(topping[number-1].getName());
                        sizePrice = topping[number-1].getPrice();         
                    }
                    else {
                        cout << "| Invalid Input" << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if(input == '2'){
                    cout << "                  -Set Crust-                    " << endl;
                    cout << "------------------------------------------------" << endl;
                    topping = get.getToppingList(2);
                    for(unsigned int i = 0; i < topping.size(); i++) {
                        cout << "| " << (i+1) << ". " << topping[i];
                    }
                    cout << "| Pick a crust: ";
                    cin >> answer;
                    stringstream sin(answer);                   
                    sin >> number;
                    if(number > 0 && number <= topping.size()){
                        tmpPizza.setCrust(topping[number-1].getName());
                        crustPrice = topping[number-1].getPrice();
                    }
                    else {
                        cout << "| Invalid Input" << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if (input == '3') {
                    cout << "                  -Set Sauce-                    " << endl;
                    cout << "------------------------------------------------" << endl;
                    topping = get.getToppingList(4);
                    for(unsigned int i = 0; i < topping.size(); i++) {
                        cout << "| " << (i+1) << ". " << topping[i];
                    }
                    cout << "| Pick a sauce: ";
                    cin >> answer;
                    stringstream sin(answer);                   ///Works the same way as the chunk of code above but instead changes the sauce and it's price
                    sin >> number;
                    if(number > 0 && number <= topping.size()){
                        tmpPizza.setSauce(topping[number-1].getName());
                        saucePrice = topping[number-1].getPrice();
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
                    topping = get.getToppingList(1);
                    for(unsigned int i = 0; i < topping.size(); i++) {
                        cout << "| " << (i+1) << ". " << topping[i];
                    }
                    cout << "| Pick a Topping: ";
                    cin >> answer;
                    stringstream sin(answer);                  
                    sin >> number;
                    if(number > 0 && number <= topping.size()){
                        tmpPizza.addTopping(topping[number-1]);
                        toppingPrice = tmpPizza.getToppingPrice();
                    }
                    else {
                        cout << "| Invalid Input" << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if (input == '5') {
                    tmpPizza.clearTopping();                       
                    toppingPrice = tmpPizza.getToppingPrice();
                }
                else if (input == '6') {
                    cout << "| Input special price: ";
                    cin >> price;
                    try {
                        validate.validateNum(price);
                        stringstream sin(price);
                        sin >> newPrice;
                        specialPrice = true; 
                        totalPrice = newPrice;
                        cout << "| New price set successfully" << endl;
                        cout << "| ";
                        system("pause");
                    }
                    catch (InvalidNumExceptions e) {
                        cout << e.getMessage() << endl;
                        cout << "| ";
                        system("pause");
                    }
                }
                else if(input == '7'){
                    if(!tmpPizza.getSize().compare("Not picked")) {
                        cout << "| You have to pick a size to add the pizza" << endl;     
                        system("pause");
                        break;
                    }
                    else {
                    pizza_specials.addPizzaSpecialToList(tmpPizza);
                    cout << "| Pizza successfully added to list" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                    }
                }
                else if(input == '8') {
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '3') {
            vector<Pizza> tmpPizzas = pizza_specials.getPizzaSpecials();
            
            system("cls");
            string answer = "";
            unsigned int number = 0;
            cout << endl;
            cout << "             -Remove Pizza from list-           " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            
            for(unsigned int i = 0; i < tmpPizzas.size(); i++) {
                cout << "|          Pizza number: " << (i+1) << endl;
                cout << tmpPizzas[i];
                cout << "|-----------------------------------------------" << endl;
                
            }
            cout << "|'0' to exit" << endl;
            cout << "| Pick a pizza to remove: ";
            cin >> answer;
                
            stringstream sin(answer);                   
            sin >> number;                             
            if(number > 0 && number <= tmpPizzas.size()) {
                    tmpPizzas.erase (tmpPizzas.begin()+(number-1));
                    pizza_specials.reWritePizzaService(tmpPizzas);
                    cout << "| Pizza successfully removed" << endl;
                    cout << "| ";
                    system("pause");
            }
            else if (number == 0) {
                cout << "| Nothing removed" << endl;
                cout << "| ";
                system("pause");
            }
            else {
                cout << "| Invalid Input " << endl;
                cout << "| ";
                system("pause");
            }
        }
        else if(input == '4') {
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
            while(true){
                system("cls");
                cout << endl;
                cout << "           -Remove topping from list-         " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| " << endl;
                topping = get.getToppingList(toppingsPick); /// display the list of toppings, easier to write the topping to remove
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << topping[i];
                }
                cout << "| " << endl;
                cout << "| What topping would you like to remove? ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    if(!get.removeTopping(top, toppingsPick)) { /// If name is validated, but don't find the right topping
                        cout << "| Topping not found!" << endl; /// error
                        cout << "| ";
                        system("pause");
                        break;
                    }
                    cout << "| Successfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                catch(InvalidNameException e) { /// catches an error, if the name is wrong, (only letters)
                    cout << e.getMessage() << endl;
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
                cout << "| " << topping[i]; /// prints out the list on the screen
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
                system("cls");
                cout << endl;
                cout << "            -Remove extras from list-           " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| " << endl;
                topping = get.getToppingList(extraPick);
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << "| " << topping[i];                         /// this is the same as displaying extras list
                }                                                       /// helps to find the item you wan't to remove
                cout << "| " << endl;
                cout << "| What extras would you like to remove? ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    if(!get.removeTopping(top, extraPick)) {    /// validates the name , if is validated
                        cout << "| Extra not found" << endl;    /// but not found it displays an error
                        cout << "| ";
                        system("pause");
                        break;
                    }
                }
                catch(InvalidNameException e){  /// if name is not validated this name exception catches an error
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                cout << "| Successfully removed" << endl;
                cout << "| ";
                system("pause");
                break;
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
                cout << endl;
                cout << "          -Remove location from list-           " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "|" << endl;
                locations = get.getLocation();
                for(unsigned int i = 0; i < locations.size(); i++) {
                    cout << "| Address " << i+1 << ": " << locations[i] << endl;    /// gets the list and displays the list
                }
                cout << "|" << endl;
                cout << "| What location would you like to remove? ";
                cin.ignore();
                getline(cin, location);
                try {               /// validates the name to remove,
                    validate.validateLocation(location);    /// if name of location is valid but
                    if(!get.removeLocation(location)) { ///  location is not found, prints error
                        cout << "| Location not found" << endl;
                        cout << "| ";
                        system("pause");
                        break;
                    }   /// if it validates, and found, removes it.
                    cout << "| Location successfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                catch(InvalidLocationException e) { /// prints out location exception error message from validation class
                    cout << e.getMessage() << endl;
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
                cout << endl;
                cout << "            -Remove item from list-             " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "|" <<  endl;
                topping = get.getToppingList(pick);                 /// print list of toppings from picked list
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << topping[i];     /// prints it out on the screen
                }
                cout << "|" << endl;
                cout << "| What item would you like to remove? ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top); /// validates the name, if true,
                    if(!get.removeTopping(top, pick)) { /// but can't find it on the list, display error
                        cout << "| Item not found" << endl;
                        system("pause");
                        break;
                    }
                    cout << "| Item successfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                catch(InvalidNameException e) { /// for invalid name error exception message
                    cout << e.getMessage() << endl;
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

/// Submenu that picks the sauce, crust or size
/// that picks from the
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
