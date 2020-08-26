#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

int integer_num = INT_MAX;
float float_num = FLT_MAX;
double double_num = DBL_MAX;

printf("Integer = %d\n");
printf("Float = %f\n");
printf("Double  = %f\n");

printf("Size of integer_num = %lu", sizeof(integer_num));
printf("\nSize of float_num = %lu", sizeof(float_num));
printf("\nSize of double_num = %lu", sizeof(double_num));

return 0;

}
