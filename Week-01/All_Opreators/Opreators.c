#include<stdio.h>

int main(){

    int a = 10, b = 3;

    // Arithmetic Operators
    printf("Arithmetic:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n\n", a % b);

    // Relational Operators
    printf("Relational:\n");
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n", a != b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n", a < b);
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n\n", a <= b);

    // Logical Operators
    printf("Logical:\n");
    printf("(a > 5 && b < 5) : %d\n", (a > 5 && b < 5));
    printf("(a > 5 || b > 5) : %d\n", (a > 5 || b > 5));
    printf("!(a > b) : %d\n\n", !(a > b));

    // Bitwise Operators
    printf("Bitwise:\n");
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n\n", a >> 1);

    // Assignment Operators
    int x = 5;
    printf("Assignment:\n");
    x += 2;
    printf("x += 2 : %d\n", x);
    x -= 1;
    printf("x -= 1 : %d\n\n", x);

    // Increment & Decrement
    int y = 5;
    printf("Increment/Decrement:\n");
    printf("y++ = %d\n", y++);
    printf("After y++ : %d\n", y);
    printf("++y = %d\n\n", ++y);

    // Conditional Operator
    int max = (a > b) ? a : b;
    printf("Conditional:\n");
    printf("Max = %d\n\n", max);

    // Comma Operator
    int m;
    m = (a = 2, b = 4, a + b);
    printf("Comma:\n");
    printf("m = %d\n\n", m);

    // sizeof Operator
    printf("Sizeof:\n");
    printf("Size of int = %lu bytes\n\n", sizeof(int));

    return 0;
}