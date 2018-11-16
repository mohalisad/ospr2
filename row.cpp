#include "row.h"
#include "table.h"

Row::Row(Table *_parent,std::string _fields):fields(_fields," "){
    parent = _parent;
}
std::string Row::operator[](std::string input){
    int i = parent->find_header_index(input);
    if(i!=-1)return fields[i];
    return "";
}
