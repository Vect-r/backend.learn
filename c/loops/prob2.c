#include <stdio.h>

int main() {
    int end = 1, num = 5;
    for (int row=num;row>=end;row--){
        for (int col=row; col>=end; col--){
            printf(" ");
        }
        printf("%d\n",row);
    }
}
