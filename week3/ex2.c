#include <stdio.h>
void bubble_sort(int a[], int n) {
    int tmp;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
int main() {
  int n;
  printf("Enter number of elements in the array:\n");
  scanf("%d", &n); 
  int a[n];
  printf("Enter the elements\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  bubble_sort(a, n);
  printf("Your sorted array:\n");
  for (int i = 0; i < n; i++)
     printf("%d\n", a[i]);
  return 0;
}
