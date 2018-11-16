#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H
#include <string>
#include <vector>
class WorkerManager{
private:
    int* workers;
    int count;
public:
    WorkerManager(int count);
    void send(int index,std::string inp);
    void close_all();
};
#endif //WORKERMANAGER_H
