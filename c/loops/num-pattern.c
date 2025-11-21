#include <stdio.h>

void main(){
    int stepper;
    printf("Enter No. to print range: ");
    scanf("%d",&stepper);
    printf("\n");

    for (int st=1;st<=stepper;st++){
        if (st%2==!0){
            //For Odd
            int num=5;
            for(int row=1;row<=num;row++){
                for(int col=1;col<=row;col++){
                    printf(" ");
                }
                for(int col = 1; col <= num; col+=1){
                    if((row == 1) || (row == num) || (col == 1) || (col == num)){
                        printf("* ");
                    }else{
                        if(row==3 && col==3){
                            printf("%d ",st);
                        } else {
                            printf("  ");
                    }
                }
            }

            printf("\n");
            if(row==5&&st!=stepper){
                for(int col=1;col<=row;col++){
                    printf(" ");
                }
                for (int col=1;col<=row;col++){
                    printf("= ");
                }
            }
            printf("\n");
            }




        } else {
            //for Even
            int end = 1, num = 5;

            for(int row = 5; row >= 1; row-=1){
                for(int col = row; col >= end; col-=1){
                    printf(" ");
                }
            for(int col = 1; col <= num; col+=1){
                if (col==end || col==num || row==num || row==end) {
                    printf("* ");
                } else {
                    if(row==3 && col==3){
                        printf("%d ",st);
                    } else {
                        printf("  ");
                    }

                }
            }
            printf("\n");
            if(row==1&&st!=stepper){
                for(int col=1;col<=row;col++){
                    printf(" ");
                }
                for (int col=1;col<=5;col++){
                    printf("= ");
                }
            }
            printf("\n");
            }

        }
    }

}
