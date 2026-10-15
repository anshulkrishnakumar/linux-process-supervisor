#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Error:fork() failed\n";
        return 1;    
    }

    if (pid == 0) {
        char* args[] = {
            const_cast<char*>("ls"),
            const_cast<char*>("-l"),
            nullptr
        };

        execvp("ls", args);

        std::cerr << "Error: execvp() failed\n";
        std::_Exit(127); // terminates program
    }

    std::cout << "Start child process with PID: " << pid << '\n';

    int status = 0;
    pid_t result = waitpid(pid, &status, 0); // blocking

    if (result == -1) {
        std::cerr << "Error: waitpid() failed\n";
        return 1;
    }
    
    if (WIFEXITED(status)) {
        int exit_code = WEXITSTATUS(status);
        std::cout << "Child exited with code: " << exit_code << '\n'; 
    } else if (WIFSIGNALED(status)) {
        std::cout << "Child terminated by signal: " << WTERMSIG(status) << '\n';  
    }

    return 0;
}
