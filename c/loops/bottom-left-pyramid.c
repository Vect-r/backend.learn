#include <stdio.h>
void main() {
    int num=33;
    for (int row=num;row>=1;row--){
        for(int col=1;col<=row;col++){
            if (col%2!=0||row==num||col==row){
                printf("* ",col);
            } else {
                printf("  ");
            }
        }
        for(int col=num-row;col>=1;col--){
            if (col==1||row%2!=0){
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}
