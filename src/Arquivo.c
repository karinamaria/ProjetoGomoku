#include "headers/Arquivo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
	A função salvarJogo pergunta se os usuários desejam salvar o jogo 
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
	int id_jogo = gerarId(jogo);
	char *nomeArquivo = nomeArquivoJogo(id_jogo);
	Data data = dataAtual();

	FILE *arquivo;
	
	arquivo = fopen(nomeArquivo, "w");

	fprintf(arquivo, "%s\n", jogo->jogador1.nome);
	fprintf(arquivo, "%s\n", jogo->jogador2.nome);
	fprintf(arquivo, "%d %d\n", jogo->jogador1.vitorias, jogo->jogador2.vitorias);
	fprintf(arquivo, "%d\n", jogo->goban.dimensao);
	fprintf(arquivo, "%d %d %d\n", data.hora, data.min, data.seg);
	fprintf(arquivo, "%d %d %d\n", data.dia, data.mes, data.ano);

	fclose(arquivo);
}

/**
	A função gerarId busca ou gera um id
	Parâmetro: O jogo
	Retorno: O id
**/
int gerarId(Jogo *jogo){
	if(jogo->id > 0){
		return jogo->id;
	}else{
		return contarArquivoOuPasta("./jogos/jogo_*.txt")+1;
	}
}

/**
	A função nomeArquivoJogo nomeia um arquivo de informações do jogo
	Parâmetro: O número do arquivo
	Retorno: O nome do arquivo
**/
char* nomeArquivoJogo(int numArquivo){
	char *nome = (char *) malloc(50 * sizeof(char));
	char caracter[10];
	nome[0] = '\0';
  	sprintf(caracter, "%i", numArquivo);

  	strcat(nome, "jogos/jogo_");
  	strcat(nome, caracter);
  	strcat(nome, ".txt");

  	return nome;
}

/**
	A função existeArquivoJogo verifica se existe jogos salvos e os exibe
	Parâmetro: o jogo
	Retorno: 0(Não existe jogo salvo) e 1(existe jogo salvo)
**/
int existeArquivoJogo(Jogo *jogo){
	int qntJogosSalvos=contarArquivoOuPasta("./jogos/jogo_*.txt");
	int numArquivo;

	do{
		imprimirMenuContinuarJogo(jogo, qntJogosSalvos);
		scanf(" %d",&numArquivo);
	}while(numArquivo < 0 || numArquivo > qntJogosSalvos);
	
	if(numArquivo == 0){
		return 0;
	}

	abrirArquivoJogo(jogo, numArquivo);
	return qntJogosSalvos;
}

/**
	A função buscarDadosArquivo armazena os dados do arquivo
	na estrutura jogo.
	Parâmetros: O jogo, o nome do arquivo e a data
**/
void buscarDadosArquivo(Jogo *jogo, char *nomeArquivo, Data *data) {
	FILE *arquivo = fopen(nomeArquivo, "r");

	fgets(jogo->jogador1.nome, 18, arquivo);
	fgets(jogo->jogador2.nome, 18, arquivo);
	fscanf(arquivo, "%d %d\n", &jogo->jogador1.vitorias, &jogo->jogador2.vitorias);
	fscanf(arquivo, "%d\n", &jogo->goban.dimensao);
	fscanf(arquivo, "%d %d %d\n", &data->hora, &data->min, &data->seg);
	fscanf(arquivo, "%d %d %d\n", &data->dia, &data->mes, &data->ano);

	jogo->jogador1.nome[strlen(jogo->jogador1.nome)-1]='\0';
	jogo->jogador2.nome[strlen(jogo->jogador2.nome)-1]='\0';

	fclose(arquivo);
}

/**
	A função abrirArquivoJogo configura um jogo com os dados de um arquivo
	Parâmetros: o jogo e o número do arquivo
**/
void abrirArquivoJogo(Jogo *jogo, int numArquivo){
	char *nomeArquivo = nomeArquivoJogo(numArquivo);
	Data data;
	jogo->id=numArquivo;

	buscarDadosArquivo(jogo, nomeArquivo, &data);
}