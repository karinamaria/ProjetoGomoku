#include "headers/Util.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>

/**
	A função converterParaMinusculo será útil caso os jogadores digitem 
	'SIM' ou 'NAO' em letras maíusculas
	Parâmetro: A resposta digitada pelos jogadores
	Retorno: A resposta em letras minúsculas
**/
char* converterParaMinusculo (char *resposta){
	for(int i=0; i<strlen(resposta); i++){
		resposta[i]=tolower(resposta[i]);
	}
	return resposta;
}

/**
	A função limparBuffer limpa o buffer
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

void existePasta() {
	if (!contarArquivoOuPasta("./jogos")) {
		system("mkdir jogos");
	}
}

/**
	A função contarArquivo conta a qnt de arquivos do tipo jogo_*.txt
**/
int contarArquivoOuPasta(char *caminho){
	const char *pattern = caminho;

	glob_t pglob; 

  	glob(pattern, GLOB_ERR, NULL, &pglob);      

  	int qtd=(int)pglob.gl_pathc;

  	globfree(&pglob);

  	return qtd;
}