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
