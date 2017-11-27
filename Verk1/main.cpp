#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string st;
    ifstream fin;

    fin.open("textFile.txt");
    if(fin.is_open()){
        while(!fin.eof()){
            fin >> st;
            cout << st << endl;
        }
        fin.close();
    }
    else{
        cout << "Unable to read from file!" << endl;
    }



    return 0;
}
