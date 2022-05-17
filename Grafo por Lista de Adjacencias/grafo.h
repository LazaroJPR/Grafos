#ifndef GRAFO
#define GRAFO

//Estrutura de um vertice
typedef struct vertice{
    int no;
	struct vertice *prox;
}Vertice;

//Estrutura de um grafo representado por uma lista de adjacencias
typedef struct grafo{
    int V;
    int E;
    Vertice *adj;
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

//Funcao que imprime todos os vertices adjacentes
void imprimeAdjacente(Grafo *G, int v);

//Funcao que verifica se dois vertices sao adjacentes
void verificaAdjacencia(Grafo *G, int v, int w);

//Funcao que calcula o grau de um vertice
int grau(Grafo *G, int v);

#endif //GRAFO