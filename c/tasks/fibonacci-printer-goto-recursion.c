#include <stdio.h>

int main() {
    int n,c = 0;
    int n0=0,n1=1,nth;

    printf("Enter No? ");
    scanf(" %d",&n);


    fibo:
        if(c>n){
            return 0;
        }

        if(c==0){
            printf("0 ");
        } else if (c==1) {
            printf("1 ");
        } else {
            nth=n0+n1;
            n0=n1;
            n1=nth;
            printf("%d ",nth);
        }
        c++;
        goto fibo;

    return 0;

}
