#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "grafo.h"
#include "fila.c"

Grafo *criaGrafo (int v){
	Grafo *G = (Grafo*)malloc(sizeof(Grafo));
	G->V = v;
	G->E = 0;
	G->adj = (Vertice*)calloc(v, sizeof(Vertice));
	return G;
}

Vertice *novoVertice(int x){
    Vertice *novo = (Vertice*)malloc(sizeof(Vertice));
    if(!novo) printf("ERRO\n");
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
}

void imprimeGrafo(Grafo *G){
    int v;
    Vertice *w;
    for(v = 0; v < G->V; v++){
        printf("%2d:", v+1);
        w = G->adj[v].prox;

        while(w != NULL){
            printf(" %2d", w->no+1);
            w = w->prox;
        }
        printf("\n");
    }
}

int ehConexo(Grafo *G){
    int visitado[G->V], i, j;
    int contador, contadorLoop, subContador;

    for(i = 0; i < G->V; i++) visitado[i] = 0;

    percursoEmProfundidade(0, G, visitado);

    contador = subContador = 0;
    for(i = 0; i < G->V; i++){
        if(visitado[i] == 1) contador++;
        visitado[i] = 0;
    }

    for(i = 1; i < G->V; i++){
        percursoEmProfundidade(i, G, visitado);
        contadorLoop = 0;
        for(j = 0; j < G->V; j++){
            if(visitado[j] == 1) contadorLoop++;
            visitado[j] = 0;
        }
        if(contadorLoop == 1) subContador++;
    }
    if(G->V == contador) return 0;
    else if(G->V == contador + subContador) return subContador;
    else return G->V - contador -1;

}

void percursoEmProfundidade(int raiz, Grafo *G, int visitado[]){
    int i, proximo;
    Vertice *vert;

    visitado[raiz] = 1;
    vert = G->adj[raiz].prox;

    while(vert != NULL){
        proximo = G->adj[raiz].prox->no;
        if(visitado[proximo] == 0)
            percursoEmProfundidade(proximo, G, visitado);
        vert = vert->prox;
    }
}
