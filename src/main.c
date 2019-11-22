#include "headers/Jogo.h"
#include "headers/Util.h"
#include "headers/Tela.h"
#include <stdio.h>

void exibirMenu();

int main(){
	exibirMenu();
	return 0;
}

/**
	A função exibirMenu apresenta o menu com as opções do jogo
**/
void exibirMenu(){
	Jogo jogo;
	int opcao;
	do{
		imprimirMenuPrincipal();
		scanf("%d", &opcao);
		if(opcao == 1){
			novoJogo(jogo);
		}else if(opcao == 2){
			continuarJogo(jogo);
		}
	}while(opcao != 0);
}