#include "table.h"
Table::Table(std::string _header):header(_header," "),headerstr(_header){}
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
std::string Table::check_filter(Filter *filters,int count){
    std::string ret = headerstr;
    for(int i=0;i<rows.size();i++){
        if(rows[i].check_filter(filters,count)){
            ret += std::string(";") + rows[i].getstrfields();
        }
    }
    return ret;
}
std::string Table::get_sorted(std::string sortby,bool isascend){
    std::string ret = headerstr + "\n";
    this->sortby = sortby;
    ascend = isascend;
    std::sort(rows.begin(),rows.end());
    for(int i=0;i<rows.size();i++){
        ret += rows[i].getstrfields() + "\n";
    }
    return ret;
}
std::string Table::get_sortby(){
    return sortby;
}
bool Table::get_ascend(){
    return ascend;
}
