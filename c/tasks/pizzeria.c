#include <stdio.h>
#include <time.h>
#include <string.h>

int sepLen = 120, Bc =0;

struct Biller{
    char name[50];
    int quantity;
    int price;
};

struct Item{
    char name[30];
    char desc[300];
    int price;
};

struct Biller bill[50];

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

void add_to_bill(char itemname[100],int quantity, int price){
    strcpy(bill[Bc].name,itemname);
    bill[Bc].quantity=quantity;
    bill[Bc].price=price;
    Bc++;
}

int ask_quantity(){
    //It was going to repeat again and again so i created a function
    int q;
    printf("How much Quantity? ");
    scanf(" %d",&q);
    if(q>5){
        printf("Sorry. We are busy we can't take order more than 5.");
        ask_quantity();
    } else {
        return q;
    }
}

int pizza_menu(){
    int choice;
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
            //subCat //size
    int prices[3][5]={
        {89,199,299,399,499},
        {109,249,349,449,549},
        {189,299,379,479,579},
    };

    char servingMenu[5][100]={
        "1. Giant Slice\n",
        "2. S - Small (6 inches)\n\tPerfect for one person, great for a quick snack or light meal.\n",
        "3. M - Medium (9 inches)\n\tA good choice for individuals or couples.\n",
        "4. L - Large (12 inches)\n\tIdeal for sharing, or for those with a big appetite.\n",
        "5. X - X-Large (15 inches)\n\tA family-sized pizza, perfect for group meals and parties.\n"
    };

    char servingFlags[5][2]={
        "SL","S","M","L","X"
    };

    int servingMenuSize=sizeof(servingMenu)/sizeof(servingMenu[0]);
    int catSize=sizeof(category)/sizeof(category[0]);
    int subCatSize=sizeof(pizzas[0])/sizeof(pizzas[0][0]);
    int priceSize=sizeof(prices[0])/sizeof(prices[0][0]);
    int catChoice,subCatChoice,quantity,price;
    char pizza[40];

    printf("\n");
    seperator();
    printf("1. Pizzas\n");
    seperator();
    printf("\n");


    menu:
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
        printf("Enter as Followed example 1.1\n");

    choose_pizza:
        printf("Which Pizza you would like to order?");
        scanf(" %d.%d",&catChoice,&subCatChoice);

        switch(catChoice){
            case 1 ... 3 :
                catChoice--;
                break;
            default:
                printf("Please try again.\n");
                goto choose_pizza;
        }

        switch(subCatChoice){
            case 1 ... 4 :
                subCatChoice--;
                break;
            default:
                printf("Please try again.\n");
                goto choose_pizza;
        }
//        printf("%d.%d",catChoice,subCatChoice);
        strcat(pizza,pizzas[catChoice][subCatChoice]);
        goto choose_serving;

    choose_serving:
        int temp;
        star_seperator();
        for(int i=0;i<servingMenuSize;i++){
            printf("%s",servingMenu[i]);
        }
        star_seperator();
        printf("Choose Serving Size? ");
        scanf("%u",&temp);
        if(temp>0 && temp<=servingMenuSize){
            strcat(pizza," ");
            strcat(pizza,servingFlags[temp-1]);
            price=prices[catChoice][temp-1];
            quantity=ask_quantity();
            add_to_bill(pizza,quantity,price);
        } else {
            printf("Error. Please Try again\n");
            goto choose_serving;
        }

     want_more_pizza:
        printf("1. Yes i would like to order more\n");
        printf("2. Nah, I'm Fine.\n");
        int resp;
        printf("Would you want to order another Pizza? ");
        scanf(" %d",&resp);
        switch(resp){
        case 1:
            strcpy(pizza,"");
            goto menu;
            break;
        case 2:
            printf("What would you like to order than Pizza?\n");
            return 0;
        default:
            goto want_more_pizza;

        }
}


int pasta(){
    seperator();
    printf("2. Pasta\n");
    seperator();
    char pasta_names[5][30] = {
        "Tandoori Chicken Pasta",
        "Palak Paneer Pasta",
        "Spicy Pesto Pasta",
        "Penne Arrabbiata (Spicy)",
        "Butter Chicken Pasta"
    };

    char pasta_descriptions[5][300] = {
        "Creamy pasta with smoky tandoori chicken and a rich, spiced tomato sauce.\n",
        "Delicious fusion of creamy spinach sauce and paneer in a comforting pasta dish, spiced with Indian masalas.\n",
        "A fresh twist on classic pesto, with mint, coriander, and green chilies for a bold Indian flavor.\n",
        "Penne pasta tossed in a fiery, garlicky tomato sauce with a hint of Indian red chili heat.\n",
        "Tender pasta in a rich and creamy butter chicken sauce, with juicy chunks of chicken and aromatic spices.\n"
    };

    int prices[5]={300,280,250,220,350};
    int sizePastaMenu=sizeof(pasta_names)/sizeof(pasta_names[0]);
    char pasta[30];
    int quantity,price;

    menu:
        star_seperator();
        for(int i=0;i<sizePastaMenu;i++){
            printf("%d %s Rs.%d\n\t%s",i+1,pasta_names[i],prices[i],pasta_descriptions[i]);
        }
        star_seperator();

    choose_menu:
        int choice;
        printf("So Which Pasta would you like select? ");
        scanf(" %d",&choice);
        if (choice>0 && choice<=sizePastaMenu){
            strcpy(pasta,pasta_names[choice-1]);
            price=prices[choice-1];
            quantity=ask_quantity();
            add_to_bill(pasta,quantity,price);
        } else {
            printf("Error!! Please Try Again\n");
            goto choose_menu;
        }

    want_more_pasta:
        printf("1. Yes i would like to order more\n");
        printf("2. Nah, I'm Fine.\n");
        int resp;
        printf("Would you want to order another Pasta? ");
        scanf(" %d",&resp);
        switch(resp){
        case 1:
            strcpy(pasta,"");
            goto menu;
            break;
        case 2:
            printf("What would you like to order than Pasta?\n");
            return 0;
        default:
            goto want_more_pasta;
        }
}

void main_menu(){
    char menu[6][20] = {"1. Pizza\n","2. Pasta\n","3. Side & Dips\n","4. Desserts\n","5. Combo Offers\n","6. Exit\n"};
    int size=sizeof(menu)/sizeof(menu[0]);
    seperator();

    menu_print:
        for (int i=0;i<size;i++){
            printf("%s",menu[i]);
        }

    choose_menu:
        int choice;
        printf("So What Would you like to have Today?");
        scanf(" %d",&choice);
        switch(choice){
            case 1:
                pizza_menu();
                goto menu_print;
            case 2:
                pasta();
                goto menu_print;
            case 6:
                break;
            default:
                printf("Error!! Try Again");
                goto choose_menu;
        }
}

void gimme_the_bill_man(){
    int total=0;
    printf("\n\n");
    seperator();
    printf("Bill Date & Time: %s\n",getFormattedDateTime());
    printf("Name\t\t\tQty\tPrice\t\tTotal\n");
    for(int i=0;i<Bc;i++){
        printf("%s %d %d %d\n",bill[i].name,bill[i].quantity,bill[i].price,bill[i].quantity*bill[i].price);
        total+=bill[i].price;
    }
    seperator();
    printf("Total %d\n",total);
}

int greetings(){
    seperator();
    printf("Greetings from Zaika Pizzeria\n (Aroma of Indian Flavours blended with Italian Cuisine)\n\n \t\t\t\t\t\t\t\t %s\n",getFormattedDateTime());
    seperator();
    printf("Hello User, What would like to have today\n");
}

void main(){
    greetings();
    main_menu();
    gimme_the_bill_man();
}
