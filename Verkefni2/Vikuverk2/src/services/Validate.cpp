#include "Validate.h"


Validate::Validate()
{
    //ctor
}

bool Validate::validateInput(string input){
    for(unsigned int i = 0; i < input.length(); i++) {
        if(!isdigit(input[i])){
            throw(InvalidInputExc("| Invalid input - (digits only)"));
        }
    }
    int tmpInput = 0;
    stringstream sin1(input);
    sin1 >> tmpInput;
    if (tmpInput >= 1 && tmpInput <= 10){
        return true;
    }
    else {
        throw(InvalidInputExc("| Invalid input - (1 to 10)"));
    }

}

bool Validate::validateSalary(string salary)
{
    for (unsigned int i = 0; i < salary.length(); i++){
        if (!isdigit(salary[i])){
            throw(InvalidSalaryExc("| Invalid input - (digits only)"));
        }
    }
return true;
}

bool Validate::validateSSN(string ssn)
{
    if (ssn.length() == 10)
    {
        for (unsigned int i = 0; i < ssn.length(); i++)
        {
            if (!isdigit(ssn[i]))
            {
                throw(InvalidSsnExc("| Invalid input - (10 - digits only)"));
            }
        }
    }
    else {
        throw(InvalidSsnExc("| Invalid lenght - (10 - digits)"));
    }
return true;
}

//cout << "| invalid input -- Month (1 - 12) Year (2017 or below)"  << endl;

bool Validate::validateMonth(string month)
{
    for(unsigned int i = 0; i < month.length(); i++) {
        if(!isdigit(month[i])){
            throw(InvalidMonthExc("| Invalid input - (digits only)"));
        }
    }
    int tmpMonth = 0;
    stringstream sin1(month);
    sin1 >> tmpMonth;
    if (tmpMonth <= 12 && tmpMonth >= 1){
        return true;
    }
    else{
        throw(InvalidMonthExc("| Invalid input - (1 to 12)"));
    }
}

bool Validate::validateName(string name)
{
    for (unsigned int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            throw(InvalidNameExc("| Invalid input - (letters only)"));
        }
    }
    if (name[0] == ' '){
        throw(InvalidNameExc("| Invalid input - (must start with a letter)"));
    }
return true;
}

bool Validate::validateYear(string year)
{
    for(unsigned int i = 0; i < year.length(); i++) {
        if(!isdigit(year[i])){
            throw(InvalidYearExc("| Invalid input - (digits only)"));
        }
    }
    int tmpYear = 0;
    if(year.length() != 4) {
        throw(InvalidYearExc("| Invalid input - (4 - digits only)"));
    }
    stringstream sin1(year);
    sin1 >> tmpYear;
    if (tmpYear >= 1900 && tmpYear <= 2017)
    {
            return true;
    }
    else
    {
        throw(InvalidYearExc("| Invalid input - (1900 to 2017)"));
    }
throw(InvalidYearExc("| Invalid input"));
}

bool Validate::validateAll(string name, string ssn, string salary, string month, string year)
{
    if (validateName(name) && validateSSN(ssn) && validateSalary(salary) && validateMonth(month) && validateYear(year))
    {
        return true;
    }
    else
    {
        return false;
    }
}
