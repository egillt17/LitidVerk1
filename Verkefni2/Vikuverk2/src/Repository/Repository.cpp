#include "Repository.h"

Repository::Repository() {
    //ctor
}

Repository::~Repository() {
    //dtor
}

void Repository::writeInFile(Employee& employee) {
    ofstream fout;
    fout.open("Employee.txt", ios::app);
    if(fout.is_open()) {
        fout << employee;
        fout.close();
    }
    else {
        // throw error!!!
    }

}

void Repository::infoInFile(vector <Employee>& employee) {
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
