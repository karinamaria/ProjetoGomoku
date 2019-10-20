#include "Jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void inicializarJogador(Jogador *jogador1, Jogador *jogador2){
	printf("Nome do jogador 1: ");
	scanf("%s",jogador1->nome);
	jogador1->vitorias=0;
	jogador1->pontos=0;

	printf("Nome do jogador 2: ");
	scanf("%s",jogador2->nome);
	jogador2->vitorias=0;
	jogador2->pontos=0;
	
	sortearPecas(jogador1,jogador2);

}
/**
	A função sortearPecas sorteia a peça(Preta ou Branca) que cada jogador vai ficar
	Parâmetros: Os dois jogadores
**/
void sortearPecas(Jogador *jogador1, Jogador *jogador2){
	time_t t;

	srand((unsigned) time(&t));

	jogador1->peca = rand()%2;

	jogador2->peca=1-jogador1->peca;

}

