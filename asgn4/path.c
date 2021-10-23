#include "path.h"
#include "stack.h"
#include "graph.h"
#include <stdlib.h>
#include "vertices.h"
struct Path {
Stack * vertices ; // The vertices comprising the path .
uint32_t length ; // The total length of the path .
};

Path *path_create(void){
	Path *p=(Path *)malloc(sizeof(Path));
	if(p){	
		p->vertices=stack_create(VERTICES);
		p->length=0;
		
	}
	return p;
}
void path_delete(Path **p){
	if(*p && (*p)->vertices){
		stack_delete(&(*p)->vertices);
		free(*p);
		*p=NULL;
	}
	return;	
}
bool path_push_vertex(Path *p, uint32_t v, Graph *G){
	if(!stack_full(p->vertices)){
	if(stack_empty(p->vertices)){
		p->length+=graph_edge_weight(G,0,v);
	}
	uint32_t *before=NULL;
	if(stack_peek(p->vertices,before))
	p->length+=graph_edge_weight(G,*before,v);
        stack_push(p->vertices,v);

	return true;
	}
	return false;
}
bool path_pop_vertex(Path *p, uint32_t *v, Graph *G){
	if(!stack_empty(p->vertices)){
        stack_pop(p->vertices,v);
	uint32_t *before=NULL;
        if(stack_peek(p->vertices,before))
        p->length-=graph_edge_weight(G,*before,*v);


	return true;
	}	

	return false;
	}

uint32_t path_vertices(Path *p){
	return stack_size(p->vertices);
}
uint32_t path_length(Path *p){
	return (p->length);
}
void path_copy(Path *dst, Path *src){
	(stack_copy(dst->vertices,src->vertices));
}
void path_print(Path *p, FILE *outfile, char *cities[]){
	stack_print(p->vertices,outfile,cities);
}
