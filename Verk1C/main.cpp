#include <iostream>
#include "Superhero.h"

using namespace std;

int main()
{
    Superhero hero;
    int number_of_heroes = 0;
    ofstream fout;
    ifstream fin;
    string st;
    fout.open("Superheroes.txt", ios::app);

    cout << "How many heroes would you like to add? ";
    cin >> number_of_heroes;

    for(int i = 0; i < number_of_heroes; i++){
        cin >> hero;
        fout << hero;
    }

    fin.open("Superheroes.txt");
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, st);
            cout << st << endl;
        }
    }

    fout.close();
    return 0;
}

