#ifndef TELA_H
#define TELA_H

#include "Jogo.h"

void imprimirMenuPrincipal();
void imprimirMenuNovoJogo();
void imprimirMenuNomeJog1();
void imprimirMenuNomeJog2();
void imprimirMenuSeuNome();
void imprimirMenuDificuldade();
void imprimirMenuNivelCOM1();
void imprimirMenuNivelCOM2();
void imprimirMenuDimensao();
void imprimirMenuContinuarJogo(Jogo *jogo, int qntJogosSalvos);
void imprimirArquivo(Jogo *jogo, int numArquivo);
char* textoDificuldade(int nivelj1, int nivelj2);
char* textoModoDeJogo(int modo);
void imprimirTitulo(char *nome);
void imprimirOpcao(char *nome, int valor);
void imprimirRetangulo();
void imprimirComando();
void imprimirFinal();
void imprimirLinha();
void imprimirEspaco();

#endif