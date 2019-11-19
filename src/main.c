#include "Jogo.h"
#include "Util.h"
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
		limparTela();
		printf("--------MENU------\n");
		printf("0. Sair\n");
		printf("1. Novo Jogo\n");
		printf("2. Continuar Jogo\n");
		printf("------------------\n");
		scanf("%d", &opcao);
		if(opcao == 1){
			iniciarJogo(jogo);
		}else if(opcao == 2){
			reiniciarJogo(jogo);
		}
	}while(opcao != 0);
}