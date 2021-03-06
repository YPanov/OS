#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <malloc.h>
void * user_realloc(void * ptr, size_t new_size){ 
    if (ptr == NULL)
        return malloc(new_size); 
    if (new_size == 0){
        free(ptr);
        return ptr;
    }        
void * temp = malloc(new_size); 
size_t size = malloc_usable_size(ptr); 
memcpy(temp, ptr, size);
    free(ptr);
    return temp;
}

int main(){
 printf("Enter original array size: ");
        int n1 = 0;
        scanf("%d",&n1);
        int* a1 = malloc(n1 * sizeof(int));
        int i;
        for(i = 0; i < n1; i++){
                a1[i] = 100;
                printf("%d ", a1[i]);
        }

        printf("\nEnter new array size: ");
        int n2 = 0;
        scanf("%d", &n2);
        a1 = realloc(a1, sizeof(int) * n2);
                for (int i = n1; i < n2; i++) {
                        a1[i] = 0;
                }
        for(i = 0; i < n2;i++) {
                printf("%d ", a1[i]);
        }
        printf("\n");
        return 0;
}
