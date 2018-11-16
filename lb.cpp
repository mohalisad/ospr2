#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "inpparse.h"
#include "workersmanager.h"

using namespace std;

void run_presenter(int &pfd);

int main(){
    int pfd;
    string line;
    run_presenter(pfd);
    while (getline(cin,line)){
        InputParser args(line);
        WorkersManager workers(args.get_workernums());
        workers.close_all();
    }
    close(pfd);
}

void run_presenter(int &pfd){
    mkfifo(PIPENAME,0666);
    if(fork()==0){
        mkfifo(PIPENAME,0666);
        int fd = open(PIPENAME, O_RDONLY);
        dup2(fd,0);
        execv("presenter",0);
    }
    pfd = open(PIPENAME, O_WRONLY);
}
