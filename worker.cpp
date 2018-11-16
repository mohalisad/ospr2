#include <iostream>
#include <string>
#include "strtoken.h"

using namespace std;

int main(){
    char a[40];
    string line;
    string presenter;
    while(getline(cin,line)){
        StringTokenizer tokens(line," ");
        if(tokens[0]=="open"){
            presenter = tokens[1];
        }
        if(tokens[0]=="close")break;
    }
    cout <<"closed"<<endl;
    return 0;
}
