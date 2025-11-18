#include <stdio.h>

int main() {
    float score;
    
    printf("Enter your score: ");
    scanf("%f", &score);
    
    // printf("%f", score);
    
    if(score  >= 0 && score <= 100){
        if(score >= 80){
            printf("Class A");
        }else if (score >= 60 ){
            printf("Class B");
        }else if (score >= 40){
            printf("Class C");
        }else {
            printf("Sorry, you are failed!!!");
        }
    }else{
        printf("Invalid score!!!");
    }
    
    
    return 0;
}