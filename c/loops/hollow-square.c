#include <stdio.h>

void main(){
    int grid=7;
    for(int row=1;row<=grid;row++){
        for(int col=1;col<=grid;col++){
            if ((row==1||row==grid)
                ||(col==1||col==grid)
                ||(row==col)
                ||(col == grid - row + 1)){
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
