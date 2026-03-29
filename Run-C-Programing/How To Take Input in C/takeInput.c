#include<stdio.h>
int main(){

    // scanf is used to take input from user
    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);

    char b;
    printf("Enter a character: ");
    scanf(" %c", &b);

    float c;
    printf("Enter a float: ");
    scanf(" %f", &c);

    printf("You Entered Integer: %d\n",a);
    printf("You Entered Character: %c\n",b);
    printf("You Entered Float: %0.2f\n",c);
    return 0;
}