#include "row.h"
#include "table.h"

Row::Row(Table *_parent,std::string _fields):fields(_fields," "){
    parent = _parent;
    strfields = _fields;
}
std::string Row::operator[](std::string input){
    int i = parent->find_header_index(input);
    if(i!=-1)return fields[i];
    return "";
}
bool Row::check_filter(Filter *filters,int count){
    for(int i=0;i<count;i++){
        if((*this)[filters[i].key] != filters[i].value)
            return false;
    }
    return true;
}
std::string Row::getstrfields(){
    return strfields;
}
