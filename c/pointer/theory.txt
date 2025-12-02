// a pointer is a variable that stores the memory address of another variable. Pointers are fundamental to C and provide a powerful mechanism for direct memory manipulation, enabling features like dynamic memory allocation, efficient array handling, and passing arguments by reference to functions. 

syntax:

// int *pointer_name = &anothor_var_memory_adress;

#include <stdio.h>

int main() {
    int num1 = 10;
    int *num2;
    int **num3;
    num2 = &num1;
    num3 = &num2;
    
    printf("%x\n", num2);
    printf("%d\n", *num2);
    printf("%d\n", **num3);

    return 0;
}


#include <stdio.h>

int add(int *a, int *b){
    return *a + *b;
}

int main() {
    int num1 = 10, num2 = 20;
    printf("pinter sum: %d", add(&num1, &num2));

    return 0;
}


-------------------------------
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int *ptr;
    printf("Enter a number: ");
    scanf("%d", &n);
    int nums[n];
    
    ptr = (int *)malloc(sizeof(int) * n);
    
    if(ptr == NULL){
        printf("Memory not allocated");
    }else{
        printf("Memory allocated");
    }
    
    for(int start = 0;start < n; start++){
        printf("\nEnter a num-%d: ", start);
        scanf("%d", &nums[start]);
    }
    
    for(int start = 0;start <n; start++){
        printf("%d\n", nums[start]);
    }
    
    
    return 0;
}


---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int *ptr;
    printf("Enter a number: ");
    scanf("%d", &n);
    int nums[n];
    
    ptr = (int *)calloc(n,sizeof(int));
    
    if(ptr == NULL){
        printf("Memory not allocated");
    }else{
        printf("Memory allocated");
    }
    
    for(int start = 0;start < n; start++){
        printf("\nEnter a num-%d: ", start);
        scanf("%d", &nums[start]);
    }
    
    for(int start = 0;start <n; start++){
        printf("%d\n", nums[start]);
    }
    
    
    return 0;
}

--------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(5 * sizeof(int));

    // Resize the memory block to hold 10 integers
    ptr = (int *)realloc(ptr, 10 * sizeof(int));
    
    // Check for allocation failure
    if (ptr == NULL) {
        printf("Memory Reallocation Failed");
        exit(0);
    }

    return 0;
}

-------------------------------


#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // Allocate memory for an array of 5 integers
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Use the allocated memory
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);
    arr = NULL; // Set pointer to NULL after freeing

    printf("Memory freed successfully.\n");

    return 0;
}