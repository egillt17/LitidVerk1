#include <iostream>
#include <fstream>
#include "Superhero.h"

using namespace std;

int main()
{
    int number_of_heroes = 0;
    ofstream fout;
    ifstream fin;
    // opens the text file so the program can work with it
    fout.open("Superheroes.txt", ios::app);
    //ios::app makes sure that the information is written at the bottom of the file
    //so it doesnt over write something that was already there
    cout << "How many heroes would you like to add? ";
    cin >> number_of_heroes;

    Superhero hero;
    // uses the constructor with 3 variables
    Superhero hero4("Aquaman", 25, 'w');
    fout << hero4;
    // the loop takes the hero input from the user and adds it to the text file as soon
    // as its done getting all the info from the user
    for(int i = 0; i < number_of_heroes; i++){
        cin >> hero;
        fout << hero;
    }
    // closes the text file when the program is done using it with fout
    fout.close();
    // opens the text file so that the program can read out of it
    fin.open("Superheroes.txt");
    string st;
    // checks if the program was able to find and open the file
    if(fin.is_open()){
        // the loop runs until it reaches the end of the file
        while(!fin.eof()){
            // get line gets entire lines at a time in the text file
            getline(fin, st);
            // prints out the line that was taken from the file
            cout << st << endl;
        }

    }
    else {
        // this gets printed if the program was not able to open the file
        cout << "File cannot be read! " << endl;
    }

    fin.close();
}
