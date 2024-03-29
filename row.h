#ifndef ROW_H
#define ROW_H
#include <string>
#include "strtoken.h"
#include "filter.h"
class Table;
class Row{
private:
    StringTokenizer fields;
    std::string     strfields;
    Table          *parent;
public:
    Row(Table *_parent,std::string _header);
    std::string operator[](std::string input) const;
    bool        check_filter(Filter *filters,int count);
    std::string getstrfields();
    bool operator < (const Row& obj2) const;
    bool operator > (const Row& obj2) const;
};
#endif //ROW_H
