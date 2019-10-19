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

#endif
