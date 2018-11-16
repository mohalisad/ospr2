#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <vector>
#include "strtoken.h"
#include "row.h"
class Table{
private:
    StringTokenizer header;
    std::vector<Row> rows;
public:
    Table(std::string _header);
    int find_header_index(std::string inp);
    void add_row(std::string inp);
    Row& operator[](int input);
    std::vector<Row>::size_type size();
    std::string check_filter(Filter *filters,int count);
};
#endif //TABLE_H
