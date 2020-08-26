#include <stdio.h>

void swap (int *a, int *b){
     int t;
     t = *a;
     *a = *b;
     *b = t;
}

int main() {
    int a;
    int b;
    printf ("Your first number: ");
    scanf ("%d", &a);
    printf ("Your second number: ");
    scanf ("%d", &b);
    printf ("\n");
    swap(&a, &b);
    printf ("New first number: %d\nNew second number: %d", a, b);

return 0;
}
