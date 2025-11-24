#include <stdio.h>

int main() {
    // int matrix[] = { 1,2,3 };
    
    // access array element
    // printf("%d", matrix[0]);
    // access whole element by for
    // for(int start = 0; start<3; start++){
    //     printf("%d\n", matrix[start]);
    // }
    int total_stu = 5;
    float stu_marks[total_stu * 4];
    
    // assign marks to array
    for(int start = 0; start<total_stu; start++){
        float mark;
        printf("\nEnter stu-%d Marks: ", start);
        scanf("%f", &mark);
        
        stu_marks[start] = mark;
        // printf("%d\n", matrix[start]);
    };
    
    // use marks
     for(int start = 0; start<total_stu; start++){
         printf("stu-%d Mark is: %.2f\n",start, stu_marks[start]);
     };
    

    return 0;
}