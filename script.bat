set FRAG = -Wall

del src\*.o
gcc -o src\Jogador.o -c src\Jogador.c %FRAG%
gcc -o src\Tabuleiro.o -c src\Tabuleiro.c %FRAG%
gcc -o src\Validacoes.o -c src\Validacoes.c %FRAG%
gcc -o src\Util.o -c src\Util.c %FRAG%
gcc -o src\Jogo.o -c src\Jogo.c %FRAG%
gcc -o src\main.o -c src\main.c %FRAG%
gcc -o Gomoku.exe src\main.o src\Jogador.o src\Tabuleiro.o src\Validacoes.o src\Util.o src\Jogo.o %FRAG%
Gomoku.exe