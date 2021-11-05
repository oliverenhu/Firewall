#include "pq.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
struct PriorityQueue {
	uint32_t capacity;
	uint32_t top;
	Node **items;
};
PriorityQueue *pq_create(uint32_t capacity){
	PriorityQueue *q=(PriorityQueue *)malloc(sizeof(PriorityQueue));
	if(q){
		q->top=0;
		q->capacity = capacity;
		q->items = (Node **) calloc(capacity, sizeof(Node));
        if (!q->items) {
            free(q);
            q = NULL;
        }
	
	}
	return q;
}
void pq_delete(PriorityQueue **q){
	if(*q && (*q)->items){
		free((*q)->items);
		free(*q);
		*q=NULL;
	}
	return;	
}

bool pq_empty(PriorityQueue *q){
	return q->top==0;
}
bool pq_full(PriorityQueue *q){
	return (pq_size(q) == q->capacity);	
}

uint32_t pq_size(PriorityQueue *q){
	return q->top;
}

int min_child(Node **items,int first, int last){
	int left = 2 * first;
	int right = left +1;
	if( right<= last && items[right -1]->frequency>items[left-1]->frequency){
		return right;
	}
	return left;

}
void node_swap(Node *x,Node *y){
        Node swap= *x;
        *x = *y;
        *y = swap;
}
void fix_queue(Node **items,int first, int last){
	bool found = false;
	int parent= first;
	int great = min_child(items,parent,last);
	while(parent<=floor(last/2) && !found){
		if(items[parent -1]->frequency<items[great-1]->frequency){
			node_swap(items[parent-1],items[great-1]);
			parent =great;
			great=min_child(items,parent,last);
		}
		else{
			found=true;
		}
	}
}
void queue_sort(Node **items,uint32_t n){
	int first=1;
	int last=n;
	for (int father = floor(last/2);father>first-1;father-=1){
                fix_queue(items,father,last);
        }
	for (int leaf = last;leaf>first;leaf-=1){
		node_swap(items[first-1],items[leaf-1]);
		fix_queue(items,first,leaf-1);
	}	
}
bool enqueue(PriorityQueue *q, Node *n){
	if (!pq_full(q)) {
        	q->items[q->top]=n ;
        	q->top += 1;
		queue_sort(q->items,pq_size(q));
        	return true;
    	}
    	return false;

}
bool dequeue(PriorityQueue *q, Node **n){
	if (!pq_empty(q)) {
        	q->top -= 1;
        	*n = q->items[0];
       	 	for(uint32_t i=0;i<q->top;i+=1){
			q->items[i]=q->items[i+1];
		}
        return true;
    }
    return false;
    }

void pq_print(PriorityQueue *q){
	for(uint32_t i=0;i<pq_size(q);i+=1){
	node_print(q->items[i]);	
	}
}

