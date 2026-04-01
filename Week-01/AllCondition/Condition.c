#include<stdio.h>

int main(){

    int a = 10, b = 20;
    int choice = 2;

    // If Condition
    if(a < b){
        printf("If: a is smaller than b\n");
    }

    // If-Else Condition
    if(a > b){
        printf("If-Else: a is greater\n");
    }else{
        printf("If-Else: b is greater\n");
    }

    // If Else-if Ladder
    int marks = 75;

    if(marks >= 80){
        printf("Grade: A+\n");
    }
    else if(marks >= 70){
        printf("Grade: A\n");
    }
    else if(marks >= 60){
        printf("Grade: A-\n");
    }
    else{
        printf("Grade: Fail\n");
    }

    // Nested If
    int age = 20;

    if(age >= 18){
        if(age >= 21){
            printf("Nested If: Adult + Special Access\n");
        }else{
            printf("Nested If: Adult\n");
        }
    }else{
        printf("Nested If: Minor\n");
    }

    // Switch Case
    printf("Switch Case:\n");

    switch(choice){
        case 1:
            printf("Choice is 1\n");
            break;
        case 2:
            printf("Choice is 2\n");
            break;
        case 3:
            printf("Choice is 3\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    // Ternary Operator
    int max = (a > b) ? a : b;
    printf("Ternary: Max = %d\n", max);

    return 0;
}