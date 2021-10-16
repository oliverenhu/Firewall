#include <stdio.h>
#include "insert.h"
#include <stdlib.h>
void insertion_sort(Stats *stats, uint32_t *A, uint32_t n){
		
	for(uint32_t i =1;i< n;i+=1){
		uint32_t j =i;
		uint32_t temp = move(stats,A[i]);
		while((j>0 )&& cmp(stats,A[j-1],temp)==1){
				
		
			A[j] =move(stats,A[j-1]);
			j -= 1;
		}

		A[j] = move(stats,temp);
		
		}
		
		printf("%lu",stats->moves);
	




//}

//	}	

	

	

}
