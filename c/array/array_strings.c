#include <stdio.h>

void main(){
    char subs[5][25] = {"Maths","Science","Social Science","English","Information Technology"};
    int size = sizeof(subs)/sizeof(subs[0]);
    printf("Size: %d\n",size);
    for(int r=0;r<size;r++){
        printf("%s\n",subs[r]);
    }
    //String Manipulation

    subs[5]="FIT"
    printf("\n")

}
