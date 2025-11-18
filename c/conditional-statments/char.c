#include <stdio.h>

int main() {
    char myChar;

    printf("Enter a character: ");
    scanf("%c", &myChar); // Reads a single character and stores it in myChar

    printf("You entered: %c\n", myChar);

    return 0;
}
