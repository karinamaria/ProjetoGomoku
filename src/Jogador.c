#include "headers/Jogador.h"
#include "headers/Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
	A função inicializarJogadores pede o nome dos jogadores,
	zera suas vitórias e sorteia a peça de cada um.
	Parâmetros: Os dois jogadores
**/
void inicializarJogadores(Jogador *jogador1, Jogador *jogador2, int modo){
	jogador1->vitorias = 0;
	jogador2->vitorias = 0;
	
	if (modo == 1) {
		jogador1->nivel = 0;
		jogador2->nivel = 0;
	}
	else if (modo == 2) {
		strcpy(jogador2->nome, "Computador");
		jogador1->nivel = 0;
	}
	else {
		strcpy(jogador1->nome, "Computador1");
		strcpy(jogador2->nome, "Computador2");
	}
}

/**
	A função sortearPecas sorteia a peça(Preta ou Branca) que cada jogador vai ficar
	Parâmetros: Os dois jogadores
**/
void sortearPecas(Jogador *jogador1, Jogador *jogador2){
	jogador1->peca = sortearNumero(0, 1);

	jogador2->peca=1-jogador1->peca;
}

/**
	A função zerarCapturas zera o atributo capturas dos dois jogadores
	Parâmetros: Os dois jogadores
**/
void zerarCapturas(Jogador *jogador1, Jogador *jogador2) {
	jogador1->capturas = 0;
	jogador2->capturas = 0;
}

/**
	A função informarQntCapturas imprime na tela o placar de capturas
	Parâmetros: Os dois jogadores
**/
void informarQntCapturas(Jogador jogador1, Jogador jogador2) {
	printf("Capturas: %s %d X %d %s\n", jogador1.nome, jogador1.capturas, jogador2.capturas, jogador2.nome);
}

/**
	A função caracterPeca recebe uma peça analisa  e retorna
	a que caracter corresponde essa peça.
	Parâmetro: A peça
	Retorno: A letra que corresponde a peça 
**/
char caracterPeca(Peca peca) {
	switch (peca) {
		case P:
			return 'P';
		case B:
			return 'B';
		default:
			return '-';
	}
}