#ifndef UTIL_H
#define UTIL_H

#ifdef __WIN32__
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

typedef struct{
	int seg;
	int min;
	int hora;
	int dia;
	int mes;
	int ano;
}Data;

int lixo;

char* converterParaMinusculo(char *resposta);
void limparBuffer();
void limparTela();
void existePasta();
int contarArquivoOuPasta(char *caminho);
Data dataAtual();
int sortearNumero(int menor_valor, int maior_valor);
void inicializarSorteio();
int verificarResposta(char *resposta, int idioma);

#endif