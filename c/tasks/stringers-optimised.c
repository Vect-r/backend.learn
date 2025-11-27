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

void lower(int ascii){
    if (isUpper(ascii)){
        printf("%c",ascii+luDiff);
    } else {
        printf("%c",ascii);
    }
}

void upper(int ascii){
    if (isUpper(ascii)){
        printf("%c",ascii);
    } else {
        printf("%c",ascii-luDiff);
    }
}


void main(){
    char str[strBuffer];
    int choice;
    char choices[9][50]={"1. Print all in Lowercase\n","2. Print all in Uppercase\n","3. Print all in Titlecase\n",
    "4. Print all in Capitalize Case\n","5. Print all in Swapcase\n","6. Count all Lowercase Chars\n","7. Count all Uppercase Chars\n","8. Count all Digits\n","9. Count all Special Chars\n"};
    printf("Enter string: ");
    gets(str);
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
    sep();
    for(int i=0;i<9;i++){
        printf("%s",choices[i]);
    }
    sep();

    menu:
        printf("Choice? ");
        scanf("%d",&choice);
        switch(choice){
            case 1 ... 5:
                for(int i=0;i<getLen(str);i++){
                    int ascii=str[i];
                    int OP=str[i-1];
                    switch (choice){
                    case 1:
                        lower(ascii);
                        break;
                    case 2:
                        upper(ascii);
                        break;
                    case 3:
                        if (i==0){
                            upper(ascii);
                        }else if(OP==luDiff){
                            upper(ascii);
                        } else {
                            lower(ascii);
                        }
                        break;
                    case 4:
                        if (i==0){
                            upper(ascii);
                        } else {
                            lower(ascii);
                        }
                        break;
                    case 5:
                        if (isUpper(ascii)){
                            lower(ascii);
                        } else if (isLower(ascii)){
                            upper(ascii);
                        } else {
                            printf("%c",ascii);
                        }
                        break;
                    }
                }
                break;
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
            default:
                printf("Error, Try Again\n");
                goto menu;
        }
}
