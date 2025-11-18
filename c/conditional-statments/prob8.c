#include <stdio.h>


void main(){
    int marks;

    printf("Input: ");
    scanf("%d", &marks);

    if (marks>=0 && marks<=100) {

        if (marks==100){
            printf("Perfect Score!\n");
        }

        if (marks>=90 && marks<=100) {
            printf("A");
        } else if (marks>=75 && marks<=89) {
            printf("B");
        } else if (marks>=60 && marks<=74) {
            printf("C");
        } else if (marks>=40 && marks<=59) {
            printf("D");
        } else if (marks>=0 && marks<=39) {
            printf("F");
        }
    } else {
        printf("Invalid Marks");
    }
}
