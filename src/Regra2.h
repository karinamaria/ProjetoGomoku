#ifndef REGRA2_H
#define REGRA2_H

#include "Jogador.h"
#include "Tabuleiro.h"

int validarInsercao(Tabuleiro tabuleiro, int lin, int col, Peca peca);
int verificarFormacao3x3(Tabuleiro goban, int i, int j, Peca peca);
int contarSequencia(Tabuleiro goban, Casa c, int di, int dj, Peca peca);
int verificarSeSeqContinua(Tabuleiro goban, Casa casa, int di, int dj, Peca peca, int n);
int validarPrimeiraSeq(Tabuleiro goban, Casa c0, Casa *c1, Casa *c2, Casa *c3, Casa *c4, int di, int dj, Peca peca);
int analisarSegundaSeq(Tabuleiro goban, int di, int dj, Casa c1, Casa c2, Casa c3, Casa c4, Peca peca);
int verificarSegundaSeq(Tabuleiro goban, int di, int dj, Casa c, Peca peca);
int validarSegundaSeq(Tabuleiro goban, Casa c0, int di, int dj, Peca peca);
int continuarJogo();
void imprimirGanhador(Jogador *jogador1, Jogador *jogador2, Peca peca, int vitoriaPorCaptura);

#endif