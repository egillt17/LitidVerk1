#include <iostream>
#include "Superhero.h"

using namespace std;

int main()
{
    int number_of_heroes = 0;
    ofstream fout;
    ifstream fin;
    fout.open("Superheroes_b.dat", ios::binary|ios::app);

    cout << "How many heroes would you like to add? ";
    cin >> number_of_heroes;

    Superhero *hero = new Superhero[number_of_heroes];

    for(int i = 0; i < number_of_heroes; i++){
        cin >> hero[i];
    }
    fout.write((char*)(hero), sizeof(Superhero)*number_of_heroes);
    fout.close();

    fin.open("Superheroes_b.dat", ios::binary);
    fin.seekg(0, fin.end);
    int size_of = fin.tellg() / sizeof(Superhero);
    fin.seekg(0, fin.beg);
    Superhero *hero2 = new Superhero[size_of];
    if(fin.is_open()){
            fin.read((char*)(hero2), sizeof(Superhero)*size_of);
    }
    else {
        cout << "File cannot be read! " << endl;
    }
    for(int i = 0; i < size_of; i++){
        cout << hero2[i];
    }

    fin.close();
    delete[] hero;
    delete[] hero2;
    return 0;
}

