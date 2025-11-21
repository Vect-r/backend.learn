#include<stdio.h>

void main(){

    int num = 5;
    for(int row = 1; row <= num; row+=1){
        for(int col = 1; col <= num; col+=1){
            if((row == col) || (col == 1) || (row == num)){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

}
