#include <iostream>
#include <string>
#include "strtoken.h"

using namespace std;

int main(){
    char a[40];
    string line;
    while(getline(cin,line)){
        StringTokenizer tokens(line," ");
        if(tokens[0]=="open"){
            std::cout <<"work"<<std::endl;
        }
        if(tokens[0]=="close")break;
    }
    return 0;
}
