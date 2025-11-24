#include <stdio.h>

int main() {
    int matrix1[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    int matrix2[2][3] = {
        {11,22,33},
        {44,55,66}
    };
    
    for(int row = 0; row < 2; row++){
        for(int col = 0; col < 3; col++){
            printf("%d ", matrix1[row][col]);
        }
        printf("\n");
    }
    
    for(int row = 0; row < 2; row++){
        for(int col = 0; col < 3; col++){
            printf("%d ", matrix2[row][col]);
        }
        printf("\n");
    }
    
    printf("Matrix multiplication: \n");
    for(int row = 0; row < 2; row++){
        for(int col = 0; col < 3; col++){
            printf("%d ", matrix1[row][col] * matrix2[row][col]);
        }
        printf("\n");
    }
    
    
    return 0;
}