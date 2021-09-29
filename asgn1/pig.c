#include <stdio.h>
#include <stdlib.h>

int main(void) {
        int players;
        int scores[10]= {0,0,0,0,0,0,0,0,0,0};
        typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER} Position;
        const Position pig[7]= { SIDE, SIDE , RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER} ;
        printf("How many players will play: ");
        scanf("%d",&players);
        if(players>1 && players<11 ){
            printf("%d players\n", players);
        }
        else {
            fprintf ( stderr , " Invalid number of players . Using 2 instead .\n");

        }
        return 0;
        }
