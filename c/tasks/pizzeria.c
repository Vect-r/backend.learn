#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

int sepLen = 90;

void seperator(){
    //To Differen
    for(int i=0;i<sepLen;i++){
        printf("=");
    }
    printf("\n");
}

void star_seperator(){
    //To Differen
    for(int i=0;i<sepLen;i++){
        printf("*");
    }
    printf("\n");
}

char* getFormattedDateTime() {
    // Get the current time
    static char buffer[100];  // Static to ensure the string remains valid outside this function
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);  // Get current time
    timeinfo = localtime(&rawtime);  // Convert to local time

    // Format the time and store in buffer
    strftime(buffer, sizeof(buffer), "%a, %b %d %I:%M %p", timeinfo);

    return buffer;
}

void pizza_menu(){
    system("clear");
    char category[3][50]={
        "The OGs\n",
        "Indian Zaikas (Veg).\n",
        "Indian Zaikas (Non Veg).\n"
    };
    char pizzas[3][4][30]={
        {"Margharita",
         "Cheese Lovers",
         "Veggie Supreme",
         "Neapolitan Pizza",
        },{
         "Tandoori Paneer",
         "Makhani Pizza",
         "Paneer 65",
         "Flamin\' Hot",
        },{
         "Bhuna Murg",
         "Butter Chicken Pizza",
         "Tandoori Chicken Pizza",
         "Keema Do Pyaza"
        }
    };
    int prices[3][5]={
        {89,199,299,399,499},
        {109,249,349,449,549},
        {189,299,379,479,579},
    };

    int catSize=sizeof(category)/sizeof(category[0]);
    int subCatSize=sizeof(pizzas[0])/sizeof(pizzas[0][0]);
    int priceSize=sizeof(prices[0])/sizeof(prices[0][0]);

    printf("\n");
    seperator();
    printf("1. Pizzas\n");
    seperator();
    printf("\n");

    printf("\t\t(Sl)\t(S)\t(M)\t(L)\t(X)\n");

    for(int cat=0;cat<catSize;cat++){
        star_seperator();
        printf("%d. %s\t",cat+1,category[cat]);
        for(int i=0;i<priceSize;i++){
            printf("\t%d",prices[cat][i]);
        }
        printf("\n");
        for(int i=0;i<subCatSize;i++){
            printf(" %d.%d %s\n",cat+1,i+1,pizzas[cat][i]);
        }
    }
    star_seperator();
    printf("S - Small (6 inches)\n");
    printf("\tPerfect for one person, great for a quick snack or light meal.\n");
    printf("M - Medium (9 inches)\n");
    printf("\tA good choice for individuals or couples.\n");
    printf("L - Large (12 inches)\n");
    printf("\tIdeal for sharing, or for those with a big appetite.\n");
    printf("X - X-Large (15 inches)\n");
    printf("\tA family-sized pizza, perfect for group meals and parties.\n");
}

void main_menu(){
    char menu[5][20] = {"1. Pizza\n","2. Pasta\n","3. Side & Dips\n","4. Desserts\n","5. Combo Offers\n"};
    int size=sizeof(menu)/sizeof(menu[0]);
    for (int i=0;i<size;i++){
        printf("%s",menu[i]);
    }

    seperator();

    menu:
        int choice;
        printf("So What Would you like to have Today?");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            pizza_menu();
            break;
        default:
            printf("Error!!. Please Try Again\n");
            goto menu;
        }
}

int greetings(){
    seperator();
    printf("Greetings from Zaika Pizzeria\n (Aroma of Indian Flavours blended with Italian Cuisine)\n\n \t\t\t\t\t %s\n",getFormattedDateTime());
    seperator();
    printf("Hello User, What would like to have today\n");
}

void main(){
    greetings();
    main_menu();
}
