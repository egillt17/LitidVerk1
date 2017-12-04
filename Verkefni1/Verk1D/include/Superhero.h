#ifndef SUPERHERO_H     //Superhero header file definition
#define SUPERHERO_H
#include <iostream>     //to be able to input output stream to screen
#include <string>       //to be able to use strings
#include <fstream>      //to be able to input / output to files in main.cpp

using namespace std;    //to use cin / cout
    

class Superhero     //Definition of the Superhero Class
{
    public:
        Superhero();        //  constructor without variables
        Superhero(string name, int age, char power);                        //constructor with variables, 
        ~Superhero();       // deconstructor
        friend istream& operator >> (istream& in, Superhero& hero);         //define the istream friend function overload
        friend ostream& operator << (ostream& out, const Superhero& hero);  //define the ostream friend function overload
        void get_hero(Superhero hero);                                      //function to make a hero with the class variable

    private:
        char _name[32];         //  var. to hold the name
        int _age;               //  var. to hold the age
        char _power;            //  var. to hold the power
};

#endif // SUPERHERO_H

