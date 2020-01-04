#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static char child_stack[1048576];

static int child_fn() {
    printf("Parent PID in new process: %ld\n", (long)getppid());
    printf("PID in new process: %ld\n", (long)getpid());
    return 0;
}

int main() {
    printf("Clone New PID Test\n");

    pid_t child_pid = clone(child_fn, child_stack+1048576, CLONE_NEWPID | SIGCHLD, NULL);
    if (child_pid < 0) {
        perror("Failed to clone a new PID");
        return -1;
    }

    printf("PID in current process: %ld\n", (long)getpid());
    printf("PID from clone() = %ld\n", (long)child_pid);

    waitpid(child_pid, NULL, 0);
    return 0;
}
