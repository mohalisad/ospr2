#include <iostream>
#include "row.h"
#include "strlib.h"
#include "table.h"

Row::Row(Table *_parent,std::string _fields):fields(_fields," "){
    parent = _parent;
    strfields = _fields;
}
std::string Row::operator[](std::string input) const{
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
bool Row::operator < (const Row& obj2) const{
    bool compare;
    std::string sortby = parent->get_sortby();
    if(sortby == "")return false;
    if(isInt((*this)[sortby])&&isInt(obj2[sortby])){
        compare = parseInt((*this)[sortby])<parseInt(obj2[sortby]);
    }else{
        compare = (*this)[sortby]<obj2[sortby];
    }
    if(parent->get_ascend())
        return compare;
    else
        return !compare;
}
bool Row::operator > (const Row& obj2) const{
    return obj2<(*this);
}
