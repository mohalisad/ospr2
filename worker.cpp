#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "filter.h"
#include "strtoken.h"
#include "table.h"

using namespace std;

void print(std::string input);

int main(){
    string line;
    string filename;
    string search_result;
    Filter *filters;
    int    filters_count;
    while(getline(cin,line)){
        StringTokenizer tokens(line," ");
        if(tokens[0]=="open"){
            filename = tokens[1];
            filters_count = tokens.size()-2;
            filters  = new Filter[filters_count];
            for(int i=2;i<tokens.size();i++){
                StringTokenizer temp(tokens[i],"=");
                filters[i-2].key   = temp[0];
                filters[i-2].value = temp[1];
            }
            ifstream ifs(filename.c_str());
            if(getline(ifs,line)){
                Table table(line);
                while (getline(ifs,line)) {
                    table.add_row(line);
                }
                search_result = table.check_filter(filters,filters_count);
            }
            print(std::string("result;")+search_result+"\n");
        }
        if(tokens[0]=="close")break;
    }
    return 0;
}

void print(std::string input){
    write(1,input.c_str(),input.size()+1);
}
