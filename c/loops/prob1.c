#include <stdio.h>

void main(){
    int end=5;
    for(int row=1;row<=end;row++){
        for(int col=1;col<=row;col++){
            printf(" ");
        }
        printf("%d\n",row);
    }

}
