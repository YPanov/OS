#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    for (size_t i = 0; i < 10; i++)
    {
        memset(malloc(10 * 1024 * 1024), '0', 10 * 1024 * 1024);
        sleep(1);
    }

    return 0;
}
// si values are always more than 100, so it seems that OS used swaps to fit in my memory. 
