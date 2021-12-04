#include "bv.h"
#include <stdlib.h>
#include <stdio.h>

struct BitVector {
uint32_t length ;
uint8_t *vector ;
};

BitVector *bv_create(uint32_t length){
	BitVector *bv=(BitVector *) malloc(sizeof(BitVector));
	if(bv){
		bv->length=length;
		bv->vector=(uint8_t *) calloc(length,sizeof(uint8_t));
		return bv;
	}
	return NULL;
}

void bv_delete(BitVector **bv){
	if(*bv &&(*bv)->vector){
		free((*bv)->vector);
		free(*bv);
		*bv =NULL;
	}	
	return;
	}	
uint32_t bv_length(BitVector *bv){
	return (bv->length);
}
bool bv_set_bit(BitVector *bv, uint32_t i){
	if(i<=bv->length){
		bv->vector[i/8] |= (0x1 << i % 8);
        	return true;
        }
        return false; 	
}
bool bv_clr_bit(BitVector *bv, uint32_t i){
	if(i<=bv->length){
                bv->vector[i/8] &= ~(0x1 << i % 8);
                return true;
        }
        return false;

}



bool bv_get_bit(BitVector *bv, uint32_t i){
	if(i<=bv->length){
	return (bv->vector[i / 8] >> i % 8) & 0x1;
	}
	return false;
}
void bv_print(BitVector *bv){
	for (uint32_t i = 0; i < bv->length*8; i += 1) {

        printf("%d", bv_get_bit(bv, i));
    }

}
