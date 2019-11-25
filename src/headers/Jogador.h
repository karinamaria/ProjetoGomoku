#ifndef JOGADOR_H
#define JOGADOR_H

typedef enum{
	P,B
}Peca;

typedef struct{
	char nome[18];
	int vitorias;
	int capturas;
	int nivel;
	Peca peca;
}Jogador;

void inicializarJogadores(Jogador *jogador1, Jogador *jogador2, int modo);
void sortearPecas(Jogador *jogador1, Jogador *jogador2);
void zerarCapturas(Jogador *jogador1, Jogador *jogador2);
void informarQntCapturas(Jogador jogador1, Jogador jogador2, int idioma);
char caracterPeca(Peca peca);

#endif