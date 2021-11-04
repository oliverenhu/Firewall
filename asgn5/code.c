#include "code.h"
#include <inttypes.h>

Code code_init(void){
Code c;
c.top=0;
for (uint32_t i = 0;i<MAX_CODE_SIZE;i+=1){
	c.bits[i]=0;
}
return c;
}

uint32_t code_size(Code *c){
	return c->top;
}
bool code_empty(Code *c){
	return c->top==0;
}
bool code_full(Code *c){
	return c->top==MAX_CODE_SIZE*8;
}
bool code_set_bit(Code *c, uint32_t i){
	if(c){
		c->bits[i/8] |= (0x1 << i % 8);
		return true;
	}
	return false;
}
bool code_clr_bit(Code *c, uint32_t i){
	if(c){
                c->bits[i/8] &= ~(0x1 << i % 8);
                return true;
        }
        return false;
}
bool code_get_bit(Code *c, uint32_t i){
	return(c->bits[i/8] >> i % 8) & 0x1;
}
bool code_push_bit(Code *c, uint8_t bit){
	if(!code_full(c)){
		if(bit==1){
			code_set_bit(c,c->top);
			c->top+=1;
		}	
		if(bit==0){
			code_clr_bit(c,c->top);
                        c->top+=1;
               	return true;
		}
	}	
	return false;


	
}
bool code_pop_bit(Code *c, uint8_t *bit){
	if(!code_empty(c)){
		c->top-=1;
		*bit=code_get_bit(c,c->top);
		code_clr_bit(c,c->top);
                return true;
        }
        return false;
	
}

void code_print(Code *c){
	for (uint32_t i = 0;i<MAX_CODE_SIZE;i+=1){
        	for 
		printf(c.bits[i]=0;
}

}
