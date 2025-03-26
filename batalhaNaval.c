#include <stdio.h>

// Definimos o tamanho do tabuleiro e dos navios
#define SIZE 10       // Tamanho do tabuleiro: 10x10
#define SHIP_SIZE 3   // Tamanho de cada navio: 3 posições

int main() {
    // Criamos uma matriz para representar o tabuleiro, preenchendo inicialmente com zeros (água)
    int board[SIZE][SIZE] = {0};

    // Escolhemos as posições iniciais dos navios
    int ship1_row = 2, ship1_col = 3; // Início do navio horizontal
    int ship2_row = 5, ship2_col = 6; // Início do navio vertical

    // Colocamos o navio horizontal no tabuleiro
    // Percorremos as posições necessárias e marcamos com 3 para indicar o navio
    for (int i = 0; i < SHIP_SIZE; i++) {
        board[ship1_row][ship1_col + i] = 3;
    }

    // Colocamos o navio vertical no tabuleiro
    // Da mesma forma, usamos um loop para marcar as posições com 3
    for (int i = 0; i < SHIP_SIZE; i++) {
        board[ship2_row + i][ship2_col] = 3;
    }

    // Mostramos o tabuleiro na tela
    // Dois loops aninhados percorrem todas as linhas e colunas do tabuleiro
    // Imprimimos cada valor seguido de um espaço para clareza
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        // Após cada linha completa do tabuleiro, pulamos para a próxima linha
        printf("\n");
    }

    return 0;
}