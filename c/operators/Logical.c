#include <stdio.h>

void main() {
// &&, ||, !

// A B C && ||
// t t t t  t
// f t t f  t
// t f t f  t
// t t f f  t
// f f f f  f

// A !
// t f
// f t

int c1 = 0; // false
int c2 = 1; // true
int c3 = 10 < 20; // true
int c4 = 30 < 20; // false

// int res = c1 && c2; // 0
// int res = c1 && c3; // 0
// int res = c2 && c3; // 1
// int res = c2 || c3; // 1
// int res = c2 || c1; // 1
// int res = ! c1; // 1

int res = !((c1 && c3) || (c2 || c3) && (c4 && c3));

printf("%d", res);
   

}