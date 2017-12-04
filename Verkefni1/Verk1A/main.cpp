#include <iostream>     //input output stream to the screen
#include <fstream>      //input output from file
#include <string>       //to manage strings with whitespace

using namespace std;    //For cout/cin to work


int main()
{
    string st;			// string variable to hold input from file
    ifstream fin;		// input file stream variable to open the file
    char input;			// character variable to hold Y/N input

    fin.open("textFile.txt");	                // input file stream var will open textFile.txt	
    if(fin.is_open()){                          // if statement, if fin is open
        while(!fin.eof() && input != 'n'){      // if fin is open, it goes into a while loop, conditions are 
                                                // that if it has not read to the end of file, and the input is not 'n'
            for(int i = 0; i < 10; i++){        // a for-loop to iterate through 10 instances of the file
                getline(fin, st);               // this gets the whole line, puts it temp. in a string, 
                cout << st << endl;             // outputs the string to the screen
                if(fin.eof()){                  // if the conditions are that we read to the end of file, loop stops
                    break;                      //stop loop
                }
            }
            input = '\0';                                       // nulls out the input
            while(input != 'n' && input != 'y'){                //another inner while loop, conditions if input is not 'n' or 'y'
                cout << "Do you wish to continue (y/n)? ";      //ask the user if he wan't to continue, input yes or no
                cin >> input;                                   //the input for y/n
                if(input != 'n'&& input != 'y'){                //if input is not y/n
                    cout << "Invalid input" << endl;            //Error message for invalid input
                }
            }

        }
        fin.close();        // fin will close textFile.txt
    }
    else{
        cout << "Unable to read from file!" << endl;            //Error message if fin can't find or read the file
    }

    return 0;
}
