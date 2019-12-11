#ifndef JOGADOR_H
#define JOGADOR_H

#include "Tabuleiro.h"

typedef enum{
	P,B
}Peca;

typedef struct{
	char nome[18];
	int vitorias;
	int capturas;
	int nivel;
	Peca peca;
}Jogador;

void inicializarJogadores(Jogador *jogador1, Jogador *jogador2, int modo);
void sortearPecas(Jogador *jogador1, Jogador *jogador2);
void zerarCapturas(Jogador *jogador1, Jogador *jogador2);
char caracterPeca(Tabuleiro goban, int i, int j, Peca peca, int proximoJogador);

#endif