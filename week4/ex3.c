  
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
char com[200];
while (1){
    printf("Print a command: ");
    fgets(com, sizeof(com) / sizeof(char), stdin);
    if(strcmp(com, "exit\n") == 0){
	break;
    } else {
	system(com);
}
}
return 0;
}
