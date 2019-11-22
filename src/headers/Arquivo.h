#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Util.h"
#include "Tela.h"
#include "Jogo.h"

void salvarJogo(Jogo *jogo);
void salvarInformacoesJogo(Jogo *jogo);
int gerarId(Jogo *jogo);
char* nomeArquivoJogo(int numArquivo);
int existeArquivoJogo(Jogo *jogo);
void buscarDadosArquivo(Jogo *jogo, char *nomeArquivo, Data *data);
void abrirArquivoJogo(Jogo *jogo, int numArquivo);

#endif