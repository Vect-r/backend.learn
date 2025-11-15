#include <stdio.h>

void main() {
    int c1 = 0; // false
    int c2 = 1; // true
    int c3 = 10 < 20; // true
    int c4 = 30 < 20; // false

    int res = !((c1 && c3) || (c2 || c3) && (c4 && c3));
    printf("%d\n", res);

    int res1 = (2+3)*4==14;
    printf("%d\n",res1);

    int x = 1, y = 2, z = 3;
    x = y, z = x + y * z;
    printf("X: %d;Y: %d;Z: %d",x,y,z);
}
