#include <string.h>
#include <stdio.h>

int main(){
char strin[1000];
printf ("Your string:\n");
gets(strin);

printf ("\nYour string in reverse:\n");
for (int i = strlen(strin); i>=0; i--){
printf ("%c", strin[i]);
}
return 0;
}
