CC = gcc
CFLAGS = -Wall

prog: clean main.o jogador.o tabuleiro.o jogo.o
	$(CC) -o prog main.o Jogador.o Tabuleiro.o Jogo.o
clean:
	rm -f *.o
main.o: main.c 
	$(CC) -o main.o -c main.c $(CFLAGS)
jogador.o: Jogador.c 
	$(CC) -o Jogador.o -c Jogador.c $(CFLAGS)
tabuleiro.o: Tabuleiro.c
	$(CC) -o Tabuleiro.o -c Tabuleiro.c $(CFLAGS)
jogo.o: Jogo.c
	$(CC) -o Jogo.o -c Jogo.c $(CFLAGS)