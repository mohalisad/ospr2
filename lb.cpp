#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include "inpparse.h"
#include "workersmanager.h"

using namespace std;

int run_presenter();
vector<string> get_files(string dirname);
string make_worker_message(string filename,InputParser &args);

int main(){
    int pfd,workercount;
    string line;
    vector<string> files;
    pfd = run_presenter();
    while (getline(cin,line)){
        InputParser args(line);
        files = get_files(args.get_dir());
        if(files.size()==0){
            cout<<"there is no file"<<endl;
            continue;
        }
        workercount = args.get_workernums();
        WorkersManager workers(workercount);
        for(int i=0;i<files.size();i++){
            workers.send(i%workercount,make_worker_message(files[i],args));
        }
        workers.close_all();
    }
    close(pfd);
}

int run_presenter(){
    mkfifo(PIPENAME,0666);
    if(fork()==0){
        mkfifo(PIPENAME,0666);
        int fd = open(PIPENAME, O_RDONLY);
        dup2(fd,0);
        execv("presenter",0);
    }
    return open(PIPENAME, O_WRONLY);
}

vector<string> get_files(string dirname){
    vector<string> ret;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ((string("./")+dirname).c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if(string(ent->d_name) != "." && string(ent->d_name) != "..")
                ret.push_back(dirname +"/"+ ent->d_name);
        }
        closedir (dir);
    }
    return ret;
}

string make_worker_message(string filename,InputParser &args){
    Filter temp;
    string ret;
    for(int i=0;i<args.filters_count();i++){
        if(i!=0)ret+=" ";
        temp = args.get_filter(i);
        ret += temp.key+"="+temp.value;
    }
    return string("open ")+filename+" "+ret;
}
