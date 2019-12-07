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
void imprimirErroJogadaInvalida(int idioma);
void imprimirErroFormacao3x3(int idioma);
void imprimirGanhador(char* ganhador, int vitoriaPorCaptura, int idioma);
void imprimirEmpate(int idioma);
void imprimirPlacarCapturas(Jogador jogador1, Jogador jogador2, int idioma);
void imprimirPlacarVitorias(Jogador jogador1, Jogador jogador2, int idioma);
void imprimirContinuarJogando(int idioma);
char* textoDificuldade(int nivelj1, int nivelj2, int idioma);
char* textoModoDeJogo(int modo, int idioma);
void imprimirTitulo(char *nome);
void imprimirOpcao(char *nome, int valor, int idioma);
void imprimirComando(int idioma);
void imprimirRetangulo();
void imprimirFinal();
void imprimirLinha();
void imprimirEspaco();

#endif