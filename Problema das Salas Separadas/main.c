#include "grafo.c"

void clear (void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

int criarSala(int entrada){
	Grafo *sala;
    char identificador, nEntrada, amigos[198];
	int i, j, id, novaEntrada, amizade;
	sala = criaGrafo(entrada);

	for(i = 0; i < entrada; i++){ //enquanto houver aluno na lista
        	scanf("%c", &identificador);
        	clear();
            id = identificador - '0'-1;

            j = 0;
            fgets(amigos, 198, stdin); //198 e o numero da quantidade de amigos*2
            while(amigos[j] != '\n'){
                if(amigos[j] != ' '){
                    amizade = amigos[j] - '0'-1;
                    insereAresta(sala, id, amizade);
                    imprimeGrafo(sala); //RETIRAR DEPOIS
                }
                j++;
            }
	}
    /*Chama a funcao que verifica se o grafo e bipartido
    ou seja, vericara se sera possivel combinar os alunos de uma forma
    em que nao houvessem dois alunos amigos na mesma sala*/
    bipartido(sala);

    scanf("%c", &nEntrada); //Le o proximo aluno e retorna
    novaEntrada = nEntrada - '0';
	return novaEntrada;
}



void main(){
    int entrada;
    char resp[4];

	fgets(resp, 4, stdin);
    entrada = strtol(resp, NULL, 10);

	while(entrada != 0){
        entrada = criarSala(entrada);
	}
}
