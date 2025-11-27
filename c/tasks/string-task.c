#include <stdio.h>

int A_Upper='A',Z_Upper='Z',A_Lower='a',Z_Lower='z',luDiff=32;
int sDigit='0', eDigit='9';
int strBuffer=100;


void sep(){
    for(int i=0;i<(strBuffer-luDiff);i++){
        printf("=");
    }
    printf("\n");
}

int getLen(char str[strBuffer]){
    int l=0;
    while(str[l]!='\0'){
        l++;
    }
    return l;
}

int isUpper(int ascii){
    if (ascii>=A_Upper && ascii<=Z_Upper){
        return 1;
    }
    return 0;
}

int isDigit(int ascii){
    if (ascii>=sDigit && ascii<=eDigit){
        return 1;
    }
    return 0;
}

int isLower(int ascii){
    if (ascii>=A_Lower && ascii<=Z_Lower){
        return 1;
    }
    return 0;
}

void lower(char str[strBuffer]){
    for(int i=0;i<getLen(str);i++){
        int ascii=str[i];
        if (isUpper(ascii)){
            //If Upper
            printf("%c",ascii+luDiff);
        } else {
            //else Lower
            printf("%c",str[i]);
        }
    }
    printf("\n");
}

void upper(char str[strBuffer]){
    for(int i=0;i<getLen(str);i++){
        int ascii=str[i];
        if (isUpper(ascii)){
            //If Upper
            printf("%c",ascii);
        } else {
            //else Lower
            printf("%c",ascii-luDiff);
        }
    }
    printf("\n");
}

void capitalize(char str[strBuffer]){
    for(int i=0;i<getLen(str);i++){
        int ascii=str[i];
        if (i==0){
            if (isUpper(ascii)){
                printf("%c",ascii);
            } else {
                printf("%c",ascii-luDiff);
            }
        } else {
            if (isUpper(ascii)){
                printf("%c",ascii+luDiff);
            } else {
                printf("%c",str[i]);
            }
        }
    }
    printf("\n");
}

void title(char str[strBuffer]){
    for(int i=0;i<getLen(str);i++){
        int ascii=str[i];
        int OP=str[i-1];
        if (i==0){
            if (isUpper(ascii)){
                printf("%c",ascii);
            } else {
                printf("%c",ascii-luDiff);
            }
        } else if(OP==luDiff){
            if (isUpper(ascii)){
                printf("%c",ascii);
            } else {
                printf("%c",ascii-luDiff);
            }
        } else {
            if (isUpper(ascii)){
                printf("%c",ascii+luDiff);
            } else {
                printf("%c",str[i]);
            }
        }
    }
    printf("\n");
}

void swapcase(char str[strBuffer]){
    for(int i=0;i<getLen(str);i++){
        int ascii=str[i];
        if (isUpper(ascii)){
            printf("%c",ascii+luDiff);
        } else if(ascii>=97 && ascii<=122) {
            printf("%c",ascii-luDiff);
        } else {
            printf("%c",ascii);
        }
    }
}

void counter(char str[strBuffer],int choice){
    int ULen=0,LLen=0,DLen=0,SLen=0;
    for(int i=0;i<getLen(str);i++){
        int ascii=str[i];
        if (isUpper(ascii)){
            ULen++;
        } else if (isLower(ascii)){
            LLen++;
        } else if (isDigit(ascii)){
            DLen++;
        } else {
            SLen++;
        }
    }

    switch(choice){
    case 6:
        printf("Total Lowercase Characters are %d\n",LLen);
        break;
    case 7:
        printf("Total Uppercase Characters are %d\n",ULen);
        break;
    case 8:
        printf("Total Digits are %d\n",DLen);
        break;
    case 9:
        printf("Total Special Chars are %d\n",SLen);
        break;
    }
}

void main(){
//    printf("%d %d",A_Lower,Z_Lower);
    char str[strBuffer];
    int choice;
    printf("Enter string: ");
    gets(str);
    sep();
    printf("1. Print all in Lowercase\n");
    printf("2. Print all in Uppercase\n");
    printf("3. Print all in Titlecase\n");
    printf("4. Print all in Capitalize Case\n");
    printf("5. Print all in Swapcase\n");
    printf("6. Count all Lowercase Chars\n");
    printf("7. Count all Uppercase Chars\n");
    printf("8. Count all Digits\n");
    printf("9. Count all Special Chars\n");
    sep();
    printf("Choice? ");
    scanf(" %d",&choice);
    switch(choice){
        case 1:
            lower(str);
            break;
        case 2:
            upper(str);
            break;
        case 3:
            title(str);
            break;
        case 4:
            capitalize(str);
            break;
        case 5:
            swapcase(str);
            break;
        case 6 ... 9:
            counter(str,choice);
            break;
        default:
            printf("Error, Try Again");
    }
}
