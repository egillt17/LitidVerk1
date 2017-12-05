#include "Validate.h"

Validate::Validate()
{
    //ctor
}

bool Validate::validateSalary(string salary)
{
    for (unsigned int i = 0; i < salary.length(); i++){
        if (!isdigit(salary[i])){
            return false;
        }
    }
return true;
}

bool Validate::validateSSN(string ssn)
{
    bool isSSN = false;
    if (ssn.length() == 10)
    {
        for (unsigned int i = 0; i < ssn.length(); i++)
        {
            if (!isdigit(ssn[i]))
            {
                isSSN = false;
                break;
            }
            else
            {
                isSSN = true;
            }
        }
    }
    return isSSN;
}

bool Validate::validateMonth(string month)
{
    for(unsigned int i = 0; i < month.length(); i++) {
        if(!isdigit(month[i])){
            return false;
        }
    }
    int tmpMonth = 0;
    stringstream sin1(month);
    sin1 >> tmpMonth;
    if (tmpMonth <= 12 && tmpMonth >= 1){
        return true;
    }
    else{
        return false;
    }
}

bool Validate::validateName(string name)
{
    bool isName = false;
    for (unsigned int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            isName = false;
            break;
        }
        else
        {
            isName = true;
        }
    }
    if (!isalpha(name[0]))
    {
        isName = false;
    }
    return isName;
}

bool Validate::validateYear(string year)
{
    for(unsigned int i = 0; i < year.length(); i++) {
        if(!isdigit(year[i])){
            return false;
        }
    }
    int tmpYear = 0;
    if(year.length() == 4) {
        stringstream sin1(year);
        sin1 >> tmpYear;
        if (tmpYear >= 1900 && tmpYear <= 2017)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
return false;
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
