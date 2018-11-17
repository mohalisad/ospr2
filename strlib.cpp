#include <sstream>
#include <fstream>
#include "strlib.h"

int parseInt(std::string input){
    bool isItNegative=false;
    int number=0;
    if(input.size()==0)return 0;
    if(input[0]=='-')isItNegative=true;
    for(int i=isItNegative?1:0;(unsigned)i<input.size();i++){
        if(input[i]>='0'&&input[i]<='9'){
            number=number*10+input[i]-'0';
        }else return 0;
    }
    return isItNegative?-number:number;
}
std::string intToString(const int& input){
    std::ostringstream myCustomStreamString;
    myCustomStreamString<<input;
    return myCustomStreamString.str();
}
bool isInt(std::string input){
    bool isItNegative=false;
    int number=0;
    if(input.size()==0)return false;
    if(input[0]=='-')isItNegative=true;
    for(int i=isItNegative?1:0;(unsigned)i<input.size();i++){
        if(input[i]>='0'&&input[i]<='9'){
        }else return false;
    }
    return true;
}
