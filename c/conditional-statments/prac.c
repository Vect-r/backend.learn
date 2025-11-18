#include <stdio.h>

void main(){
    char letter;
    int ascii_val;
    printf("Enter a Char: ");
    scanf("%c",&letter);
    ascii_val = letter;
    //printf("%d\n",ascii_val);

    if (ascii_val>=65 && ascii_val<=90){
        printf("Uppercase Letter");
    } else if( ascii_val>=97 && ascii_val<=122) {
        printf("Lowercase Letter");
    } else if (ascii_val>=48 && ascii_val<=57) {
        printf("Digit");
    } else {
        printf("Special Character");
    }
}
