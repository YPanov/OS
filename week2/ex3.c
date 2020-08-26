#include <stdio.h>
int main(){

int n;
scanf("%d", &n);
int a = 1;
for (int i = 0; i < n; i++){

        for (int j = 0; j < n-1-i; j++){
                printf (" ");
        }

        for (int g = 0; g < 1+2*i; g++){
                printf ("*");
        }
        
        printf ("\n");

}

return 0;

}
