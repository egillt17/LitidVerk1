#include "Repository.h"

void Repository::writeInFile(Employee& employee) {
    ofstream fout;
    fout.open("Employee.txt", ios::app);                        ///If Employee.txt is open then write an employee into the .txt file, we're using ios::app so the new employee
    if(fout.is_open()) {                                        ///simply goes to the bottom of the text file
        fout << employee;
    }
    else {

    }
    fout.close();
}

void Repository::reWriteInFile(vector <Employee> employee) {
    ofstream fout;
    fout.open("Employee.txt");
    if(fout.is_open()) {
        for(unsigned int i = 0; i < employee.size(); i++) {     ///If Employee.txt is open then write all the employees inside the vector until the size of the vector
            fout << employee[i];                                ///is surpassed (not using ios::app here so the file is completely rewritten)
        }
    }
    else {

    }
    fout.close();
}

void Repository::getInfoInFile(vector <Employee>& employee) {
    employee.clear(); /// here the vector gets cleared so there wont be any conflict if this function gets called again
    ifstream fin;
    Service fix;
    string namef = "";
    string ssnf = "";
    string salaryf = "";
    string monthf = "";
    string yearf = "";

    fin.open("Employee.txt");   ///opens the employee file
    if(fin.is_open()) {     /// checks if the file was opened
        while(!fin.eof()) {     /// runs until end of file
            for(int i = 0; i < 5; i++) {    ///it loops five times because there are five different things that the program gets for the employee variable
                if(i == 0) {    /// if i = 0 because the name is always writen first
                    getline(fin, namef, ':');
                    if(namef == "") {   ///this is because it the empty space in the beginning of the file
                    getline(fin, namef, ':');   ///so this overwrites that
                    }
                }
                else if(i == 1) {   /// because the social security number is always after the name
                    getline(fin, ssnf, ':');
                }
                else if(i == 2) {       /// because the salary is always after the ssn
                    getline(fin, salaryf, ':');
                }
                else if(i == 3) {       /// because the month is always after the salary
                    getline(fin, monthf, ':');
                }
                else if(i == 4) {       ///because the year is always after the month
                    getline(fin, yearf, ':');
                }
            } ///this line below is turnong all the variables into an Employee variable
            Employee employee2 = fix.makeEmployee(namef, ssnf, salaryf, monthf, yearf);
            employee.push_back(employee2); /// here the Employee variable gets added to the employee vector
            /// which gets return by reference
        }
    }
    else {

    }
    fin.close();
}
