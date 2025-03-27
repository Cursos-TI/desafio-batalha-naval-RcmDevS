#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
#define SHIP_SIZE 3

// Preenche o tabuleiro com zeros (0), representando água
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verifica se um navio pode ser colocado em uma posição específica
bool posicaoValida(int tabuleiro[SIZE][SIZE], int linha, int coluna, int direcao, bool diagonal) {
    for (int i = 0; i < SHIP_SIZE; i++) {
        int x = linha + i * (diagonal || direcao == 0);
        int y = coluna + i * (diagonal || direcao == 1);
        
        // Verifica se está dentro do tabuleiro e se não tem outro navio no caminho
        if (x >= SIZE || y >= SIZE || tabuleiro[x][y] != 0) {
            return false;
        }
    }
    return true;
}

// Coloca o navio no tabuleiro
void colocarNavio(int tabuleiro[SIZE][SIZE], int linha, int coluna, int direcao, bool diagonal) {
    for (int i = 0; i < SHIP_SIZE; i++) {
        int x = linha + i * (diagonal || direcao == 0);
        int y = coluna + i * (diagonal || direcao == 1);
        tabuleiro[x][y] = 3; // Marca onde o navio está
    }
}

// Mostra o tabuleiro no console
void mostrarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[SIZE][SIZE];
    inicializarTabuleiro(tabuleiro);
    
    // Colocando dois navios em linha reta (horizontal ou vertical)
    if (posicaoValida(tabuleiro, 0, 0, 0, false)) {
        colocarNavio(tabuleiro, 0, 0, 0, false); // Navio na horizontal
    }
    if (posicaoValida(tabuleiro, 2, 2, 1, false)) {
        colocarNavio(tabuleiro, 2, 2, 1, false); // Navio na vertical
    }
    
    // Colocando dois navios na diagonal
    if (posicaoValida(tabuleiro, 5, 5, 0, true)) {
        colocarNavio(tabuleiro, 5, 5, 0, true); // Navio na diagonal principal
    }
    if (posicaoValida(tabuleiro, 7, 2, 1, true)) {
        colocarNavio(tabuleiro, 7, 2, 1, true); // Navio na diagonal secundária
    }
    
    // Exibe o tabuleiro
    mostrarTabuleiro(tabuleiro);
    
    return 0;
}