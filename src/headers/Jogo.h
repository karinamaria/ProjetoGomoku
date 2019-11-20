#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h"
#include "Tabuleiro.h"

typedef struct{
	int id;
	Jogador jogador1;
	Jogador jogador2;
	Tabuleiro goban;
	Peca proximoJogador;
	int ganhando;
}Jogo;

void novoJogo(Jogo jogo);
void continuarJogo(Jogo jogo);
void jogar(Jogo *jogo);
void inicializarJogo(Jogo *jogo);
void loopJogo(Jogo *jogo);
void informarProximoJogador(Jogo *jogo);
void novaJogada(Jogo *jogo, int *lin, int *col);
void alternarJogador(Peca *proximoJogador);
int validarInsercao(Tabuleiro tabuleiro, int lin, int col, Peca peca);
int verificarFormacao3x3(Tabuleiro goban, int i, int j, Peca peca);
int formaSequenciaDe5(Tabuleiro goban, Casa c, Peca peca);
int contarSequencia(Tabuleiro goban, Casa c, int di, int dj, Peca peca);
int verificarSeSeqContinua(Tabuleiro goban, Casa casa, int di, int dj, Peca peca, int n);
int validarPrimeiraSeq(Tabuleiro goban, Casa c0, Casa *c1, Casa *c2, Casa *c3, Casa *c4, int di, int dj, Peca peca);
int analisarSegundaSeq(Tabuleiro goban, int di, int dj, Casa c1, Casa c2, Casa c3, Casa c4, Peca peca);
int verificarSegundaSeq(Tabuleiro goban, int di, int dj, Casa c, Peca peca);
int validarSegundaSeq(Tabuleiro goban, Casa c0, int di, int dj, Peca peca);
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura);
int continuarJogando();

#endif