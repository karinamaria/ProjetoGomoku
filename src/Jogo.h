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
void informarProximoJogador(Jogo *jogo);
void alternarJogador(Peca *proximoJogador);
int validarInsercao(Tabuleiro tabuleiro, int lin, int col, Peca peca);
int verificarFormacao3x3(Tabuleiro goban, int i, int j, Peca peca);
int contarSequencia(Tabuleiro goban, int i, int j, int di, int dj, int *pdi, int *pdj, int *fi, int *fj, Peca peca);
int continuarJogo();
int validarCaptura(Jogo *jogo, int i, int j);
void analisarCaptura(Jogo *jogo, int i, int j);
int verificarCaptura(Jogo *jogo, int i, int j, int di, int dj);
int capturarPecas(Jogo *jogo, int i, int j, int di, int dj);
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura);

#endif