#include <iostream>     //To stream in and out on the screen
#include <fstream>      //to stream from file onto screen

using namespace std;    //to use cin / cout

int main()
{
    string str;                             //temporary string to that is input in TextFile.txt
    ofstream fout;                          //make the output to file stream variable 'fout'
    fout.open("TextFile.txt", ios::app);    //fout opens the TextFile.txt , if it is not already available, it will make it.
                                            //ios::app means that if the program is run again, it will append to the last line of the file
                                            //it will not overwrite , just write new lines
    getline(cin, str);          //cin will input the string, getline gets the whole line, with whitespaces too. This is just the first input
    while (str[0] != '\\')      //A while loop, conditions are if it senses the first instance in the string is the sign '\', 
    {                           // the loop will stop, and the program stops, otherwise
        fout << str << endl;    //the fout will input the string in the TextFile.txt
        getline(cin, str);      //this is after the first input, it does the same as before, but is part of the loop.
    }

    fout.close();               //fout closes the Textfile.txt file.

    return 0;
}
