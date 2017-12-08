#include "Sales_ui.h"

void Sales_ui::salesMainUI()
{
    char answer = '\0';

    while (true)
    {
        cout << "| Hello Sales Person!" << endl;
        cout << "| What would you like to do? " << endl;
        cout << "| '1' to set up a new order" << endl << "| '2' to add pizzas (and other things) to order" << endl << "| '3' to get the total cost of an order" << endl
             << "| '4' to set an order sent or picked up" << endl << "| '5' to mark an order paid for" << endl << "| '6' to mark a pizza to a specific delivery place" << endl
             << "| '7' to  Add comments" << endl << "| '8' to Quit" << endl;;

        cin >> answer;
        cout << endl;

        if (answer == '1')
        {
            system("CLS");
            cout << "---Setting up a new order---" << endl;
        }
        else if (answer == '2')
        {
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
                    cout << "| Wrong input, please try again" << endl;
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
        }
        else if (answer == '8')
        {
            system("CLS");
            break;
        }
        else
        {
            system("CLS");
            cout << "| Wrong input, please try again" << endl;
        }
    }
}
