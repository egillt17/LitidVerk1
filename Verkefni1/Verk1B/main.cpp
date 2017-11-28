#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string str;
    ofstream fout;
    fout.open("TextFile.txt");

    getline(cin, str);
    while (str[0] != '\\')
    {
        fout << str << endl;
        getline(cin, str);
    }

    fout.close();

    return 0;
}
