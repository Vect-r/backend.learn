#include <stdio.h>
int num;

void main(){
    int b = 1;
    while (b) {
        printf("Enter a No.");
        scanf("%d", &num);

        if (num%2==0){
            printf("The Number %d is Even Number.\n",num);
        } else {
            printf("The Number %d is Odd Number.\n",num);
        }
    }
}
