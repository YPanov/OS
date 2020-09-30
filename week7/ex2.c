#include <stdio.h> 
#include <stdlib.h>
int main(){
    
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    
    int * ar = (int*)malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++ ){
        ar[i] = i;
        printf("%d ", ar[i]);
    }
    printf("\n");
    
    free(ar);
    
    return 0;
    
}
