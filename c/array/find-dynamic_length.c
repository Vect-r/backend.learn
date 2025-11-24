#include <stdio.h>

int main() {
    int matrix1[2][4] = {
        {1,2,3,11},
        {4,5,6,44}
    };
    
    int len_row = sizeof(matrix1)/ sizeof(matrix1[0]);
    printf("len_row: %d\n", len_row);
    
    int len_col = sizeof(matrix1[0])/ sizeof(matrix1[0][0]);
    printf("len_col: %d\n", len_col);
    
    
    
    for(int row = 0; row < len_row; row++){
        for(int col = 0; col < len_col; col++){
            printf("%d ", matrix1[row][col]);
        }
        printf("\n");
    }
    
    
    return 0;
}