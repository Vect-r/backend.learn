#include <stdio.h>

void main(){
    int a;
    int b;
    char opt;



    printf("Enter a:");
    scanf("%d",&a);


    printf("Enter b:");
    scanf("%d",&b);

    printf("Enter operator:");
    scanf(" %c",&opt);



    printf("%c\n",opt);

    if (opt=='+'){
        printf("%d",a+b);
    } else if (opt=='-') {
        printf("%d",a-b);
    } else if (opt=='*') {
        printf("%d",a*b);
    } else if (opt=='/'){
        if (b==0) {
            printf("Cannot divide by zero");
        } else {
            printf("%d",a/b);
        }
    } else {
        printf("Invalid Operator");
    }
}
