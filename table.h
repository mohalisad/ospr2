#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <vector>
#include "strtoken.h"
#include "row.h"
class Table{
private:
    StringTokenizer  header;
    std::string      headerstr;
    std::vector<Row> rows;
    std::string      sortby;
    bool             ascend;
public:
    Table(std::string _header);
    int find_header_index(std::string inp);
    void add_row(std::string inp);
    Row& operator[](int input);
    std::vector<Row>::size_type size();
    std::string check_filter(Filter *filters,int count);
    std::string get_sorted(std::string sortby,bool isascend);
    std::string get_sortby();
    bool        get_ascend();
};
#endif //TABLE_H
