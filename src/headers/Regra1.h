#ifndef REGRA1_H
#define REGRA1_H

#include "Jogo.h"

void verificarCaptura(Jogo *jogo, int i, int j);
void capturarPeca(Jogo *jogo, int i, int j, int di, int dj);
int validarCaptura(Tabuleiro goban, int peca, int i, int j, int di, int dj);

#endif