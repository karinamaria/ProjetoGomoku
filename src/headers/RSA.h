#ifndef RSA_H
#define RSA_H

char* cifrarCaractere(char caractere, unsigned long long int n, unsigned long long int e);
char* encriptar(char *mensagem);
char decifrarCaractere(unsigned long long int caractere, unsigned long long int n, unsigned long long int d);
char* decriptar(char* cifrado);

#endif