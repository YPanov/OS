#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 10
void main(void) {
    int n = SIZE;
    pid_t pid;
        pid = fork();
    if (pid > 0){   //parent
        printf ("Hello from parent [%d - %d]\n", pid, n);
    } else if (pid == 0) { //child
        printf ("Hello from child [%d - %d]\n", pid, n);
    }
}
