#include "Main_ui.h"
#include "Validate.h"
//#include "InvalidNameExc.h"

Main_ui::Main_ui()
{
    //ctor
}

void Main_ui::main_menu(){
    char input = '\0';

    while(true) {
        cout << "          This is a salary registry menu           " << endl;
        cout << "             Choose following things               " << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "| 1. Add an employee to the salary registry       |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 2. Get monthly salary records from an employee  |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 3. Get yearly salary from an employee           |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 4. Get the highest paid employee by year        |" << endl;
        cout << "|                                                 |" << endl;
        cout << "| 5. Quit the program                             |" << endl;
        cout << "|                                                 |" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "| Please input a number : ";
        cin >> input;
        if (input == '1') {
            system("CLS");
            addEmplMenu();
        }
        else if(input == '2') {
            system("CLS");
            getRcrdMenu();
        }
        else if(input == '3'){
            system("CLS");
            getYrPayMenu();
        }
        else if(input == '4') {
            system("CLS");
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
    string input_ch;
    int input = 0;
    string tmpName;
    string tmpSSN;
    string tmpSalary;
    string tmpMonth, tmpYear;
    cout << "                                                   " << endl;
    cout << "    Here you can add employees to the registry     " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                  " << endl;

    while(true){
        cout << "| How many employees do you wan't to add? (max 10): ";
        cin >> input_ch;
        try {
            (validate.validateInput(input_ch));
            stringstream sin1(input_ch);
            sin1 >> input;
            break;
        }
        catch(InvalidInputExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    for(int i = 0; i < input; i++){

        while(true){
            cout << "| Enter a name: ";
            cin.ignore();
            getline(cin, tmpName);
            try{
                (validate.validateName(tmpName));
                break;
            }
            catch(InvalidNameExc exc){
                cout << exc.getMessage() << endl;
            }
        }
        while(true) {
            cout << "| Social Security Number (10 digits only): ";
            cin >> tmpSSN;
            try {
                (validate.validateSSN(tmpSSN));
                break;
            }
            catch (InvalidSsnExc exc) {
                cout << exc.getMessage() << endl;
            }
        }
        while(true) {
            cout << "| Enter monthly salary: ";
            cin >> tmpSalary;
            try {
                (validate.validateSalary(tmpSalary));
                break;
            }
            catch (InvalidSalaryExc exc) {
                cout << exc.getMessage() << endl;
            }
        }
        while(true) {
            cout << "| Enter a month (1 - 12): ";
            cin >> tmpMonth;
            try {
                (validate.validateMonth(tmpMonth));
                break;
            }
            catch(InvalidMonthExc exc) {
                cout << exc.getMessage() << endl;
            }
        }
        while(true) {
            cout << "| Enter a year :";
            cin >> tmpYear;
            try {
                (validate.validateYear(tmpYear));
                break;
            }
            catch(InvalidYearExc exc) {
                cout << exc.getMessage() << endl;
            }
        }
    Service newEmployee;
    newEmployee.writeEmployeeInFile(tmpName, tmpSSN, tmpSalary, tmpMonth, tmpYear);
        if(input > 1) {
            cout << "|" << endl;
            cout << "| Please input another employee: " << endl;
            cout << "|" << endl;
        }
    }
system("CLS");
}

void Main_ui::getRcrdMenu() {
    string ssn;
    string month;
    string year;
    Validate validate;
    cout << "                                                         " << endl;
    cout << "  Here you get the monthly salary record of an employee  " << endl;
    cout << "---------------------------------------------------------" << endl;

    while(true) {
        cout << "| Social Security Number (10 digits only): ";
        cin >> ssn;
        try {
            (validate.validateSSN(ssn));
            break;
        }
        catch (InvalidSsnExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    while(true) {
        cout << "| Enter a month (1 - 12): ";
        cin >> month;
        try {
            (validate.validateMonth(month));
            break;
        }
        catch (InvalidMonthExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    while(true) {
        cout << "| Enter a year :";
        cin >> year;
        try {
            (validate.validateYear(year));
            break;
        }
        catch (InvalidYearExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    Service get;
    Employee employee = get.findEmployeeMonth(ssn, month, year);
    cout << "| Employee: " << endl << employee;
    system("PAUSE");
    system("CLS");
}

void Main_ui::getYrPayMenu(){
    string ssn;
    string year;
    Validate validate;
    Service get;
    cout << "                                                         " << endl;
    cout << "  Here you get the yearly sarary from an employee        " << endl;
    cout << "---------------------------------------------------------" << endl;

    while(true) {
        cout << "| Social Security Number (10 digits only): ";
        cin >> ssn;
        try {
            (validate.validateSSN(ssn));
            break;
        }
        catch (InvalidSsnExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    while(true) {
        cout << "| Enter a year :";
        cin >> year;
        try {
            (validate.validateYear(year));
            break;
        }
        catch (InvalidYearExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    Employee employee;
    employee = get.findEmployeeYearlySalary(ssn, year);
    cout << "Employee: " << endl << employee;
    system("PAUSE");
    system("CLS");
}

void Main_ui::getHiPayMenu(){
    string ssn;
    string year;
    Validate validate;
    Service get;
    cout << "                                                         " << endl;
    cout << "  Here you get the highest paid employee by year         " << endl;
    cout << "---------------------------------------------------------" << endl;

    while(true) {
        cout << "| Enter a year :";
        cin >> year;
        try {
            (validate.validateYear(year));
            break;
        }
        catch (InvalidYearExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
//    Employee employee = get.findHighestEmployeeYearly(year);
//    cout << "Employee: " << endl << employee;
    system("PAUSE");
    system("CLS");

}
/*
Service newEmployee
newEmployee.writeEmployeeInFile(string name, string ssn, string salary, string month, string year);
*/
