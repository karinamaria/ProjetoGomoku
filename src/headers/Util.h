#ifndef UTIL_H
#define UTIL_H

#ifdef __WIN32__
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

int lixo;

char* converterParaMinusculo(char *resposta);
void limparBuffer();
void limparTela();
void existePasta();
int contarArquivoOuPasta(char *caminho);

#endif