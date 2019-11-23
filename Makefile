CC = gcc
CFLAGS = -Wall

prog: clean main.o jogador.o tabuleiro.o regra1.o regra2.o regra3.o arquivo.o traducao.o tela.o util.o jogo.o
	$(CC) -o Gomoku src/*.o
clean:
	rm -f src/*.o
main.o: 
	$(CC) -o src/main.o -c src/main.c $(CFLAGS)
jogador.o: 
	$(CC) -o src/Jogador.o -c src/Jogador.c $(CFLAGS)
tabuleiro.o: 
	$(CC) -o src/Tabuleiro.o -c src/Tabuleiro.c $(CFLAGS)
regra1.o:
	$(CC) -o src/Regra1.o -c src/Regra1.c $(CFLAGS)
regra2.o:
	$(CC) -o src/Regra2.o -c src/Regra2.c $(CFLAGS)
regra3.o:
	$(CC) -o src/Regra3.o -c src/Regra3.c $(CFLAGS)
arquivo.o:
	$(CC) -o src/Arquivo.o -c src/Arquivo.c $(CFLAGS)
traducao.o:
	$(CC) -o src/Traducao.o -c src/Traducao.c $(CFLAGS)
tela.o:
	$(CC) -o src/Tela.o -c src/Tela.c $(CFLAGS)
util.o:
	$(CC) -o src/Util.o -c src/Util.c $(CFLAGS)
jogo.o: 
	$(CC) -o src/Jogo.o -c src/Jogo.c $(CFLAGS)