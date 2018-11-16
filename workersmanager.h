#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H
#include <string>
#include <vector>

#define PIPENAME "temp"

class WorkersManager{
private:
    int* workers;
    int  count;
public:
    WorkersManager(int count);
    void send(int index,std::string inp);
    void close_all();
};
#endif //WORKERMANAGER_H
