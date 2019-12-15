#ifndef IA_H
#define IA_H

#include "Jogo.h"

#define CAPTURA_5    44299815392811110
#define SEQUENCIA_G  4429981539281110
#define SEQUENCIA_5  442998153928110
#define SEQUENCIA_4D 44299815392810
#define CAPTURA_X    553747692410
#define SEQUENCIA_4U 13843692310
#define SEQUENCIA_3D 461456410
#define SEQUENCIA_3U 11536410
#define SEQUENCIA_2D 288410
#define SEQUENCIA_2U 7210
#define POSICAO_X    10
#define INIMIGO_N    10

#define SEQUENCIA_S  2
#define INIMIGO_S   -1

typedef struct{
	int lin;
	int col;
	long long int prioridade;
}Jogada;

void pedirJogadaIA(Jogo *jogo, int *lin, int *col);
long long int calcularPrioridade(Jogo *jogo, int i, int j);
long long int calcularBloqueio(Tabuleiro goban, int ganhando, int peca_inimiga, int nivel, int i, int j);
long long int calcularSequencia(Tabuleiro goban, int ganhando, int peca, int nivel, int i, int j);
int calcularSeqDirSimples(Tabuleiro goban, int i, int j, int di, int dj, Peca peca, int *prioridade);
long long int calcularSeqDirNormal(Tabuleiro goban, int ganhando, int i, int j, int di, int dj, Peca peca);
long long int calcularSeqDirReal(Tabuleiro goban, int ganhando, int i, int j, int di, int dj, Peca peca);
long long int calcularCapturado(Tabuleiro goban, int ganhando, Jogador inimigo, int nivel, int i, int j);
long long int calcularCaptura(Tabuleiro goban, int ganhando, Jogador jogador, int nivel, int i, int j);
long long int calcularCapturaDir(Tabuleiro goban, int g, int p, int n, int i, int j, int di, int dj, int *c);
long long int calcularEntrega(Tabuleiro goban, int ganhando, Jogador inimigo, int nivel, int i, int j);
long long int calcularEntregaDir(Tabuleiro goban, int g, int p, int n, int i, int j, int di, int dj, int *c);
void percorrerSequencia(Tabuleiro goban, Casa casa, int di, int dj, Peca peca, int *n, int *max);
int verificarSeSeqPodeContinuar(Tabuleiro goban, Casa casa, int di, int dj, int n, int peca);
int contarSeqReal(Tabuleiro goban, int k, int i, int j, int di, int dj, int peca);
long long int prioridadeDaSequencia(int n1, int n2, int max1, int max2, int ganhando, int peca);
int validarEntrega(Tabuleiro goban, int peca, int i, int j, int di, int dj);
void selecionarMelhorJogada(Jogada *jogadas, int n, int *lin, int *col);
Jogada* insertionSort(Jogada *jogadas, int n);

#endif