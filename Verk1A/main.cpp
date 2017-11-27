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
            for(int i = 0; i < 10; i++){
                getline(fin, st);
                cout << st << endl;
                if(fin.eof()){
                    break;
                }
            }
            input = '0';
            while(input != 'n' && input != 'y'){
                cout << "Do you wish to continue (y/n)? ";
                cin >> input;
                if(input != 'n'&& input != 'y'){
                    cout << "Invalid input" << endl;
                }
            }

        }
        fin.close();
    }
    else{
        cout << "Unable to read from file!" << endl;
    }

    return 0;
}
