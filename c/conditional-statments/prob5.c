#include <stdio.h>

void main(){
    int a;
    int b;
    int c;

    printf("Enter 3 Numbers sep with Space: ");
    scanf("%d %d %d",&a,&b,&c);

    if (a == b && b == c) {
        // all equal
        printf("Greatest Equivalent");
    } else if (a == b && a >= c) {
        // a & b equal and >= c
        printf("Greatest Equivalent");
    }else if (b == c && b >= a) {
        // b & c equal and >= a
        printf("Greatest Equivalent");
    } else if (a == c && a >= b) {
        // a & c equal and >= b
        printf("Greatest Equivalent");
    } else {
        // find the greatest normally
        if (a >= b && a >= c) {
            printf("%d\n", a);
        } else if (b >= a && b >= c) {
            printf("%d\n", b);
        } else {
            printf("%d\n", c);
        }
    }
}
