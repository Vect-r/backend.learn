#include <stdio.h>
//Comma precedence
void main(){
    int a = 1, b = 2, c = 3;
    int x = (a = b, b = c, c = a + b + c);
    printf("X: %d, A: %d;B: %d;C: %d",x,a,b,c);
    printf("\n");
    puts("X: %d, A: %d;B: %d;C: %d",x,a,b,c);
}
