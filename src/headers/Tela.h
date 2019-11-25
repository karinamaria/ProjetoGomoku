#ifndef TELA_H
#define TELA_H

#include "Jogo.h"

void imprimirMenuPrincipal();
void imprimirMenuContinuarJogo(Jogo *jogo, int qntJogosSalvos);
void imprimirArquivo(Jogo *jogo, int numArquivo);
void imprimirTitulo(char *nome);
void imprimirOpcao(char *nome, int valor);
void imprimirComando();
void imprimirFinal();
void imprimirLinha();
void imprimirEspaco();

#endif