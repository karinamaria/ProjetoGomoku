#include "headers/Arquivo.h"
#include "headers/Util.h"
#include <string.h>
#include <stdio.h>
/**
	A função salvarJogo pergunta se os usuário desejam salvar o jogo 
	Parâmetro: O jogo
**/
void salvarJogo(Jogo *jogo){
	char resposta[3];
	do{
		printf("Deseja salvar esse jogo (sim | nao)? ");
		scanf("%s",resposta);
		strcpy(resposta,converterParaMinusculo(resposta));
	}while(strcmp("sim", resposta) != 0 && strcmp("nao", resposta) != 0);
	if(strcmp("sim", resposta) == 0){
		existePasta();
		salvarInformacoesJogo(jogo);
	}
	
}

/**
	A função salvarInformacoesJogo grava os detalhes do jogo em um arquivo 'jogo_x.txt'
	Parâmetro: O jogo
**/
void salvarInformacoesJogo(Jogo *jogo){
	char nomeArquivo[50] = "jogos/jogo_";
	
	int id_jogo;

	gerarId(jogo, &id_jogo);
	
	nomeArquivoJogo(nomeArquivo, id_jogo);

	FILE *arquivo;
	
	arquivo = fopen(nomeArquivo, "w");

	fprintf(arquivo, "%s\n", jogo->jogador1.nome);
	fprintf(arquivo, "%s\n", jogo->jogador2.nome);
	fprintf(arquivo, "%d %d %d\n", jogo->jogador1.vitorias, jogo->jogador2.vitorias, jogo->goban.dimensao);
	
	fclose(arquivo);
}

/**
	A função gerarId busca ou gera um id
	Parâmetros: O jogo e id_jogo
**/
void gerarId(Jogo *jogo, int *id_jogo){
	if(jogo->id > 0){
		*id_jogo=jogo->id;
	}else{
		*id_jogo=contarArquivoOuPasta("./jogos/jogo_*.txt")+1;
	}
}

/**
	A função nomeArquivoJogo nomeia um arquivo de informações do jogo
	Parâmetro: O nome do arquivo e o número do arquivo;
**/
void nomeArquivoJogo(char *nomeArquivo, int numArquivo){
	char caracter[10];
  	sprintf(caracter, "%i", numArquivo);

  	strcat(nomeArquivo, strcat(caracter, ".txt"));
}

/**
	A função existeArquivoJogo verifica se existe jogos salvos e os exibe
	Parâmetro: o jogo
	Retorno: 0(Não existe jogo salvo) e 1(existe jogo salvo)
**/
int existeArquivoJogo(Jogo *jogo){
	int qntJogosSalvos=contarArquivoOuPasta("./jogos/jogo_*.txt");

	int numArquivo;

	if(qntJogosSalvos != 0){
		limparTela();
		printf("----ESCOLHA UM JOGO----\n");
		printf("0. Voltar\n");
		do{
			for(int i=0; i<qntJogosSalvos; i++){
				printf("%d. Jogo_%d\n", i+1, i+1);
			}
			printf("------------------------\n");
			scanf(" %d",&numArquivo);
		}while(numArquivo < 0 || numArquivo > qntJogosSalvos);
		if(numArquivo == 0){
			return 0;
		}
		abrirArquivoJogo(jogo, numArquivo);
		return 1;
	}else{
		printf("Nenhum jogo salvo.\n");
		limparBuffer();
		getchar();
		return 0;
	}
}

/**
	A função abrirArquivoJogo configura um jogo com os dados de um arquivo
	Parâmetros: o jogo e o número do arquivo
**/
void abrirArquivoJogo(Jogo *jogo, int numArquivo){
	char nomeArquivo[50] = "jogos/jogo_";
	nomeArquivoJogo(nomeArquivo, numArquivo);
	jogo->id=numArquivo;

	FILE *arquivo;

	arquivo = fopen(nomeArquivo, "r");

	fgets(jogo->jogador1.nome, 16, arquivo);
	fgets(jogo->jogador2.nome, 16, arquivo);
	fscanf(arquivo, "%d %d %d\n", &jogo->jogador1.vitorias, &jogo->jogador2.vitorias, &jogo->goban.dimensao);

	fclose(arquivo);

	jogo->jogador1.nome[strlen(jogo->jogador1.nome)-1]='\0';
	jogo->jogador2.nome[strlen(jogo->jogador2.nome)-1]='\0';
}