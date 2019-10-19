#include "Jogo.h"


void iniciarJogo(Jogo jogo){

	inicializarJogador(&jogo.jogador1, &jogo.jogador2);
	jogo.goban = inicializarTabuleiro();
	imprimirTabuleiro(jogo.goban);

}