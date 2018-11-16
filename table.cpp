#include "table.h"
Table::Table(std::string _header):header(_header," "){}
int Table::find_header_index(std::string inp){
    for (int i=0;i<header.size();i++){
        if(inp == header[i])return i;
    }
    return -1;
}
void Table::add_row(std::string inp){
    Row temp(this,inp);
    rows.push_back(temp);
}
Row& Table::operator[](int input){
    return rows[input];
}
std::vector<Row>::size_type Table::size(){
    return rows.size();
}
