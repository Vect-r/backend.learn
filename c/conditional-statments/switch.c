#include <stdio.h>

int main() {
   int day = 5;
   switch(day-1){
       case 0:
            printf("Mon");
            break;
       case 1:
            printf("Tue");
            break;
       case 2:
            printf("Wed");
            break;
       case 3:
            printf("Thu");
            break;
       case 4:
            printf("Fri");
            break;
       case 5:
            printf("Sat");
            break;
       case 6:
            printf("Sun");
            break;
        default:
            printf("Invalid day");
   }
    return 0;
}
