#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int randomNum(int limit){
    // Returns Number from 1 to limit...
    srand(time(0));
    return (rand() % limit)+1;
}

void main(){
    int num=randomNum(10);
//    printf("%d\n",num);

    int choice=0,counter=0;

    while(choice!=num){
        printf("Guess the number within %d: ",10);
        scanf(" %d",&choice);
        if (choice<num){
            printf("Low\n");
        } else if (choice>num){
            printf("High\n");
        } else {
            printf("Yes, The number is %d\n",choice);
        }
        counter++;
    }
    printf("You Guessed the number in %d tries\n",counter);
}
