    #include <stdio.h>

    int main() {
        char myString[100];
        printf("Enter String? ");
        gets(myString);
        int length = 0;
        printf("%d %d",'a','z');

        while (myString[length] != '\0') {
            length++;
            if (myString[length]==' '){
                printf("Space at %d %d\n", length,myString[length]);
            }

        }

        printf("Length of myString (excluding null terminator): %d\n", length);

        return 0;
    }
