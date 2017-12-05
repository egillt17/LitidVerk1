#include "Main_ui.h"
#include "Service.h"
#include "Validate.h"
#include <string>

#include <iostream>

using namespace std;

Main_ui::Main_ui()
{
    //ctor
}

void Main_ui::main_menu(){
    char input = '\0';
    
    while(true) {
        cout << "        This is a salary registry menu             " << endl;
        cout << "           Choose following things                 " << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "| 1. Add an employee to the salary registry       |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 2. Get salary records from an employee          |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 3. Get yearly salary from an employee           |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 4. Get the highest paid employee by year        |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 5. quit the program                             |" << endl;
        cout << "|                                                 |" << endl;
        cout << "---------------------------------------------------" << endl;
        cin >> input;
        if (input == '1') {
            addEmplMenu();
        }
        else if(input == '2') {
            getRcrdMenu();
        }
        else if(input == '3'){
            getYrPayMenu();
        }
        else if(input == '4') {
            getHiPayMenu();
        }
        else if (input == '5') {
            break;
        }
        else {
            cout << "Invalid input -- try again" << endl;
        }
        
    }
    
    
}

void Main_ui::addEmplMenu(){

    Validate validate;
    int input;
    string tmpName;
    string tmpSSN;
    string tmpSalary;
    string tmpMonth, tmpYear;
    cout << "How many employees do you wan't to add? :";
    cin >> input;
    for(int i = 0; i < input; i++){
            
        while(true){
            cout << "Enter a name: ";
            cin.ignore();
            getline(cin, tmpName);
            cout << tmpName;
            if (!validate.validateName(tmpName)){
                cout << "invalid input -- try again" << endl;
            }
            else{
                cout << endl;
                break;
            }
        }
        while(true) {
            cout << "Social Security Number (10 digits only): ";
            cin >> tmpSSN;
            if(!validate.validateSSN(tmpSSN)) {
                cout << "invalid input -- try again" << endl;
            }
            else {
                cout << endl;
                break;
            }
        }
        while(true) {
            cout << "Enter monthly salary: ";
                cin >> tmpSalary;
            if(!validate.validateSalary(tmpSalary)) {
                cout << "invalid input -- try again" << endl;
            }
            else {
                cout << endl;
                break;
            }
        }
        while(true) {
            cout << "Enter a mont and a year: ";
                cin >> tmpMonth >> tmpYear;
            if(!validate.validateMonth(tmpMonth) || !validate.validateYear(tmpYear)) {
                cout << "invalid input -- Month (1 - 12) Year (2017)"  << endl;
            }
            else {
                cout << endl;
                break;
            }
        }
        cout << tmpName << endl;
        cout << tmpSSN << endl;
        cout << tmpSalary << endl;
        cout << tmpMonth << "/" << tmpYear << endl;
    }

}

void Main_ui::getRcrdMenu() {

}

void Main_ui::getYrPayMenu(){

}

void Main_ui::getHiPayMenu(){

}
/*
Service newEmployee
newEmployee.writeEmployeeInFile(string name, string ssn, string salary, string month, string year);
*/
