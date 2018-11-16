#include "inpparse.h"
#include "strtoken.h"
#include "strlib.h"

InputParser::InputParser(std::string input){
    Filter tempf;
    workernums = 0;
    StringTokenizer tokens(input,"-");
    for (int i = 0;i<tokens.size();i++){
        StringTokenizer temp(tokens[i],"= ");
        if (temp[0] == "prc_cnt"){
            workernums = parseInt(temp[1]);
        }else if (temp[0] == "dir"){
            dir = temp[1];
        }else if (temp[1] == "ascend" || temp[1] == "descend"){
            sortby = temp[0];
            ascend = (temp[1] == "ascend");
        }else {
            tempf.key   = temp[0];
            tempf.value = temp[1];
            filters.push_back(tempf);
        }
    }
}
std::string InputParser::get_dir(){
    return dir;
}
std::string InputParser::get_sortby(bool& isascend){
    isascend = ascend;
    return sortby;
}
int InputParser::get_workernums(){
    return workernums;
}
int InputParser::filters_count(){
    return (int)filters.size();
}
Filter InputParser::get_filter(int index){
    return filters[index];
}
