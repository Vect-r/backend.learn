#include <stdio.h>

int main() {
   int age;
   float weight;

   printf("Enter age: ");
   scanf("%d", &age);


   if(age >= 18){
       printf("Enter wight: ");
       scanf("%f", &weight);
       if(weight >= 50){
           printf("You can donate");
           return 1;
       }else{
           printf("Your weight is less than 50");
           return 0;
       }
   }else{
       printf("Your age is less than 18");
       return 0;
   }
    return 0;
}
