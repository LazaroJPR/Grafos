#include <stdlib.h>
#include <stdio.h>

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

//Funcao que cria o grafo
Grafo *criaGrafo (int v);

//Funcao que cria um vertice
Vertice *novoVertice(int x);

//Funcao que realiza a insercao de uma aresta no grafo
void insereAresta(Grafo *G, int v, int w);

//Funcao que verifica se um grafo e conexo
int ehConexo(Grafo *G);

//Funcao que realiza o percurso em profundidade a partir de um vertice para verificar se e conexo
void percursoEmProfundidade(int raiz, Grafo *G, int visitado[]);

//Funcao que realiza a limpeza do input
void clear ();

//Funcao que le os parametros de cada cidade e cria a mesma
void criarCidade(int caso);

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

int ehConexo(Grafo *G){
    int visitado[G->V], i;
    int contador, subContador;

    for(i = 0; i < G->V; i++) visitado[i] = 0;

    percursoEmProfundidade(0, G, visitado);

    contador = subContador = 0;
    for(i = 0; i < G->V; i++)
        if(visitado[i] == 1) contador++;

    for(i = 1; i < G->V; i++)
        if(G->adj[i].prox == NULL) subContador++;

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

void clear (){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

void criarCidade(int caso){
    Grafo *cidade;
    char pPrincipal, nEstrada, pontX, pontY;
    int pontosPrincipais, estradasConstruidas, i, pontoX, pontoY, conectividade;

    scanf("%c", &pPrincipal);
    pontosPrincipais = pPrincipal - '0';
    clear();
    scanf("%c", &nEstrada);
    estradasConstruidas = nEstrada - '0';
    clear();

    cidade = criaGrafo(pontosPrincipais);

    for(i = 0; i < estradasConstruidas; i++){
        scanf("%c %c", &pontX, &pontY);
        clear();
        pontoX = pontX - '0'-1;
        pontoY = pontY - '0'-1;

        insereAresta(cidade, pontoX, pontoY);
    }

    conectividade = ehConexo(cidade);
    if(conectividade == 0)printf("Caso #%d: a promessa foi cumprida\n", caso+1);
    else printf("Caso #%d: ainda falta(m) %d estrada(s)\n", caso+1, conectividade);
    caso++;
}

void main(){
    int entrada, i;    //Entrada Numero de casos testes T(T<=100)
    char resp[4];

	fgets(resp, 4, stdin);
    entrada = strtol(resp, NULL, 10);

    for(i = 0; i < entrada; i++) criarCidade(i);
}
