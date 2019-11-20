#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Jogo.h"

void salvarJogo(Jogo *jogo);
void salvarInformacoesJogo(Jogo *jogo);
void ehNovoJogo(Jogo *jogo, int *id_jogo);
void nomeArquivoJogo(char *nomeArquivo, int numArquivo);
int contarArquivos();
int existeArquivoJogo(Jogo *jogo);
void abrirArquivoJogo(Jogo *jogo, int numArquivo);

#endif