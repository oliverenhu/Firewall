#include <stdio.h>
#include <stdlib.h>
#include "names.h"
typedef enum { SIDE=0, RAZORBACK=10, TROTTER=10, SNOUTER=15, JOWLER=5} Position;
const Position pig[7]= { SIDE, SIDE , RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER} ;
const char* get_position(int points){
    switch (points){
        case 0: return "side";
        case 1: return "side";
        case 2: return "razorback";
        case 3: return "trotter";
        case 4: return "snouter";
        case 5: return "jowler";
        case 6: return "jowler";
    }
    return "0";
}
void check_winner(int players);
int main(void) {
        int players;
	long long seed;
        printf("How many players ? ");
        scanf("%d",&players);
        if(players>1 && players<11 ){
            printf("%d players\n", players);
        }
        else {
            fprintf ( stderr , " Invalid number of players . Using 2 instead .\n");
        }

        printf("Random seed:");
        scanf("%lld",&seed);
        if(seed <= 4294967295 && seed >=0 ){
            srandom(seed);
	    check_winner(players);
        }
        else{
            fprintf ( stderr , " Invalid random seed . Using 2021 instead .\n");
	    srandom(2021);
            check_winner(players);
        }
        return 0;

}
void check_winner(int players){
    int scores[10]={0,0,0,0,0,0,0,0,0,0};
    int win=0;
    WIN:while(win==0){
        for(int i=0;i<players;i=i+1){
            int position;
            int r;
            printf("%s rolls the pig... ",names[i]);
            do {
                if(scores[i]>=100){
                    printf("%s wins with %d\n",names[i],scores[i]);
                    win=1;
                    goto WIN;

                }
                r=random()%7;
                position=pig[r];
                scores[i]+=position;
                if(r==0||r==1){
                    printf("pig lands on %s\n",get_position(r));
                }
                else{
                    printf("pig lands on %s ",get_position(r));
                }
            }while(position!=0);

        }
    }
}
