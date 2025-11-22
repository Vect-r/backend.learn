#include <stdio.h>

void main(){
    int start;
    int end=1;

    printf("Enter Odd an No: ");
    scanf(" %d",&start);

    if(start%2!=0){
    for(int row=start;row>=end;row--){
        for(int col=1;col<=start-row;col++){
            if(col==1||row%2!=0){
                printf("* ");
            } else{
                printf("  ");
            }
        }
        for(int col=row;col>=end;col--){
            if (row==start||col%2!=0){
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    } else {
        printf("The Number you entered is not Odd. Please try again...");
    }
}
