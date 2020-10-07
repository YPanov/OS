#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(){
    struct rusage f;
    for (size_t i = 0; i < 10; i++)
    {
        memset(malloc(10 * 1024 * 1024), '0', 10 * 1024 * 1024);

        if(getrusage(RUSAGE_SELF, &f) == 0){
            printf("%ld KB\n", f.ru_maxrss);
        } else {
            printf("Error\n");
        }
        
        sleep(1);
    }

    return 0;
}
