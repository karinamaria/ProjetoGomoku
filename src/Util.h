#ifndef UTIL_H
#define UTIL_H

#ifdef __WIN32__
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

char* converterParaMinusculo(char *resposta);
void limparTela();

#endif