#ifndef INPPARSE_H
#define INPPARSE_H
#include <string>
#include <vector>
#include "filter.h"
class InputParser{
private:
    std::vector<Filter>  filters;
    std::string          dir;
    std::string          sortby;
    bool                 ascend;
    int                  workernums;
public:
    InputParser(std::string input);
    std::string get_dir();
    std::string get_sortby(bool& isascend);
    int         get_workernums();
    int         filters_count();
    Filter      get_filter(int index);
};
#endif //INPPARSE_H
