#include <iostream>
#include "workermanager.h"
int main(){
    WorkerManager workers(5);
    workers.close_all();
}
