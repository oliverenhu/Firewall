#include "graph.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "vertices.h"
struct Graph{
	uint32_t vertices ; // Number of vertices .
        bool undirected ; // Undirected graph
        bool visited [ VERTICES ]; // vertices visited
        uint32_t matrix [ VERTICES ][ VERTICES ]; // Adjacency matrix .
};
Graph *graph_create(uint32_t vertices, bool undirected){
	Graph *G = ( Graph *) calloc (1 , sizeof ( Graph ) ) ;
	if(vertices<=VERTICES){
	G-> vertices = vertices ;
	}
	G-> undirected = undirected ;
	return G;
}
	
void graph_delete(Graph **G){
	free (*G);
	*G = NULL;
	return;
}

uint32_t graph_vertices(Graph *G){
	return G->vertices;
}

bool graph_add_edge(Graph *G, uint32_t i, uint32_t j, uint32_t k){
	if(i<=G->vertices&&j<=G->vertices&&i!=j){

		G->matrix[i][j]=k;
		if(G->undirected==true){
			G->matrix[j][i]=k;
		}
		return true;
	}	
	return false;
}	

bool graph_has_edge(Graph *G, uint32_t i, uint32_t j){
	if(i<=G->vertices&&j<=G->vertices&&G->matrix[i][j]>0){
		return true;
	}
	return false;	
}

uint32_t graph_edge_weight(Graph *G, uint32_t i, uint32_t j){
	if(graph_has_edge(G ,i , j)&& G->matrix[i][j]!=0){
		return G->matrix[i][j];		
	}
	return 0;
}	

bool graph_visited(Graph *G, uint32_t v){
	if(G->visited[v]==true){
		return true;
	}
	return false;	
}

void graph_mark_visited(Graph *G, uint32_t v){
	if(v<VERTICES){
		G->visited[v]=true;	
	}
}

void graph_mark_unvisited(Graph *G, uint32_t v){
	if(v<VERTICES){
                G->visited[v]=false;
        }
}


void graph_print(Graph *G){
	 for (uint32_t x=0;x<VERTICES;x+=1){
		for (uint32_t y=0;y<VERTICES;y+=1){
		printf("%u  ",G->matrix[x][y]);
		}
		printf("\n");	
	}
}
