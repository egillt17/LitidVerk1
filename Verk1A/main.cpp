#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string st;
    ifstream fin;
    char input;

    fin.open("textFile.txt");
    if(fin.is_open()){
        while(!fin.eof() && input != 'n'){
            for (int i = 0; i < 10; i++) {
                getline(fin, st);
                cout << st << endl;
            }
        }
        fin.close();
    }
    else{
        cout << "Unable to read from file!" << endl;
    }



    return 0;
}
