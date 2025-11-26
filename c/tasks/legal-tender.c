#include <stdio.h>

void main(){
    int cLen = 65;

    int currency[9] = {500,200,100,50,20,10,5,2,1};
    int num;

    printf("Enter No? ");
    scanf(" %d",&num);

    int diff = num;

    int arrLen = sizeof(currency)/sizeof(currency[0]);

    for(int f=0;f<cLen;f++){
        printf("=");
    }
    printf("\n");

    for(int i=0;i<arrLen;i++){
        int quo = diff/currency[i];
        if(quo>0){
            diff-=(currency[i]*quo);
            printf("%d x %d = %d\n",currency[i],quo,currency[i]*quo);
        }
    }

    for(int f=0;f<cLen;f++){
        printf("=");
    }
    printf("\n");
    printf("Total: %d",num);
}
