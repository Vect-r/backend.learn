#include <stdio.h>

void main(){
    int nums[5]={45,23,10,53,34};

    int order[5];

    for (int i=0;i<5;i++){
        if(nums[i]<nums[i+1]){
            printf("Yes");
        } else {
            printf("No");
        }
    }

}
