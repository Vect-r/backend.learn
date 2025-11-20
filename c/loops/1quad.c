#include <stdio.h>

int main() {
    int end = 5;
    for(int row = 1; row <= end; row+=1){
        for(int col = 1; col <= row; col+=1){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
