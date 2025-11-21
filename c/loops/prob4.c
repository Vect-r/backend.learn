#include <stdio.h>

void main() {
    int end = 1, num = 5;
    for(int row = 5; row >= 1; row-=1){
        for(int col = row; col >= end; col-=1){
            printf(" ");
        }
        for(int col = 1; col <= num; col+=1){
            if (col==end || col==num || row==num || row==end) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
