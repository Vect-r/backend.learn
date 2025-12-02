#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Station{
    char pointName[30];
    int basePrice;
};

struct Route{
    char routeId[5];
    struct Station* stations;
    int totalStations;
};

struct Route routes[2];

void defineRoutes(){
    strcpy(routes[0].routeId,"17A");
    routes[0].totalStations = 2;
    routes[0].stations = (struct Station*)malloc(routes[0].totalStations * sizeof(struct Station));
    strcpy(routes[0].stations[0].pointName,"Kamrej BRTS");
    routes[0].stations[0].basePrice=2;
    strcpy(routes[0].stations[1].pointName,"Shyam Nagar");
    routes[0].stations[1].basePrice=2;

    strcpy(routes[1].routeId,"17A");
    routes[1].totalStations = 2;
    routes[1].stations = (struct Station*)malloc(routes[1].totalStations * sizeof(struct Station));
    strcpy(routes[1].stations[0].pointName,"Kamrej BRTS");
    routes[1].stations[0].basePrice=2;
    strcpy(routes[1].stations[1].pointName,"Shyam Nagar");
    routes[1].stations[1].basePrice=2;

}

void main(){
    defineRoutes();
    for(int i=0;i<2;i++){
        for(int c=0;c<routes[i].totalStations;c++){
            printf("Route Id: %s; Station %s\n",routes[i].routeId,routes[i].stations[c].pointName);
        }
    }

}
