#include <stdio.h>

int num=10;

void printer(int index, int val){
    arr1[index]=val;
}

int fibo(int n){
//    printf("Value: %d\n",n);
    if (n==0){
        return 0;
    } else if (n==1){
        return 1;
    } else {
        int p=fibo(n-1)+fibo(n+2);
        printer(n,p);
    }
}

void main(){
    int n=10;
    printf("%d \n",fibo(num));
    for(int i=0;i<num;num++){
        printf("%d ",arr1[i]);
    }
}
