#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Jogo.h"

void salvarJogo(Jogo *jogo);
void salvarInformacoesJogo(Jogo *jogo);
void gerarId(Jogo *jogo, int *id_jogo);
void nomeArquivoJogo(char *nomeArquivo, int numArquivo);
int existeArquivoJogo(Jogo *jogo);
void abrirArquivoJogo(Jogo *jogo, int numArquivo);

#endif