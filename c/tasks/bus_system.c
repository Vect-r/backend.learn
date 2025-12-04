#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int basePrice=2,age=0,routeId,from,destination,routesLength=2;

void line_seperator(){
    for(int i=0;i<65;i++){
        printf("=");
    }
    printf("\n");
}

struct Station{
    char pointName[30];
};

struct Route{
    char id[5];
    int totalStations;
    struct Station* stations;
};

struct Ticket{
    int id;
    char from[30];
    char to[30];
    int fare;
    int isAdult;
    char direction[4];
};

struct Route routes[2];
struct Ticket *tickets;
int count = 0;


void generateTickets(){
    tickets = realloc(tickets, (count + 1) * sizeof(struct Ticket));
    int fare=0;
    int c=count;
    tickets[c].id=c+1;
    strcpy(tickets[c].from,routes[routeId].stations[from].pointName); //Copies From Station to Ticket Struct
    strcpy(tickets[c].to,routes[routeId].stations[destination].pointName); //Copies Destination Station string to Ticket Struct
    if (from>destination){
        //Up Direction
        strcpy(tickets[c].direction,"UP");
        for(int i=from;i>=destination;i--){
            fare+=basePrice;
        }

    } else{
        //Down Direction
        strcpy(tickets[c].direction,"DOWN");
        for(int i=from;i<=destination;i++){
            fare+=basePrice;
        }
    }

    if (age>=18){
        tickets[c].isAdult=1;
    } else {
        fare=fare/2;
        tickets[c].isAdult=0;
    }
    tickets[c].fare=fare;
    count++;
}

void bill_sep(){
    for(int i=0;i<65;i++){
        printf("#");
    }
    printf("\n");
}

void ticketPrinter(){
    bill_sep();
    int c = count-1;
    printf("Ticket\n");
    bill_sep();
    printf("Id: %d\n",tickets[c].id);
    printf("From: %s\n",tickets[c].from);
    printf("Destination: %s\n",tickets[c].to);
    printf("Direction: %s\n",tickets[c].direction);
    if (tickets[c].isAdult==1){
        printf("Type: ADULT\n");
    } else {
        printf("Type: CHILDREN\n");
    }
    printf("FARE: %d\n",tickets[c].fare);
    bill_sep();
    printf("HAVE A HAPPY & SAFE JOURNEY\n");
    bill_sep();

}

void defineRoutes(){
    strcpy(routes[0].id,"17A");
    routes[0].totalStations = 15;
    routes[0].stations = (struct Station*)malloc(routes[0].totalStations * sizeof(struct Station));
    strcpy(routes[0].stations[0].pointName,"Kamrej BRTS");
    strcpy(routes[0].stations[1].pointName,"Shyam Nagar");
    strcpy(routes[0].stations[2].pointName,"Pashodra Gam");
    strcpy(routes[0].stations[3].pointName,"Diamond Nagar");
    strcpy(routes[0].stations[4].pointName,"Laskana Gam");
    strcpy(routes[0].stations[5].pointName,"Raghuvir Row House");
    strcpy(routes[0].stations[6].pointName,"Swaminyarayan Mission");
    strcpy(routes[0].stations[7].pointName,"Sagwadi");
    strcpy(routes[0].stations[8].pointName,"Shyamdham Mandir");
    strcpy(routes[0].stations[8].pointName,"Purushottam nagar");
    strcpy(routes[0].stations[9].pointName,"Sarthana Nature Park");
    strcpy(routes[0].stations[10].pointName,"Simada Naka");
    strcpy(routes[0].stations[11].pointName,"Nana Varachha Police Station");
    strcpy(routes[0].stations[12].pointName,"KAPODARA FIRE STATION");
    strcpy(routes[0].stations[13].pointName,"SMC KAPODARA WARD OFFICE");
    strcpy(routes[0].stations[14].pointName,"DGVCL-URJA SADAN");


    strcpy(routes[1].id,"18P");
    routes[1].totalStations = 9;
    routes[1].stations = (struct Station*)malloc(routes[1].totalStations * sizeof(struct Station));
    strcpy(routes[1].stations[0].pointName,"PARVAT GAM");
    strcpy(routes[1].stations[1].pointName,"MAGOB PARVAT KHADI BRIDGE");
    strcpy(routes[1].stations[2].pointName,"MAGOB GAM");
    strcpy(routes[1].stations[3].pointName,"AMAZIA AMUSEMENT PARK BRTS");
    strcpy(routes[1].stations[4].pointName,"SITANAGAR");
    strcpy(routes[1].stations[5].pointName,"ANJANI BOOT BHAVANI");
    strcpy(routes[1].stations[6].pointName,"LAMBE HANUMAN ROAD");
    strcpy(routes[1].stations[7].pointName,"RACHANA CIRCLE");
    strcpy(routes[1].stations[8].pointName,"D.G.V.C.L URJA SADAN BRT");

}

void greetings(){
    line_seperator();
    printf("Welcome To Surat BRTS\n");
    line_seperator();
}

int askAge(){
    printf("Please Enter Age? ");
    scanf(" %d",&age);
}

void select_from(){
    line_seperator();
    printf("%d. %s - %s (%s)\n",routeId+1,routes[routeId].stations[0].pointName,routes[routeId].stations[routes[routeId].totalStations-1].pointName,routes[routeId].id);
    line_seperator();
    for(int i=0;i<routes[routeId].totalStations;i++){
        printf("%d. %s\n",i+1,routes[routeId].stations[i].pointName);
    }
    line_seperator();

    menu:
        printf("Select your starting point? ");
        scanf(" %d",&from);
        if (from<1 || from > routes[routeId].totalStations){
            printf("Error. Please Select Again.\n");
            goto menu;
        }
        from--;
}

void select_to(){
    line_seperator();
    printf("%d. %s - %s (%s)\n",routeId+1,routes[routeId].stations[0].pointName,routes[routeId].stations[routes[routeId].totalStations-1].pointName,routes[routeId].id);
    line_seperator();
    for(int i=0;i<routes[routeId].totalStations;i++){
        printf("%d. %s",i+1,routes[routeId].stations[i].pointName);
        if (i==from){
            printf("*");
        }
        printf("\n");
    }
    line_seperator();

    menu:
        printf("Select your destination point? ");
        scanf(" %d",&destination);
        if (destination<1 || destination > routes[routeId].totalStations){
            printf("Error. Please Select Again.\n");
            goto menu;
        }

        if ((from+1)==destination) {
            printf("Error, Destination Can't be same as Starting Point.\n");
            goto menu;
        }
        destination--;

}

void route_select(){
    askAge();
    line_seperator();
    printf("Please Select Route\n");
    line_seperator();
    defineRoutes();
    for(int i=0;i<2;i++){
        int lastStation = routes[i].totalStations;
        printf("%d. %s - %s (%s)\n",i+1,routes[i].stations[0].pointName,routes[i].stations[lastStation-1].pointName,routes[i].id);
    }

    menu:
        line_seperator();
        printf("Select Route? ");
        scanf("%d",&routeId);
        if (routeId<1 || routeId>routesLength){
            printf("Please Select valid route from the route.\n");
            goto menu;
        }
        routeId--;
}


void clrscr() {
    system("@cls||clear");
}

void pressKey(){
    char o[1];
    printf("Press Any Key to Continue...\n");
    gets(o);
}
void main(){
    menu_loop:
        defineRoutes();
        greetings();
        route_select();
        clrscr();
        select_from();
        clrscr();
        select_to();
        generateTickets();
        clrscr();
        ticketPrinter();
        pressKey();
        goto menu_loop;
}
