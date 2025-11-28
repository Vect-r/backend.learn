#include <stdio.h>
#include <string.h>

struct book{
    char name[100];
    int page;
    float price;
}b1, b2;

void main() {
    // struct book b1, b2;
    strcpy(b1.name, "Python");
    b1.page = 400;
    b1.price = 450;
    
    printf("Name: %s\n", b1.name);
    printf("Page: %d\n", b1.page);
    printf("Price: %.2f", b1.price);
    
    strcpy(b2.name, "java");
    b2.page = 500;
    b2.price = 550;
    
    printf("Name: %s\n", b2.name);
    printf("Page: %d\n", b2.page);
    printf("Price: %.2f", b2.price);
}