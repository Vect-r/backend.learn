#include <stdio.h>

int cLen = 65;

void sep(){
    for(int f=0;f<cLen;f++){
        printf("=");
    }
    printf("\n");
}

void main(){
    int TStuds;
    char subs[5][25] = {"Maths","Science","Social Science","English","Information Technology"};
    int sub_size = sizeof(subs)/sizeof(subs[0]);

    sep();
    printf("Total no of students? ");
    scanf(" %d",&TStuds);
    sep();

    float marks[TStuds*4][sub_size];

    for(int step=0;step<TStuds;step++){
        sep();
        printf("Student %d\n",step+1);
        sep();
        for(int sub=0;sub<sub_size;sub++){
            while(1){
                float mark;
                printf("Enter Marks of subject %s: ",subs[sub]);
                scanf(" %f",&mark);
                if (mark<=100.0 && mark>=0){
                    marks[step][sub]=mark;
                    break;
                } else {
                    printf("Error! Try Again\n");
                    continue;
                }

            }

        }
        sep();
    }
//    for(int step=0;step<TStuds;step++){
//        printf("Student: %d\n",step+1);
//        for(int sub=0;sub<sub_size;sub++){
//            printf("%s: %.2f\n",subs[sub],marks[step][sub]);
//        }
//    }
    int stud;
    float totalMarks;
    int choice;

    while(1){
        printf("Enter Student Index no: ");
        scanf(" %d",&stud);
        stud--;
        printf("Stud: %d\n",stud);
        if(stud>-1 && stud<TStuds){
            break;
        } else {
            printf("Invalid Index No. Try Again.\n");
            continue;
        }
    }

    for(int sub=0;sub<sub_size;sub++){
        totalMarks+=marks[stud][sub];
    }

    sep();
    printf("1. Get Total marks obtained\n");
    printf("2. Get Percentage\n");
    printf("3. Get Marksheet\n");
    sep();
    printf("Enter Choice? ");
    scanf(" %d",&choice);
    sep();
    switch (choice){
        case 1:
            printf("Total Marks of Student %d is %.2f / 500\n",stud+1,totalMarks);
            break;
        case 2:
            printf("Percentage of Student %d is %.2f %\n",stud+1,(totalMarks/500)*100);
            break;
        case 3:
            printf("* Student: %d\n",stud+1);
            // Incomplete

    }
    sep();
}
