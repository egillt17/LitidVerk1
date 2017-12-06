#include "Repository.h"

void Repository::writeInFile(Employee& employee) {
    ofstream fout;
    fout.open("Employee.txt", ios::app);                        ///If Employee.txt is open then write an employee into the .txt file, we're using ios::app so the new employee
    if(fout.is_open()) {                                        ///simply goes to the bottom of the text file
        fout << employee;
    }
    else {
        // throw error!!!
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
        // throw error!!!
    }                                                           ///Else throw error
    fout.close();
}

void Repository::getInfoInFile(vector <Employee>& employee) {
    employee.clear();
    ifstream fin;
    Service fix;
    string namef = "";
    string ssnf = "";
    string salaryf = "";
    string monthf = "";
    string yearf = "";

    fin.open("Employee.txt");
    if(fin.is_open()) {
        while(!fin.eof()) {
            for(int i = 0; i < 5; i++) {
                if(i == 0) {
                    getline(fin, namef, ':');
                    if(namef == "") {
                    getline(fin, namef, ':');
                    }
                }
                else if(i == 1) {
                    getline(fin, ssnf, ':');
                }
                else if(i == 2) {
                    getline(fin, salaryf, ':');
                }
                else if(i == 3) {
                    getline(fin, monthf, ':');
                }
                else if(i == 4) {
                    getline(fin, yearf, ':');
                }
            }
            Employee employee2 = fix.makeEmployee(namef, ssnf, salaryf, monthf, yearf);
            employee.push_back(employee2);
        }
    }
    else {
        // throw error!!!
    }
}
