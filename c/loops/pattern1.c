#include <stdio.h>

void main(){
    int end = 9;

    for(int row=1;row<=end;row++){
        for(int col=1;col<=row;col++){
            if (col==1||(row%2!=0)){
                printf("* ");
            } else {
                printf("  ");
            }

        }
        printf("\n");
    }
}
