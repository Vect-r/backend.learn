#include <stdio.h>

int main() {
    int start = 1, end = 10;
    
    for(start; start<=end; start++){
        printf("Something.....1\n");
        printf("Something.....2\n");
        if (start == 2){
            printf("continue\n");
            continue;
        }
        printf("Something.....3\n");
        if (start == 5){
            printf("Breck\n");
            break;
        }
        printf("%d\n", start);
    }
  

    return 0;
}