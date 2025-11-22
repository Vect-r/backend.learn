#include <stdio.h>

void main(){
    int start;
    int end=1;

    printf("Enter Rows in Odd Number: ");
    scanf(" %d",&start);

    if(start%2!=0){
    for (int row=start;row>=end;row--){
        for(int col=1;col<=row;col++){
            if (col%2!=0){
                printf("| ",col);
            } else if(col==row){
                printf("/ ");
            } else {
                printf("  ");
            }
        }
        for(int col=start-row;col>=end;col--){
            if (row%2!=0){
                printf("_ ");
            } else {
                printf("  ");
            }
        }
        for(int col=1;col<=start-row;col++){
            if(row%2!=0){
                printf("_ ");
            } else{
                printf("  ");
            }
        }
        for(int col=row;col>=end;col--){
            if (col%2!=0||col==row){
                printf("| ",col);
            } else {
                printf("  ");
            }
        }

        printf("\n");
    }
    } else {
        printf("Please Enter Odd Number.");
    }
}
