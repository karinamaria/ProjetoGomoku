#ifndef IA_H
#define IA_H

#include "Jogo.h"

typedef struct{
	int lin;
	int col;
	int prioridade;
}Jogada;

void pedirJogadaIA(Jogo *jogo, int *lin, int *col);
int calcularPrioridade(Jogo *jogo, int i, int j);
int calcularCaptura(Jogo *jogo, Jogador jogador, int i, int j);
int calcularCapDirecao(Jogo *jogo, Jogador jogador, int i, int j, int di, int dj);
int calcularCapturado(Jogo *jogo, Jogador jogador, int i, int j);
int calcularCapturadoDir(Jogo *jogo, Jogador jogador, Jogador inimigo, int i, int j, int di, int dj);
int calcularSequencia(Jogo *jogo, Jogador jogador, int i, int j);
int calcularBloqueio(Jogo *jogo, Jogador jogador, int i, int j);
int calcularSeqDirecao(Tabuleiro goban, int i, int j, int di, int dj, Peca peca);
int verificarSeqMax(Tabuleiro goban, Casa casa, int di, int dj, int n, Peca peca);
void selecionarMelhorJogada(Jogada *jogadas, int n, int *lin, int *col);
Jogada* insertionSort(Jogada *jogadas, int n);

#endif