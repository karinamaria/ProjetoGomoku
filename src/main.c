#include "headers/Util.h"
#include "headers/Jogo.h"
#include "headers/Tela.h"
#include <stdio.h>
#include <string.h>

void exibirMenu();

int main(){
	inicializarSorteio();
	exibirMenu();
	return 0;
}

/**
	A função exibirMenu apresenta o menu com as opções do jogo
**/
void exibirMenu(){
	Jogo jogo;
	jogo.idioma=1;
	int opcao;

	do{
		jogo.turno = 0;
		imprimirMenuPrincipal(jogo.idioma);
		scanf("%d", &opcao);
		limparBuffer();
		if(opcao == 1){
			novoJogo(&jogo);
		}else if(opcao == 2){
			continuarJogo(&jogo);
		}else if(opcao == 3){
			configurarJogo(&jogo);
		}
	}while(opcao != 0);
}