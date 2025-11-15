#include <stdio.h>

void main() {
    int bal = 1000;
    int wb = 1250;
    
    // () ? true : false
    (wb <= bal) ? printf("Remaining bal. is: %d", bal - wb) : printf("Insufficent bal");
}