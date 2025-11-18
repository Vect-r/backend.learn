#include <stdio.h>

void main(){
    int a;
    int b;
    int c;

    printf("Enter Triangles Sides Sep with Space: ");
    scanf("%d %d %d",&a,&b,&c);

    if (a>0 && b>0 && c>0) {
        if ( (a+b>c) || (a+c>b) || (b+c>a) ) {
//            printf("Valid Triangle\n");

            if (a==b && b==c){
                printf("Equilateral");
            } else if (a==b||b==c||c==a){
                printf("Isosceles");
            } else {
                printf("Scalene");
            }
        }

    } else {
        printf("Invalid Triangle");
    }
}
