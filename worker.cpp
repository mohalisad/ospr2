#include <iostream>
#include <string>
#include "strtoken.h"

using namespace std;

int main(){
    string line;
    string presenter;
    while(getline(cin,line)){
        StringTokenizer tokens(line," ");
        if(tokens[0]=="open"){
            presenter = tokens[1];
        }
        if(tokens[0]=="close")return 0;
    }
}
