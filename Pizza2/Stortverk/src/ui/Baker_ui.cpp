#include "Baker_ui.h"


void Baker_ui::bakerMainUI() {          ///Pretty basic if/else commands in this function, to summarize we are figuring out which location the baker is located at and what
                                        ///he is doing at that location.
    char answer = '\0';

    while (true)
    {
        cout << "                Bakers Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What is you location? " << endl;
        cout << "| '1' to go to location 1" << endl << "| '2' to go to location 2" << endl << "| '3' to Quit" << endl;
        cin >> answer;

        if (answer == '1')
        {
            system("CLS");
            while (true)
            {
                cout << "---Goes to location 1---" << endl;
                cout << "| What would you like to do at location 1?" << endl;
                cout << "| '1' to get a list of all pending orders at location 1" << endl << "| '2' to get a specific order up" << endl << "| '3' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')
                {
                    system("CLS");
                    cout << "---Getting a list of all orders for location 1---" << endl;
                }
                else if (answer == '2')
                {
                    system("CLS");
                    char answer = '\0';

                    while (true)
                    {
                        cout << "| What would you like to do about that order?" << endl;
                        cout << "| '1' to mark an order \"In the making\"" << endl << "| '2' to mark an order Ready" << endl << "| '3' to Quit" << endl;

                        cin >> answer;
                        cout << endl;

                        if (answer == '1')
                        {
                            system("CLS");
                            cout << "---Marking an order \"In the making\"---" << endl;
                        }
                        else if (answer == '2')
                        {
                            system("CLS");
                            cout << "---Marking an order Ready---" << endl;
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
        else if (answer == '2')
        {
            system("CLS");
            char answer = '\0';

            while (true)
            {
                cout << "---Goes to location 2---" << endl;
                cout << "| What would you like to do at location 2?" << endl;
                cout << "| '1' to get a list of all pending orders for location 2" << endl << "| '2' to get a specific order up" << endl << "| '3' to Quit" << endl;

                cin >> answer;
                cout << endl;

                if (answer == '1')
                {
                    system("CLS");
                    cout << "---Getting a list of all orders for location 2---" << endl;
                }
                else if (answer == '2')
                {
                    system("CLS");
                    char answer = '\0';

                    while (true)
                    {
                        cout << "| What would you like to do about that order?" << endl;
                        cout << "| '1' to mark an order \"In the making\"" << endl << "| '2' to mark an order Ready" << endl << "| '3' to Quit" << endl;

                        cin >> answer;
                        cout << endl;

                        if (answer == '1')
                        {
                            system("CLS");
                            cout << "---Marking an order \"In the making\"---" << endl;
                        }
                        else if (answer == '2')
                        {
                            system("CLS");
                            cout << "---Marking an order Ready---" << endl;
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
