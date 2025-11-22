#include <stdio.h>
int main()
{
    int num = 9;
    for(int row = 1; row <= num; row++){
      for(int col = 1; col <= row; col++){
        if (row % 2 == 0) {
          if (col == 1){
            printf("* ");
            continue;
          }else{
            printf("  ");
          }
        }else{
          printf("* ");
        }
      }
      for(int col = num-row; col >= 1; col--){
          if (col % 2 == 0){
            if (row == 1){
              printf("* ");
              continue;
            }else{
              printf("  ");
            }
          }else{
            printf("* ");
          }
      }
      printf("\n");
    }
}
