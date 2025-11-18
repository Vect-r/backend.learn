#include <stdio.h>

void main(){
    //int x = 10, y = 20, z = 30;
    //int result = x > y ? x : y > z ? y : z;
    //int x = -15;
    //int abs_val = (x < 0) ? -x : x;
    //printf("%d",abs_val);
    int a = 10, b = 20, c = 5;
    int largest = (a > b)
                ? (a > c ? a : c)
                : (b > c ? b : c);
    printf("%d", largest);
}
