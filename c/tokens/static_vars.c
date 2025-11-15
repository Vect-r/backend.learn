#include <stdio.h>

void main(){
    printf("Static Data Types\n\n");

    int age = 25;
    printf("Age (int) output: %d\n",age);

    float pi = 3.14;
    printf("Pi (float) output: %f\n",pi);

    double decimal = 3.3415;
    printf("decimal (double): %lf\n",decimal);

    char letter = 'A';
    printf("letter (char): %c\n", letter);

    printf("Derived Data Types\n\n");

    int marks[5] = {10, 20, 30, 40, 50};
    printf("Array (int): %d\n", marks[4]);
}
