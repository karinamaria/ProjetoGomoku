#ifndef JOGADOR_H
#define JOGADOR_H

typedef enum{
	P,B
}Peca;

typedef struct{
	char nome[16];
	int vitorias;
	int capturas;
	Peca peca;
}Jogador;

void inicializarJogadores(Jogador *jogador1, Jogador *jogador2);
void sortearPecas(Jogador *jogador1, Jogador *jogador2);
void zerarCapturas(Jogador *jogador1, Jogador *jogador2);
void informarQntCapturas(Jogador jogador1, Jogador jogador2);
char caracterPeca(Peca peca);


#endif