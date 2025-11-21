#include <stdio.h>

int main() {
    int num = 7; // Size of the grid
    for(int row = 1; row <= num; row++) { // Iterate through each row
        for(int col = 1; col <= num; col++) { // Iterate through each column
            // Conditions to print a star '*':
            if((row == 1 || row == num) // Top row or bottom row
                || (col == 1 || col == num) // First column or last column
                || (row == col) // Primary diagonal (top-left to bottom-right)
                || (col == num - row + 1)) { // Secondary diagonal (top-right to bottom-left)
                printf("* "); // Print star with space
            } else {
                printf("  "); // Print two spaces for alignment
            }
        }
        printf("\n"); // Move to the next line after finishing a row
    }
    return 0;
}
