#include <stdio.h>

void main(){
    int num=5;
    for(int row=1;row<=num;row++){
        for(int col=1;col<=row;col++){
            printf(" ");
        }
        for(int col = 1; col <= num; col+=1){
            if((row == 1) || (row == num) || (col == 1) || (col == num)){
                printf("* ");
            }else{
                printf("  ");
            }
        }

//        printf("%d\n",row);
        printf("\n");
    }

}
