#include <stdio.h>

void main(){
    int num = 10;
    int n0 = 0,n1 = 1, nth;
    for(int i=0;i<num;i++){
        if (i==0){
            printf("0 \n");
        } else if (i==1){
            printf("1 \n");
        } else {
            printf("Pre; nth: %d,n0: %d,n1: %d\n",nth,n0,n1);
            nth = n0 + n1;
            n0 = n1;
            n1 = nth;
            printf("Post; nth: %d,n0: %d,n1: %d\n",nth,n0,n1);
            printf("%d \n",nth);
        }
    }
}
