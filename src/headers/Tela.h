#ifndef TELA_H
#define TELA_H

#include "Jogo.h"

void imprimirMenuPrincipal(int idioma);
void imprimirMenuNovoJogo(int idioma);
void imprimirMenuNomeJog1(int idioma);
void imprimirMenuNomeJog2(int idioma);
void imprimirMenuSeuNome(int idioma);
void imprimirMenuDificuldade(int idioma);
void imprimirMenuNivelCOM1(int idioma);
void imprimirMenuNivelCOM2(int idioma);
void imprimirMenuDimensao(int idioma);
void imprimirMenuContinuarJogo(Jogo *jogo, int qntJogosSalvos);
void imprimirMenuIdioma(Jogo *jogo);
void imprimirArquivo(Jogo *jogo, int numArquivo);
char* textoDificuldade(int nivelj1, int nivelj2);
char* textoModoDeJogo(int modo);
void imprimirTitulo(char *nome);
void imprimirOpcao(char *nome, int valor, int idioma);
void imprimirComando(int idioma);
void imprimirRetangulo();
void imprimirFinal();
void imprimirLinha();
void imprimirEspaco();

#endif