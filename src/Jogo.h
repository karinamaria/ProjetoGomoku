#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h"
#include "Tabuleiro.h"


typedef struct{
	Jogador jogador1;
	Jogador jogador2;
	Tabuleiro goban;
	Peca proximoJogador;
}Jogo;

void iniciarJogo(Jogo jogo);
void loopJogo(Jogo *jogo);
void analisarProximoJogador(Jogo *jogo);
int validarInsercao(Tabuleiro tabuleiro, int lin, int col);
int continuarJogo();
char* converterParaMinusculo(char *resposta);

#endif