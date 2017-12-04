#include <iostream>             //Input / output on the screen
#include "Superhero.h"          //includes the superehero class header file

using namespace std;            //to be able to use cin / cout

int main()
{
    int number_of_heroes = 0;       //to hold the number of instances of superheroes
    ofstream fout;                  //make the output to file variable named fout
    ifstream fin;                   //make the input to file variable named fin
    
    fout.open("Superheroes_b.dat", ios::binary|ios::app);       //fout opens the binary file Superheroes_b.dat file

    cout << "How many heroes would you like to add? ";          //Test to prompt how many heroes you want to add
    cin >> number_of_heroes;                                    //input the number of heroes
    Superhero *hero = new Superhero[number_of_heroes];          //makes a new dynamic variable on the heap, from a Superhero class

    for(int i = 0; i < number_of_heroes; i++){                  //for loop, to input the number of heroes, in the dynamic superhero class array
        cin >> hero[i];                                         //input heroes, uses the friend istream function in Superhero.cpp
    }
    fout.write((char*)(hero), sizeof(Superhero)*number_of_heroes);  //fout writes to the binary file, casts the data to byte, writes the byes in the size of
                                                                    //the Superhero class, multiplied by the number of superheroes.
    fout.close();                                                   //fout closes the file, after it writes the data.

    fin.open("Superheroes_b.dat", ios::binary);                     //fin opens the Superheroes_b.dat file, and reads it as a binary file (ios::binary)
    fin.seekg(0, fin.end);                                          //this function finds the end of the file
    int size_of = fin.tellg() / sizeof(Superhero);                  //this int variable gets the size of the data, divided by the size of the Superhero class
    fin.seekg(0, fin.beg);                                          //this function lets you begin the reading of the file from the beginning
    Superhero *hero2 = new Superhero[size_of];                      //We make a new class of Superhero, as a dynamic array, we are not using the one before.
    if(fin.is_open()){                                              //if-else statement, conditions if fin is open it will then...
            fin.read((char*)(hero2), sizeof(Superhero)*size_of);    //read the binary data from (Superheroes_b_dat) in the size of bytes, as the size of the
                                                                    //Superhero class, multiplied by the size of the file into 'hero2' dynamic array
    }
    else {
        cout << "File cannot be read! " << endl;                    //Error message if the file cannon be read, or invalid file
    }
    for(int i = 0; i < size_of; i++){                               //hero2 dynamic array, is now full of data, this for loop outputs the data to the screen
        cout << hero2[i];                                           //as the overloaded friend ostream function does in Superhero.cpp
    }

    fin.close();            //this closes the file, 
    delete[] hero;          // Delete hero from the Heap
    delete[] hero2;         // Delete hero2 from the Heap.
    return 0;
}

