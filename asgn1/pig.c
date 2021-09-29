#include <stdio.h>
#include <stdlib.h>
#include <names.h>
int main(void) {
        int players,seed;
        int scores[10]= {0,0,0,0,0,0,0,0,0,0};
        typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER} Position;
        const Position pig[7]= { SIDE, SIDE , RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER} ;
        printf("How many players ? ");
        scanf("%d",&players);
        if(players>1 && players<11 ){
            printf("%d players\n", players);
        }
        else {
            fprintf ( stderr , " Invalid number of players . Using 2 instead .\n");

        }
        printf("Random seed:");
        scanf("%d",&seed);
        if(seed != 2021 ){
            fprintf ( stderr , " Invalid random seed . Using 2021 instead .\n");
        }
        
        return 0;
