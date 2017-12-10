 #include "Sales_ui.h"

void Sales_ui::salesMainUI()
{
    char answer = '\0';
    string input = "";
    Order takeOrder;

    while (true)
    {
        cout << "                Sales Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What would you like to do? " << endl;
        cout << "| '1' to set up a new order" << endl;
        cout << "| '2' to add pizzas (and other things) to order" << endl;
        cout << "| '3' to get the total cost of an order" << endl;
        cout << "| '4' to set an order sent or picked up" << endl;
        cout << "| '5' to mark an order paid for" << endl;
        cout << "| '6' to mark a pizza to a specific delivery place" << endl;
        cout << "| '7' to  Add comments" << endl;
        cout << "| '8' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer == '1')
        {
            system("CLS");
            cout << "---Setting up a new order---" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, input);
        }
        else if (answer == '2')
        {
            addPizza();
            system("CLS");
            char answer = '\0';

            while (true)
            {
                cout << "| What would you like to add to an order?" << endl;
                cout << "| '1' to set a new size or bottom to a pizza" << endl << "| '2' to see the price of one pizza in an order" << endl << "| '3' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')
                {
                    system("CLS");
                    cout << "---seting a new size or bottom to a pizza---" << endl;
                }
                else if (answer == '2')
                {
                    system("CLS");
                    cout << "---seeing the price of one pizza in an order---" << endl;
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
            cout << "---Getting the total cost of an order---" << endl;
        }
        else if (answer == '4')
        {
            system("CLS");
            cout << "---setting an order sent or picked up---" << endl;
        }
        else if (answer == '5')
        {
            system("CLS");
            cout << "---Marking an order paid for---" << endl;
        }
        else if (answer == '6')
        {
            system("CLS");
            cout << "---Marking a pizza to a specific delivery place---" << endl;
        }
        else if (answer == '7')
        {
            system("CLS");
            cout << "---Adding comments---" << endl;
            cout << "Comment: ";
            cin.ignore();
            getline(cin, input);
        }
        else if (answer == '8')
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

Pizza Sales_ui::addPizza() {
    char answer = '\0';
    unsigned int number = 0;
    TopService get;
    Pizza pizza;
    vector <Toppings> topping;
    while(true){
        system("CLS");
        topping.clear();
        cout << "                Your pizza                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << pizza;
        cout << "                Pizza menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What would you like to do? " << endl;
        cout << "| '1' set size" << endl;
        cout << "| '2' set sauce" << endl;
        cout << "| '3' set crust" << endl;
        cout << "| '4' add topping" << endl;
        cout << "| '5' Quit" << endl;

        cin >> answer;
        if (answer == '1') {
            system("CLS");
            topping = get.getToppingList(3);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            cout << "Pick a size: ";
            cin >> answer;
            number = answer - '0';
            if(number > 0 && number <= topping.size()){
                pizza.setSize(topping[number-1].getName());
            }
            else {
                cout << "no can do!" << endl;
            }
        }
        else if (answer == '2') {
            system("CLS");
            topping = get.getToppingList(4);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            cout << "Pick a sauce: ";
            cin >> answer;
            number = answer - '0';
            if(number > 0 && number <= topping.size()){
                pizza.setSauce(topping[number-1].getName());
            }
            else {
                cout << "no can do!" << endl;
            }
            system("pause");

        }
        else if (answer == '3') {
            system("CLS");
            topping = get.getToppingList(2);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            cout << "Pick a crust: ";
            cin >> answer;
            number = answer - '0';
            if(number > 0 && number <= topping.size()){
                pizza.setCrust(topping[number-1].getName());
            }
            else {
                cout << "no can do!" << endl;
            }
            system("pause");

        }
        else if (answer == '4') {
            system("CLS");
            topping = get.getToppingList(1);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            system("pause");

        }
    }

    return pizza;
}
