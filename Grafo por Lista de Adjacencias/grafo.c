#include "grafo.h"

Grafo *criaGrafo (int v){
	Grafo *G = (Grafo*)malloc(sizeof(Grafo));
	G->V = v;
	G->E = 0;
	G->ajd = (Vertice*)calloc(V, sizeof(Vertice));
	return G;
}

Vertice *novoVertice(int x){
    Vertice *novo = (Vertice*)malloc(sizeof(Vertice));
    if(!novo) printf("ERRO\n"); exit(1);
    novo->no = x;
    novo->prox = NULL;
    return novo;
}

void insereAresta(Grafo *G, int v, int w){
    if(v != w){
        Vertice *p = G->adj[v].prox;
        while(p != NULL){
            if(p->no == w) break;
            p = p->prox;
        }
        if(p == NULL){
            Vertice *novo = novoVertice(w);
            novo->prox = G->adj[v].prox;
            G->adj[v].prox = novo;
            G->E++;
        }
        
        p = G->adj[w].prox;
        while(p != NULL){
            if(p->no == v) break;
            p = p->prox;
        }
        if(p == NULL){
            Vertice *novo = novoVertice(v);
            novo->prox = G->adj[w].prox;
            G->adj[w].prox = novo;
            G->E++;
        }
    }
}

void removeAresta(Grafo *G, int v, int w){
    if(G->adj[v].prox != NULL){
        Vertice *aux = G->adj[v].prox;
        Vertice *preaux = &(G->adj[v]);

        while(aux != NULL){
            if(aux->no == w) break;
            preaux = aux;
            aux = aux->prox;
        }
        if(aux != NULL){
            G->E--;
            preaux->prox = aux->prox;
            free(aux);
        }
    }
    if(G->adj[w].prox != NULL){
        aux = G->adj[v].prox;
        preaux = &(G->adj[v]);

        while(aux != NULL){
            if(aux->no == w) break;
            preaux = aux;
            aux = aux->prox;
        }
        if(aux != NULL){
            G->E--;
            preaux->prox = aux->prox;
            free(aux);
        }
    }
}

void imprimeGrafo(Grafo *G){
    int v;
    Vertice *w;
    for(v = 0; v < G->V; v++){
        printf("%2d:" v);
        w = G->adj[v].prox;

        while(w != NULL){
            printf(" %2d", w->no);
            w = w->prox;
        }
        printf("\n");
    }
}