#ifndef REGRA1_H
#define REGRA1_H

#include "Jogo.h"

void verificarCaptura(Jogo *jogo, int i, int j);
int capturouPecas(Jogo *jogo, int i, int j, int di, int dj);
int validarCaptura(Jogo *jogo, int i, int j, int di, int dj);

#endif