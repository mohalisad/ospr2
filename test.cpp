#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>


int parent_pipe[2];
int child_pipe[2];

void parent_loop() {
    std::cout << "Hello Child" << ' ' << "Disconnect" << std::endl;
    std::string receive("Parent Receives: ");
    while(true) {
        std::string buffer;
        if( ! (std::cin >> buffer) || buffer == "Disconnect")
            break;
        receive += buffer;
    }
    std::cout << "Disconnect";
    std::cerr << receive << std::endl;
}

void child_loop() {
    std::string receive(" Child Receives: ");
    while( true) {
        std::string buffer;
        if( ! (std::cin >> buffer) || buffer == "Disconnect")
            break;
        receive += buffer;
    }
    std::cout << "Hello Parent" << std::endl;
    std::cout << "Disconnect" << std::endl;
    std::cerr << receive << std::endl;
}


int main(int argc, char** argv) {
    pipe(parent_pipe);
    pipe(child_pipe);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }
    else if (pid) {
        // Parent
        if((dup2(child_pipe[0], STDIN_FILENO) == -1)
        || (dup2(parent_pipe[1], STDOUT_FILENO) == -1))
        {
            std::cerr << "Setup Failure\n";
            return EXIT_FAILURE;
        }
        close(child_pipe[1]);
        close(parent_pipe[0]);

        parent_loop();

        close(child_pipe[0]);
        close(parent_pipe[1]);
    }
    else {
        // Child
        if((dup2(parent_pipe[0], STDIN_FILENO) == -1)
        || (dup2(child_pipe[1], STDOUT_FILENO) == -1))
        {
            std::cerr << "Setup Failure\n";
            return EXIT_FAILURE;
        }
        close(parent_pipe[1]);
        close(child_pipe[0]);

        child_loop();

        close(parent_pipe[0]);
        close(child_pipe[1]);
    }
    return 0;
}
