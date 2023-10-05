/* Nome: Pedro Vinicius Ferreira Santos
   Matricula: 2021020317
   Professor: Frederico Gadelha Guimaraes*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

// Função para verificar se as coordenadas estão dentro dos limites do tabuleiro
bool dentroDosLimites(int x, int y, int tamanho) {
    return (x >= 0 && x < tamanho && y >= 0 && y < tamanho);
}

int main(int argc, char* argv[]) {
    int numJogos;
    scanf("%d", &numJogos);

    for (int jogo = 0; jogo < numJogos; jogo++) {
        int tamanho;
        scanf("%d", &tamanho);

        char tabuleiro[MAX][MAX];
        char revelado[MAX][MAX];
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                scanf(" %c", &tabuleiro[i][j]);
                revelado[i][j] = ' ';
            }
        }

        int numJogadas;
        scanf("%d", &numJogadas);

        bool perdeu = false;

        for (int jogada = 0; jogada < numJogadas; jogada++) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (perdeu || revelado[x][y] != ' ') {
                // O jogador já perdeu ou já revelou essa posição
                continue;
            }

            if (tabuleiro[x][y] == 'b') {
                // O jogador encontrou uma mina
                perdeu = true;
            } else {
                // Revela a posição atual
                revelado[x][y] = 'r';

                // Verifica se todos os vizinhos sem minas podem ser revelados
                if (tabuleiro[x][y] == 'x') {
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int novoX = x + dx;
                            int novoY = y + dy;
                            if (dentroDosLimites(novoX, novoY, tamanho) && tabuleiro[novoX][novoY] == 'x' && revelado[novoX][novoY] == ' ') {
                                revelado[novoX][novoY] = 'r';
                            }
                        }
                    }
                }
            }
        }

        bool ganhou = true;
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (tabuleiro[i][j] == 'x' && revelado[i][j] != 'r') {
                    ganhou = false;
                    break;
                }
            }
            if (!ganhou) {
                break;
            }
        }

        if (perdeu) {
            printf("PERDEU\n");
        } else if (ganhou) {
            printf("GANHOU\n");
        } else {
            printf("FALTOU TERMINAR\n");
        }

        if (jogo < numJogos - 1) {
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
