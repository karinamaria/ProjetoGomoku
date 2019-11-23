#include "headers/Util.h"
#include "headers/Traducao.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>
#include <time.h>

/**
	A função converterParaMinusculo será útil caso os jogadores digitem 
	'SIM' ou 'NAO' em letras maíusculas
	Parâmetro: A resposta digitada pelos jogadores
	Retorno: A resposta em letras minúsculas
**/
char* converterParaMinusculo(char *resposta){
	for(int i=0; i<strlen(resposta); i++){
		resposta[i]=tolower(resposta[i]);
	}
	return resposta;
}

/**
	A função limparBuffer limpa o buffer usando
	uma variável global
**/
void limparBuffer() {
	while ((lixo = getchar()) != '\n' && lixo != EOF);
}

/**
	A função limparTela executa um comando de terminal
	para limpar a tela
**/
void limparTela() {
	system(LIMPAR_TELA);
}

/**
	A função existePasta verifica se a pasta que salva
	jogos já existe, caso não existe ela será criada
**/
void existePasta() {
	if (!contarArquivoOuPasta("./jogos")) {
		system("mkdir jogos");
	}
}

/**
	A função contarArquivo conta a qnt de arquivos do tipo jogo_*.txt
	Parâmetro: O caminha para o arquivo ou pasta
	Retorno: A quantidade de arquivos/pastas existentes
**/
int contarArquivoOuPasta(char *caminho){
	const char *pattern = caminho;

	glob_t pglob;

  	glob(pattern, GLOB_ERR, NULL, &pglob);

  	int qtd=(int)pglob.gl_pathc;

  	globfree(&pglob);

  	return qtd;
}

/**
	A função dataAtual retorna uma estrutura contando a data atual
	Retorno: estrutura do tipo Data
**/
Data dataAtual() {
	Data data;
	time_t d = time(NULL);
	struct tm *data_atual = localtime(&d);
	
	data.seg  = data_atual->tm_sec;
	data.min  = data_atual->tm_min;
	data.hora = data_atual->tm_hour;
	data.dia  = data_atual->tm_mday;
	data.mes  = data_atual->tm_mon + 1;
	data.ano  = data_atual->tm_year + 1900;

	return data;
}
/**
	A função verificarResposta analisa se a resposta corresponde a 
	um dos três idiomas
	Parâmetros: a resposta e o idioma
	Retorno: 1(resposta certa) ou 0(resposta errada)
**/
int verificarResposta(char *resposta, int idioma){
	if(idioma == PORTUGUES){
		return strcmp("sim", resposta) != 0 && strcmp("nao", resposta) != 0;
	}else if(idioma == INGLES){
		return strcmp("yes", resposta) != 0 && strcmp("no", resposta) != 0;
	}
	return strcmp("si", resposta) != 0 && strcmp("no", resposta) != 0;
}