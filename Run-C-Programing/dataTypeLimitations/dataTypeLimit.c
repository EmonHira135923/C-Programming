#include<stdio.h>

int main(){
    int a = 2147483647;   // max int
    int b = 2147483648;   // overflow
    float c = 3.4028235e38; // max float
    double d = 1.7976931348623157e308; // max double

    printf("Int Max: %d\n", a);
    printf("Int Overflow Example: %d\n", b);
    printf("Float Max: %f\n", c);
    printf("Double Max: %lf\n", d);

    return 0;
}