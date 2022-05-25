#include "grafo.c"

void clear (void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

void criarCidade(){
    Grafo *cidade;
    char pPrincipal, nEstrada, pontX, pontY;
    int pontosPrincipais, estradasConstruidas, i, pontoX, pontoY;

    scanf("%c", &pPrincipal);
    pontosPrincipais = pPrincipal - '0'-1;
    scanf("%c", &nEstrada);
    estradasConstruidas = nEstrada - '0'-1;
    clear();

    cidade = criaGrafo(pontosPrincipais);

    for(i = 0; i < estradasConstruidas; i++){
        scanf("%d %d", &pontX, &pontY);
        pontoX = pontX - '0';
        pontoY = pontY - '0';

        insereAresta(cidade, pontoX, pontoY);
    }
    //Verificar Promessa
}


void main(){
    int entrada, i;    //Entrada Numero de casos testes T(T<=100)
    char resp[4];

	fgets(resp, 4, stdin);
    entrada = strtol(resp, NULL, 10);

    for(i = 0; i < entrada; i++) criarCidade();
}
