#include <stdio.h>

int main() {
    int end = 1, num = 5;
    for(int row = 5; row >= 1; row-=1){
        for(int col = 1; col <= num - row; col+=1){
            printf("  ",col);
        }
        for(int col = row; col >= end; col-=1){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
