#include <iostream>
#include "strtoken.h"
#include "strlib.h"
#include "table.h"

using namespace std;

int main(){
    string line,sortby;
    Table *table;
    bool   make_table = false,ascend;
    int    counter = 0,max_counter = -1;
    while (getline(cin,line)) {
        StringTokenizer tokens(line,";");
        if(tokens[0] == "init"){
            make_table = true;
            counter = 0;
            max_counter = parseInt(tokens[1]);
            sortby = tokens[3];
            ascend = (parseInt(tokens[2])==1);
        }
        if(tokens[0] == "result"){
            if(make_table){
                table = new Table(tokens[1]);
                make_table = false;
            }
            for(int i=2;i<tokens.size();i++){
                table->add_row(tokens[i]);
            }
            counter++;
        }
        if(counter == max_counter){
            cout<<table->get_sorted(sortby,ascend)<<flush;
            max_counter = -1;
        }
    }
}
