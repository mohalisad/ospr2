#ifndef ROW_H
#define ROW_H
#include <string>
#include "strtoken.h"
class Table;
class Row{
private:
    StringTokenizer fields;
    Table *parent;
public:
    Row(Table *_parent,std::string _header);
    std::string operator[](std::string input);
};
#endif //ROW_H
