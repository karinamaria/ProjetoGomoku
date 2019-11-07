#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "Jogo.h"

int verificarFimDeJogo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarQntCapturas(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarLinhas(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarColunas(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarDiagPrincipalBaixo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarDiagPrincipalCima(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarDiagSecundariaCima(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarDiagSecundariaBaixo(Jogo *jogo, Peca *peca, int *vitoriaPorCaptura);
int verificarEmpate(Jogo *jogo, Peca *peca);

#endif