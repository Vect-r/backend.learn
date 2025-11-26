#include <stdio.h>

int nNumSum(int n){
    printf("Value; %d\n",n);
   if (n == 1){
       return 1;
   }else{
       return n + nNumSum(n - 1);
   }
}

int main() {
    int num = 10;
    printf("%d ", nNumSum(num));

    return 0;
}
