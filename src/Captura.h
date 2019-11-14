#ifndef CAPTURA_H
#define CAPTURA_H

#include "Jogo.h"

void analisarCaptura(Jogo *jogo, int i, int j);
int verificarCaptura(Jogo *jogo, int i, int j);
int capturouPecas(Jogo *jogo, int i, int j, int di, int dj);
int validarCaptura(Jogo *jogo, int i, int j, int di, int dj);

#endif