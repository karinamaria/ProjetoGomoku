#include "Util.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

void limparTela() {
	system(LIMPAR_TELA);
}