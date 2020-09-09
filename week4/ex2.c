#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
for (int i = 0; i < 3; i++){
    fork();
    sleep(5);
}
    return 0;
}
// Before 1st pstree command fork() copies the process.
// Then on the 2nd time loop runs fork() copies all processes we have
// Then on 3rd time loop it copies all processes again
// In the end we have 8 processes
// X - - X - - X - - X
//    |     |
//    |     X
//    |
//    |- X - - X
//    |
//    X
// If we run loop 5 times instead of 3 nothing in the algorithm will change, but the tree will become bigger and bigger and we will have 32 processes
