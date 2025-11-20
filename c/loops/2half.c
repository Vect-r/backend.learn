#include <stdio.h>

void  main(){
    int num = 5;
    for(int row = 1; row <= num; row += 1){
        for(int col = 1; col < row; col += 1){
            printf("  ");
        }
        for(int col = num; col >= row; col--){
            printf("* ");
        }
        for(int col = num; col > row; col--){
            printf("* ");
        }
        printf("\n");
    }
}
