#include "BakerUI.h"
#include "Display.h"

BakerUI::BakerUI()
{
    //ctor
}

BakerUI::~BakerUI()
{
    //dtor
}

void BakerUI::displayBakerUI()          ///Pretty basic if/else commands in this function, to summarize we are figuring out which location the baker is located at and what
                                        ///he is doing at that location.
{
    char answer = ' ';

    while (answer != 'q' || answer == 'Q')
    {
        cout << endl << "Hello Baker!" << endl;
        cout << "What is you location? " << endl;
        cout << "'a' to go to location a" << endl << "'b' to go to location b" << endl << "'q' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer != 'q' || answer == 'Q')
        {
            if (answer == 'a' || answer == 'A')
            {
                char answer = ' ';

                while (answer != 'q' || answer == 'Q')
                {
                    cout << "---Goes to location a---" << endl;
                    cout << "What would you like to do at location a?" << endl;
                    cout << "'a' to get a list of all pending orders at location a" << endl << "'b' to get a specific order up" << endl << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q' || answer == 'Q')
                    {
                        if (answer == 'a' || answer == 'A')
                        {
                            cout << "---Getting a list of all orders for location a---" << endl;
                        }
                        else if (answer == 'b' || answer == 'B')
                        {
                            char answer = ' ';

                            while (answer != 'q' || answer == 'Q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order \"In the making\"" << endl << "'b' to mark an order Ready" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q' || answer == 'Q')
                                {
                                    if (answer == 'a' || answer == 'A')
                                    {
                                        cout << "---Marking an order \"In the making\"---" << endl;
                                    }
                                    else if (answer == 'b' || answer == 'B')
                                    {
                                        cout << "---Marking an order Ready---" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong answer, try again" << endl;
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "Wrong input, try again" << endl;
                        }
                    }
                }

            }
            else if (answer == 'b' || answer == 'B')
            {
                char answer = ' ';

                while (answer != 'q' || answer == 'Q')
                {
                    cout << "---Goes to location b---" << endl;
                    cout << "What would you like to do at location b?" << endl;
                    cout << "'a' to get a list of all pending orders for location b" << endl << "'b' to get a specific order up" << endl << "'q' to Quit" << endl;

                    cin >> answer;
                    cout << endl;

                    if (answer != 'q' || answer == 'Q')
                    {
                        if (answer == 'a' || answer == 'A')
                        {
                            cout << "---Getting a list of all orders for location b---" << endl;
                        }
                        else if (answer == 'b' || answer == 'B')
                        {
                            char answer = ' ';

                            while (answer != 'q' || answer == 'Q')
                            {
                                cout << "What would you like to do about that order?" << endl;
                                cout << "'a' to mark an order \"In the making\"" << endl << "'b' to mark an order Ready" << endl << "'q' to Quit" << endl;

                                cin >> answer;
                                cout << endl;

                                if (answer != 'q' || answer == 'Q')
                                {
                                    if (answer == 'a' || answer == 'A')
                                    {
                                        cout << "---Marking an order \"In the making\"---" << endl;
                                    }
                                    else if (answer == 'b' || answer == 'B')
                                    {
                                        cout << "---Marking an order Ready---" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong answer, try again" << endl;
                                    }
                                }
                            }

                        }
                        else
                        {
                            cout << "Wrong input, try again" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "Wrong location, try again" << endl;
            }
        }
    }
}
