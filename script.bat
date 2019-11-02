set FLAG = -Wall

del src\*.o
gcc -o src\Jogador.o -c src\Jogador.c %FLAG%
gcc -o src\Tabuleiro.o -c src\Tabuleiro.c %FLAG%
gcc -o src\Validacoes.o -c src\Validacoes.c %FLAG%
gcc -o src\Util.o -c src\Util.c %FLAG%
gcc -o src\Jogo.o -c src\Jogo.c %FLAG%
gcc -o src\main.o -c src\main.c %FLAG%
gcc -o Gomoku.exe src\main.o src\Jogador.o src\Tabuleiro.o src\Validacoes.o src\Util.o src\Jogo.o %FLAG%
Gomoku.exe