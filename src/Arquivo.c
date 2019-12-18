#include "headers/Arquivo.h"
#include "headers/Tela.h"
#include "headers/RSA.h"
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
		printf("%s ", perguntas(SALVAR_JOGO, jogo->idioma));
		scanf("%s",resposta);
		strcpy(resposta,converterParaMinusculo(resposta));
	}while(verificarResposta(resposta, jogo->idioma));
	if(strcmp("sim", resposta) == 0 || strcmp("yes", resposta) == 0
		|| strcmp("si", resposta) == 0){
		existePasta();
		salvarInformacoesJogo(jogo);
	}
}

/**
	A função salvarInformacoesJogo criptografa e grava
	os detalhes do jogo em um arquivo 'jogo_x.txt'
	Parâmetro: O jogo
**/
void salvarInformacoesJogo(Jogo *jogo){
	int id_jogo = gerarId(jogo);
	char *nomeArquivo = nomeArquivoJogo(id_jogo);
	char texto[500];
	Data data = dataAtual();
	FILE *arquivo = fopen(nomeArquivo, "w");

	sprintf(texto, "%s\n %s\n %d %d %d %d %d %d %d %d %d %d %d %d",
		    jogo->jogador1.nome,     jogo->jogador2.nome,
		    jogo->jogador1.nivel,    jogo->jogador2.nivel,
		    jogo->jogador1.vitorias, jogo->jogador2.vitorias,
		    jogo->goban.dimensao,    jogo->modo_de_jogo,
		    data.hora, data.min, data.seg,
		    data.dia,  data.mes, data.ano);

	fprintf(arquivo, "%s\n", encriptar(texto));
	
	free(nomeArquivo);
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
  	strcat(nome, strcat(caracter, ".txt"));

  	return nome;
}

/**
	A função existeArquivoJogo lista todos os jogos salvos
	Parâmetro: o jogo
	Retorno: 0(volta para o menu principal) e 1(carregar jogo)
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
	A função abrirArquivoJogo configura um jogo com os dados de um arquivo
	Parâmetros: o jogo e o número do arquivo
**/
void abrirArquivoJogo(Jogo *jogo, int numArquivo){
	char *nomeArquivo = nomeArquivoJogo(numArquivo);
	Data data;
	jogo->id=numArquivo;

	buscarDadosArquivo(jogo, nomeArquivo, &data);
	free(nomeArquivo);
}

/**
	A função buscarDadosArquivo descriptografa e armazena
	os dados do arquivo na estrutura jogo.
	Parâmetros: O jogo, o nome do arquivo e a data
**/
void buscarDadosArquivo(Jogo *jogo, char *nomeArquivo, Data *data) {
	size_t tam;
	char *texto = NULL;
	FILE *arquivo = fopen(nomeArquivo, "r");

	getline(&texto, &tam, arquivo);
	texto[strlen(texto) - 1] = '\0';
	texto = decriptar(texto);

	sscanf(texto, "%[^\n]\n %[^\n]\n %d %d %d %d %d %d %d %d %d %d %d %d",
		    jogo->jogador1.nome,      jogo->jogador2.nome,
		    &jogo->jogador1.nivel,    &jogo->jogador2.nivel,
		    &jogo->jogador1.vitorias, &jogo->jogador2.vitorias,
		    &jogo->goban.dimensao,    &jogo->modo_de_jogo,
		    &data->hora,        &data->min,        &data->seg,
		    &data->dia,         &data->mes,        &data->ano);

	free(texto);
	fclose(arquivo);
}