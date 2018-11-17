#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "workersmanager.h"

WorkersManager::WorkersManager(int count){
    int pfd;
    int fd[2];
    this->count = count;
    workers = new int[count];
    for(int i=0;i<count;i++){
        pipe(fd);
        if(fork()==0){
            dup2(fd[0],0);
            close(fd[0]);
            close(fd[1]);
            pfd = open(PIPENAME, O_WRONLY);
            dup2(pfd,1);
            close (pfd);
            execv("worker",(char **)0);
        }else{
            workers[i] = fd[1];
            close(fd[0]);
        }
    }
}

void WorkersManager::send(int index,std::string inp){
    std::string temp = inp + "\n";
    write (workers[index],temp.c_str(),temp.size());
}

void WorkersManager::close_all(){
    for (int i=0;i<count;i++)
        send(i,"close");
}
