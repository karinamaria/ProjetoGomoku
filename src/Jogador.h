#ifndef JOGADOR_H
#define JOGADOR_H

typedef enum{
	P,B
}Peca;

typedef struct{
	char nome[16];
	int vitorias;
	int pontos;
	Peca peca;
}Jogador;

void inicializarJogador(Jogador *jogador1, Jogador *jogador2);
void sortearPecas(Jogador *jogador1, Jogador *jogador2);
char caracterPeca(Peca peca);


#endif