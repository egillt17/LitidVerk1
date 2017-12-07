#include "Main_ui.h"
#include "Validate.h"

///the main menu function
void Main_ui::main_menu(){
    char input = '\0';
    ///this is the main menu display
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
        cout << "Please input a number : ";
        ///if else statement for the main menu
        cin >> input;
        if (input == '1') {     /// to add a new employee menu
            system("CLS");
            addEmplMenu();
        }
        else if(input == '2') { /// to get a record of a specific employee, at a given time
            system("CLS");
            getRcrdMenu();
        }
        else if(input == '3'){    /// to get a yearly salary from an employee
            system("CLS");
            getYrPayMenu();
        }
        else if(input == '4') { /// to get the highest paid employee from a specific year
            system("CLS");
            getHiPayMenu();
        }
        else if (input == '5') {    /// quits the program
            exit(1337);
        }
        else {  ///error message if wrong input
            cout << "Invalid input -- try again" << endl;
            system("PAUSE");
            system("CLS");
        }
    }
}

/// the add employee menu
void Main_ui::addEmplMenu(){

    Validate validate;  /// to validate the variables
    /// different variables to use in this function
    string input_ch;
    int input = 0;
    string tmpName;
    string tmpSSN;
    string tmpSalary;
    string tmpMonth, tmpYear;
    cout << "                                                   " << endl;
    cout << "    Here you can add employees to the registry     " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "                                                   " << endl;

    /// this loop checks if the input, for how many employee to input
    while(true){
        cout << "How many employees do you wan't to add? (max 10): ";
        cin >> input_ch;
        try {
            (validate.validateInput(input_ch)); /// validates the input in the Validate class
            stringstream sin1(input_ch); /// this changes this string to a int
            sin1 >> input; /// puts in an empty int
            break;
        }
        catch(InvalidInputExc exc) {            /// catches the invalid message from Validate class
            cout << exc.getMessage() << endl;   /// writes out the message
        }
    }
    for(int i = 0; i < input; i++){ ///loop for number of employees to input

        while(true){ /// loop to check the name
            cout << "Enter a name: ";
            cin.ignore();   /// to ignore a whitespace
            getline(cin, tmpName);
            try{        /// this tries to validate the name in the Validate class
                (validate.validateName(tmpName));
                break;  /// goes to the next step if it validates
            }
            catch(InvalidNameExc exc){  /// get the error message from Validate class
                cout << exc.getMessage() << endl; /// prints error message out
            }
        }
        while(true) {   /// loop to check the SSN
            cout << "Social Security Number (10 digits only): ";
            cin >> tmpSSN;
            try {
                (validate.validateSSN(tmpSSN)); /// tries to check if it is valid
                break;
            }
            catch (InvalidSsnExc exc) {     /// prints out the error in the validation class
                cout << exc.getMessage() << endl;
            }
        }
        while(true) {   /// loop to check the salary
            cout << "Enter monthly salary: ";
            cin >> tmpSalary;
            try {
                (validate.validateSalary(tmpSalary));   /// tries to check if it is valid
                break;
            }
            catch (InvalidSalaryExc exc) { /// prints out the error in the validation class
                cout << exc.getMessage() << endl;
            }
        }
        while(true) {   /// loop to check the month
            cout << "Enter a month (1 - 12): ";
            cin >> tmpMonth;
            try {
                (validate.validateMonth(tmpMonth));
                break;
            }
            catch(InvalidMonthExc exc) {
                cout << exc.getMessage() << endl;
            }
        }
        while(true) {   /// loop to check the year
            cout << "Enter a year :";
            cin >> tmpYear;
            try {
                (validate.validateYear(tmpYear));
                break;
            }
            catch(InvalidYearExc exc) {
                cout << exc.getMessage() << endl;
            }
        }
    Service newEmployee;    ///makes a new employee from the service class
    newEmployee.writeEmployeeInFile(tmpName, tmpSSN, tmpSalary, tmpMonth, tmpYear);   /// this writes the to the newEmployee class all the variables
        if(input > 1) {     /// this prints out if you wan't to input more than 1 employees
            cout << endl;
            cout << "Please input another employee: " << endl;
            cout << endl;
        }
    }
system("CLS");  /// clears screen
}

/// The menu to look up an employee in records
void Main_ui::getRcrdMenu() {
    string ssn;
    string month;
    string year;
    Validate validate;


    cout << "                                                         " << endl;
    cout << "  Here you get the monthly salary record of an employee  " << endl;
    cout << "---------------------------------------------------------" << endl;

    /// this is the same as in the "input new employee" function, except it looks for the SSN, month and year
    while(true) {
        cout << "Social Security Number (10 digits only): ";
        cin >> ssn;
        try {   /// loop to input and check the SSN
            (validate.validateSSN(ssn));
            break;
        }
        catch (InvalidSsnExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    while(true) {   /// loop to input and check the month
        cout << "Enter a month (1 - 12): ";
        cin >> month;
        try {
            (validate.validateMonth(month));
            break;
        }
        catch (InvalidMonthExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    while(true) {   /// loop to input and check the year
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
    /// makes the variable get of the Service class
    Service get;
    /// makes the variable employee of the Employee class
    /// get goes into the find employee by month function, inputs the variables
    /// if it finds the specific employee, by month in the get class
    Employee employee = get.findEmployeeMonth(ssn, month, year);

    if (employee.get_name() != ""){
        cout << "Employee: " << endl << employee;         /// Here we check if the employee is accually found by checking if his name is the empty string,
        system("PAUSE");                                    ///and if thats not the case then we print out the employee
        system("CLS");
    }
    else {
        cout << "Record does not exist, exiting to main menu" << endl << endl;
        system("PAUSE");
        system("CLS");                                      ///If the employees name is in fact the emty string then an error message pops up saying the employee does not exist
    }
}

/// The menu to find the yearly salary from an employee
void Main_ui::getYrPayMenu(){
    string ssn;
    string year;
    Validate validate;
    Service get;
    cout << "                                                         " << endl;
    cout << "  Here you get the yearly sarary from an employee        " << endl;
    cout << "---------------------------------------------------------" << endl;

    /// same as in addEmplMenu(), except it inputs and checks only SSN and the year
    while(true) {
        cout << "Social Security Number (10 digits only): ";
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
        cout << "Enter a year :";
        cin >> year;
        try {
            (validate.validateYear(year));
            break;
        }
        catch (InvalidYearExc exc) {
            cout << exc.getMessage() << endl;
        }
    }
    /// makes the variable employee of the Employee class
    /// get goes into the find employee by Yearly salary function, inputs the variables
    /// if it finds the specific employee, by month in the get class
    Employee employee;
    employee = get.findEmployeeYearlySalary(ssn, year);

    if (employee.get_name() != ""){
        cout << "Employee: " << endl << employee;                 /// Here we check if the employee is accually found by checking if his name is the empty string,
        system("PAUSE");                                            ///and if thats not the case then we print out the employee
        system("CLS");
    }
    else {
        cout << "Record does not exist, exiting to main menu" << endl << endl;
        system("PAUSE");
        system("CLS");                                  ///If the employees name is in fact the emty string then an error message pops up saying the employee does not exist
    }
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
        cout << "Enter a year :";
        cin >> year;
        try {
            (validate.validateYear(year));          ///Here we try to validate the year by calling the Validate class, and if the year is valid then the program
            break;                                  ///continues, if its not valid then an exception is thrown
        }
        catch (InvalidYearExc exc) {                ///Catches the error message and prints it on the screen
            cout << exc.getMessage() << endl;
        }
    }

    Employee employee = get.findHighestEmployeeYearly(year);

    if (employee.get_name() != ""){
        cout << "Employee: " << endl << employee;                 /// Here we check if the employee is accually found by checking if his name is the empty string,
        system("PAUSE");                                            ///and if thats not the case then we print out the employee
        system("CLS");
    }
    else {
        cout << "Record does not exist, exiting to main menu" << endl << endl;
        system("PAUSE");
        system("CLS");                                  ///If the employees name is in fact the emty string then an error message pops up saying the employee does not exist
    }
}
