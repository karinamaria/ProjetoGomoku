#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "Jogo.h"

int verificarFimDeJogo(Jogo *jogo, Peca *peca);
int verificarLinhas(Jogo *jogo, Peca *peca);
int verificarColunas(Jogo *jogo, Peca *peca);
int verificarDiagPrincipalBaixo(Jogo *jogo, Peca *peca);
int verificarDiagPrincipalCima(Jogo *jogo, Peca *peca);
int verificarDiagSecundariaCima(Jogo *jogo, Peca *peca);
int verificarDiagSecundariaBaixo(Jogo *jogo, Peca *peca);
int verificarEmpate(Jogo *jogo, Peca *peca);

#endif