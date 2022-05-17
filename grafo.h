#ifndef GRAFO
#define GRAFO

//Estrutura base do grafo
typedef struct grafo{
	int V;
	int E;
	int **adj;
}Grafo;

int **alocaMatrizAdj(int r, int c, int val);
Grafo *criaGrafo (int V);
void insereAresta(Grafo *G, int v, int w);
void removeAresta(Grafo *G, int v, int w);
void imprimeGrafo(Grafo *G);

#endif //GRAFO