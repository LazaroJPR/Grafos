#include "grafo.c"

void clear (void){
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
