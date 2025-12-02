#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int sepLen = 120, Bc =0, discountOffer=0,weekDay,hasDiscount=0;
char itemName[40],days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

struct Biller{
    char name[40];
    int quantity;
    int price;
    char type[6];
};

//struct Offer{
//    char type[6];
//    int discount;
//    int dayofWeek;
//};

struct Biller bill[50];
//struct Offer offers[3];




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

int getDayOfWeek(){
    time_t currentTime;
    struct tm *localTime;

    // Get the current calendar time
    time(&currentTime);

    // Convert to local time format
    localTime = localtime(&currentTime);

    // The tm_wday field holds the day of the week (0 = Sunday, 6 = Saturday)
    int dayOfWeekNum = localTime->tm_wday;
    return dayOfWeekNum;
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

void add_to_bill(char itemname[100],int quantity, int price, char type[6]){
    strcpy(bill[Bc].name,itemname);
    strcpy(bill[Bc].type,type);
    bill[Bc].quantity=quantity;
    bill[Bc].price=price;
    Bc++;
}

int ask_quantity(){
    //It was going to repeat again and again so i created a function
    int q;
    printf("How much Quantity? ");
    scanf(" %d",&q);
    if(q<1){
        printf("Error try again.\n");
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
            add_to_bill(pizza,quantity,price,"Pizza");
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
            seperator();
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
            add_to_bill(pasta,quantity,price,"Pasta");
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
            seperator();
            printf("What would you like to order than Pasta?\n");
            return 0;
        default:
            goto want_more_pasta;
        }
}

int sides_and_dips(){
    char items[7][30] = {
        "Garlic Bread","Cheesy Garlic Bread","Onion Rings","French Fries","Crispy Paneer Bites","BBQ Chicken Wings","Samosa Bites"
    };
    int prices[7]={99,129,149,129,169,199,99};

    int menuSize=sizeof(items)/sizeof(items[0]);
    char item[30];
    int quantity,price;

    menu:
        star_seperator();
        for(int i=0;i<menuSize;i++){
            printf("%d %s Rs.%d\n",i+1,items[i],prices[i]);
        }
        star_seperator();

    choose_menu:
        int choice;
        printf("So Which Sides & Dips you would like to order? ");
        scanf(" %d",&choice);
        if (choice>0 && choice<=menuSize){
            strcpy(item,items[choice-1]);
            price=prices[choice-1];
            quantity=ask_quantity();
            add_to_bill(item,quantity,price,"Sides");
        } else {
            printf("Error!! Please Try Again\n");
            goto choose_menu;
        }

    want_more:
        printf("1. Yes i would like to order more\n");
        printf("2. Nah, I'm Fine.\n");
        int resp;
        printf("Would you want to order another Sides & Dips? ");
        scanf(" %d",&resp);
        switch(resp){
        case 1:
            strcpy(item,"");
            goto menu;
            break;
        case 2:
            seperator();
            printf("What would you like to order rather than Sides & Dips?\n");
            return 0;
        default:
            goto want_more;
        }

}

int drinks(){
    char items[9][30] = {
        "Coca Cola 250Ml","Sprite 250Ml","Fanta 250 Ml",
        "Coca Cola 500Ml","Sprite 500Ml","Fanta 500 Ml",
        "Coca Cola 1L","Sprite 1L","Fanta 1L"};
    int prices[9]={20,20,20,35,35,35,55,55,55};

    int menuSize=sizeof(items)/sizeof(items[0]);
    char item[30];
    int quantity,price;

    menu:
        star_seperator();
        for(int i=0;i<menuSize;i++){
            printf("%d %s Rs.%d\n",i+1,items[i],prices[i]);
        }
        star_seperator();

    choose_menu:
        int choice;
        printf("So Which Drink you would like to order? ");
        scanf(" %d",&choice);
        if (choice>0 && choice<=menuSize){
            strcpy(item,items[choice-1]);
            price=prices[choice-1];
            quantity=ask_quantity();
            add_to_bill(item,quantity,price,"Drinks");
        } else {
            printf("Error!! Please Try Again\n");
            goto choose_menu;
        }

    want_more:
        printf("1. Yes i would like to order more\n");
        printf("2. Nah, I'm Fine.\n");
        int resp;
        printf("Would you want to order another Drinks? ");
        scanf(" %d",&resp);
        switch(resp){
        case 1:
            strcpy(item,"");
            goto menu;
            break;
        case 2:
            seperator();
            printf("What would you like to order rather than Drinks?\n");
            return 0;
        default:
            goto want_more;
        }

}

int combo_offers(){
    char items[4][30] = {
        "Solo Combo","Couple Combo","Family Feast","Party Pack",
    };
    int prices[4]={299,499,799,999};

    char desc[4][70]={
        "Margherita Pizza S + Samosa + 1 Cold Drink 250ml",
        "Flamin Hot M + Garlic Bread + 1 Cold Drink 500ml",
        "Paneer 65 L + Garlic Bread + 1 Cold Drink 1 Ltr",
        "Bhuna Murg XL + Penne Arabita Pasta + 1 Cold Drink 1Ltr"
    };

    char drinks[3][10]={"Coca Cola","Sprite","Fanta"};
    int drinkSize = sizeof(drinks)/sizeof(drinks[0]);
    int menuSize=sizeof(items)/sizeof(items[0]);
    char item[30];
    int quantity,price;

    menu:
        star_seperator();
        for(int i=0;i<menuSize;i++){
            printf("%d %s Rs.%d\n\t%s\n",i+1,items[i],prices[i],desc[i]);
        }
        star_seperator();

    choose_menu:
        int choice;
        printf("So Which Combo you would like to order? ");
        scanf(" %d",&choice);
        if (choice>0 && choice<=menuSize){
            strcpy(item,items[choice-1]);
            price=prices[choice-1];

        } else {
            printf("Error!! Please Try Again\n");
            goto choose_menu;
        }

    choose_drink:
        int drink;
        for(int i=0;i<drinkSize;i++){
            printf("%d. %s\n",i+1,drinks[i]);
        }
        printf("Select Drink for Combo? ");
        scanf("%d",&drink);
        if (drink>0 && drink<=drinkSize){
            strcat(item," ");
            strcat(item,drinks[drink-1]);
            quantity=ask_quantity();
            add_to_bill(item,quantity,price,"Combo");
        } else {
            goto choose_drink;
        }


    want_more:
        printf("1. Yes i would like to order more\n");
        printf("2. Nah, I'm Fine.\n");
        int resp;
        printf("Would you want to order another Combos? ");
        scanf(" %d",&resp);
        switch(resp){
        case 1:
            strcpy(item,"");
            goto menu;
            break;
        case 2:
            seperator();
            printf("What would you like to order rather than Drinks?\n");
            return 0;
        default:
            goto want_more;
        }



}

void main_menu(){
    char menu[6][20] = {"1. Pizza\n","2. Pasta\n","3. Side & Dips\n","4. Drinks\n","5. Combo Offers\n"};
    int size=sizeof(menu)/sizeof(menu[0]);
    seperator();

    menu_print:
        for (int i=0;i<size;i++){
            printf("%s",menu[i]);
        }
        if(Bc!=0){
            printf("6. Generate Bill\n");
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
            case 3:
                sides_and_dips();
                goto menu_print;
            case 4:
                drinks();
                goto menu_print;
            case 5:
                combo_offers();
                goto menu_print;
            case 6:
                if (Bc==0){
                    printf("Error!! Try Again");
                    goto choose_menu;
                } else{
                    break;
                }
            default:
                printf("Error!! Try Again");
                goto choose_menu;
        }
}

void bill_seperator(){
    for(int i=0;i<80;i++){
        printf("#");
    }
    printf("\n");
}
float calculateDiscount(float originalPrice, float discountPercentage) {
    float discountAmount = (originalPrice * discountPercentage) / 100;
    float finalPrice = originalPrice - discountAmount;
    return finalPrice;
}

int gimme_the_bill_man(){
    if (Bc==0){
        return 0;
    }
    float total=0,saved=0;
    printf("\n\n");
    bill_seperator();
    printf("Bill Generated at: %s\n",getFormattedDateTime());
    bill_seperator();
    printf("%-40s %-7s %-10s %-7s %-7s\n","Name","Qty","Discount","Price","Value");
    bill_seperator();
    for(int i=0;i<Bc;i++){
//        int discount=0;
//        float price=0;
//        if (strcmp(bill[i].type,offers[random_offer].type)==0){
//            discount=offers[random_offer].discount;
//            price=calculateDiscount(bill[i].price,discount);
//        } else {
//            price=bill[i].price;
//        }
//        float itemTotal=bill[i].quantity*price;
//        saved += (bill[i].price-price)*bill[i].quantity;
//        printf("%-40s %-7d %-10d %-7.2f %% %-7.2f\n",bill[i].name,bill[i].quantity,discount,price,itemTotal);
//        total+=itemTotal;
        float price;
        int discount=0;
        if (strcmp(bill[i].type,itemName)==0){
            discount = discountOffer;
            price=calculateDiscount(bill[i].price,discount);
        } else {
            price = bill[i].price;
        }
        float itemTotal=bill[i].quantity*price;
        saved += (bill[i].price-price)*bill[i].quantity;
        printf("%-40s %-7d %-10d%% %-7.2f %-7.2f\n",bill[i].name,bill[i].quantity,discount,price,itemTotal);
        total+=itemTotal;
    }
    if (weekDay==0){
        bill_seperator();
        int ttlDiscount = calculateDiscount(total,discountOffer);
        printf("Total Discount on Bill %d%%\n",discountOffer);
        saved+=total-ttlDiscount;
        total = ttlDiscount;
    }
    bill_seperator();
    printf("Total %.2f; You Saved: %.2f\n",total,saved);
    bill_seperator();
    Bc=0;
    memset(bill, 0, sizeof(bill));
    printf("\n\n\n");
}

int greetings(){

    seperator();
    printf("Greetings from Zaika Pizzeria\n (Aroma of Indian Flavours blended with Italian Cuisine)\n\n \t\t\t\t\t\t\t\t %s\n",getFormattedDateTime());
    seperator();
    if (hasDiscount==1){
        if (weekDay==0){
            printf("%s Discount: %d%% Off on total bill.\n",days[0],discountOffer);
        } else {
            printf("%s %s offer: %d%% discount on %s.\n",days[weekDay],itemName,discountOffer,itemName);
        }
        seperator();
    }

//    printf("Special Discount %d%% off on %s.\n",offers[random_offer].discount,offers[random_offer].type);

    printf("Hello User, What would like to have today\n");
}

void main(){
//    strcpy(offers[0].type,"pizza");
//    offers[0].discount=5;
//
//    strcpy(offers[1].type,"pasta");
//    offers[1].discount=10;
//
//    strcpy(offers[2].type,"combos");
//    offers[2].discount=7;

//
//
//
//    int offerSize=sizeof(offers)/sizeof(offers[0]);
//    srand(time(0));
//
//    // Generate a random index between 0 and 2 (for an array of 3 elements)
//    random_offer = rand() % offerSize;


    weekDay = getDayOfWeek();
//    printf("%s\n",days[weekDay]);
    switch(weekDay){
    case 0:
        hasDiscount=1;
        discountOffer = 10;
        break;
    case 5:
        hasDiscount=1;
        strcpy(itemName,"Combo");
        discountOffer = 15;
        break;
    }

    hello:
        greetings();
        main_menu();
        gimme_the_bill_man();
        goto hello;
}
