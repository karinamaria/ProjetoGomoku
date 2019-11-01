#ifndef JOGO_H
#define JOGO_H

#ifdef __WIN32__
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

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
int validarCaptura(Jogo *jogo, int i, int j);
void analisarCaptura(Jogo *jogo, int i, int j);
int verificarCaptura(Jogo *jogo, int i, int j, int di, int dj);
int capturarPecas(Jogo *jogo, int i, int j, int di, int dj);
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca);
void limparTela();

#endif