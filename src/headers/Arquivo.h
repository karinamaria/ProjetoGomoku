#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Jogo.h"
#include "Util.h"
#include "Traducao.h"

void salvarJogo(Jogo *jogo);
void salvarInformacoesJogo(Jogo *jogo);
int gerarId(Jogo *jogo);
char* nomeArquivoJogo(int numArquivo);
int existeArquivoJogo(Jogo *jogo);
void abrirArquivoJogo(Jogo *jogo, int numArquivo);
void buscarDadosArquivo(Jogo *jogo, char *nomeArquivo, Data *data);

#endif