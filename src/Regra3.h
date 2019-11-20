#ifndef REGRA3_H
#define REGRA3_H

#include "Jogo.h"

int verificarFimDeJogo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarQntCapturas(Jogo *jogo, Peca *peca);
int verificarLinhas(Tabuleiro goban, Peca *peca, int ganhando);
int verificarColunas(Tabuleiro goban, Peca *peca, int ganhando);
int verificarDiagPrincipalBaixo(Tabuleiro goban, Peca *peca, int ganhando);
int verificarDiagPrincipalCima(Tabuleiro goban, Peca *peca, int ganhando);
int verificarDiagSecundariaCima(Tabuleiro goban, Peca *peca, int ganhando);
int verificarDiagSecundariaBaixo(Tabuleiro goban, Peca *peca, int ganhando);
int verificarEmpate(Jogo *jogo, Peca *peca);

#endif