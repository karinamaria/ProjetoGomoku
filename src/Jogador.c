#include "Jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void inicializarJogador(Jogador *jogador1, Jogador *jogador2){
	printf("Nome do jogador 1: ");
	fgets(jogador1->nome, 16, stdin);
	jogador1->nome[strlen(jogador1->nome)-1]='\0';
	jogador1->vitorias=0;
	jogador1->capturas=0;

	printf("Nome do jogador 2: ");
	fgets(jogador2->nome, 16, stdin);
	jogador2->nome[strlen(jogador2->nome)-1]='\0';
	jogador2->vitorias=0;
	jogador2->capturas=0;
	
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
/**
	A função caracterPeca recebe uma peça e retorna um caracter
	que corresponde a essa peça.
	Parâmetro: A peça
**/
char caracterPeca(Peca peca) {
	switch (peca) {
		case P:
			return 'P';
		case B:
			return 'B';
		default:
			return '-';
	}
}

