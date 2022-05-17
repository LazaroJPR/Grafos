#ifndef GRAFO
#define GRAFO

//Estrutura base do grafo representado por uma matriz de adjacencias
typedef struct grafo{
	int V;
	int E;
	int **adj;
}Grafo;

//Funcao que aloca dinamicamente uma matriz de adjacencias
int **alocaMatrizAdj(int r, int c, int val);

//Funcao que cria o grafo
Grafo *criaGrafo (int V);

//Funcao que realiza a insercao de uma aresta no grafo
void insereAresta(Grafo *G, int v, int w);

//Funcao que realiza a remocao de uma aresta no grafo
void removeAresta(Grafo *G, int v, int w);

//Funcao que realiza a impressao do grafo
void imprimeGrafo(Grafo *G);

//Funcao que calcula o grau de um vertice
int grau(Grafo *G, int v);

#endif //GRAFO