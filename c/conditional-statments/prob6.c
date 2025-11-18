#include <stdio.h>


void main(){
    int temp = 50;

    if (temp<=100 && temp>=-100){
        //printf("Temp OK");
        if (temp<=0){
            printf("Freezing");
        } else if (temp>0 && temp<=20) {
            printf("Cold");
        } else if (temp>20 && temp<=35){
            printf("Warm");
        } else if (temp>35 && temp<50) {
            printf("Hot");
        } else if (temp>=50) {
            printf("Extreme Heat");
        }
    } else {
        printf("Invalid Temperature");
    }
}
