#include<stdio.h>

int main(){

    int i, j;

    // For Loop
    printf("For Loop:\n");
    for(i = 1; i <= 5; i++){
        printf("%d ", i);
    }
    printf("\n\n");

    // While Loop
    printf("While Loop:\n");
    i = 1;
    while(i <= 5){
        printf("%d ", i);
        i++;
    }
    printf("\n\n");

    // Do-While Loop
    printf("Do-While Loop:\n");
    i = 1;
    do{
        printf("%d ", i);
        i++;
    }while(i <= 5);
    printf("\n\n");

    // Nested Loop
    printf("Nested Loop:\n");
    for(i = 1; i <= 3; i++){
        for(j = 1; j <= 3; j++){
            printf("%d%d ", i, j);
        }
        printf("\n");
    }
    printf("\n");

    // Break Example
    printf("Break Example:\n");
    for(i = 1; i <= 10; i++){
        if(i == 5){
            break;
        }
        printf("%d ", i);
    }
    printf("\n\n");

    // Continue Example
    printf("Continue Example:\n");
    for(i = 1; i <= 5; i++){
        if(i == 3){
            continue;
        }
        printf("%d ", i);
    }
    printf("\n\n");

    // Infinite Loop (Warning: manually stop)
    printf("Infinite Loop (Press Ctrl+C to stop):\n");
    // for(;;){
    //     printf("Running...\n");
    // }

    return 0;
}