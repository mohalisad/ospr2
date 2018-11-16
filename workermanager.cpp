#include <iostream>
#include <unistd.h>
#include "workermanager.h"

WorkerManager::WorkerManager(int count){
    int fd[2];
    this->count = count;
    workers = new int[count];
    for(int i=0;i<count;i++){
        pipe(fd);
        if(fork()==0){
            dup2(fd[0],0);
            close(fd[0]);
            close(fd[1]);
            execv("worker",0);
        }else{
            workers[i] = fd[1];
            close(fd[0]);
        }
    }
}
void WorkerManager::send(int index,std::string inp){
    std::string temp = inp + "\n";
    write (workers[index],temp.c_str(),temp.size());
}
void WorkerManager::close_all(){
    for (int i=0;i<count;i++)
        send(i,"close");
}
