#include "Validate.h"

bool Validate::validateName(string name){
    for(unsigned int i = 0; i < name.length(); i++){
        if(!isalpha(name[i])){
            throw(InvalidNameException("Invalid Input - Name must be letters only"));
        }
    }
    if (name[0] == ' '){
        throw(InvalidNameException("Invalid Input - Name must start with a letter"));
    }
return true;
}

bool Validate::validateNum(string number){
    for(unsigned int i = 0; i < number.length(); i++){
        if(!isdigit(number[i])){
            throw(InvalidNumExceptions("Invalid Input - Must be digits only"));
        }
    }
}

bool Validate::validateLocation(string location){
    string tempStreet;
    string tempNum;
    string delimiter = " ";
    int num_of_delimiters = 0;
    unsigned int pos = 0;
    if(location[0] == ' '){
        throw(InvalidLocationException("Invalid Input - Must start with a letter"));
    }
    for(size_t i = 0; i < location.length(); i++) {
        if(location[i] == ' '){
            num_of_delimiters++;
        }
    }
    if(num_of_delimiters > 1) {
        throw(InvalidLocationException("Invalid Input - Only street name followed by a number"));
    }
    pos = location.find(delimiter);
    tempStreet = location.substr(0, pos);
    if(!validateName(tempStreet)){
        throw(InvalidLocationException("Invalid Input - Street name must be only letters"));
    }
    location.erase(0, pos + delimiter.length());
    tempNum = location.substr(0, location.length());
    if(!validateNum(tempNum)) {
        throw(InvalidLocationException("Invalid Input - Street number must be only digits"));
    }
return true;
}
