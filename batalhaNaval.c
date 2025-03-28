#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
#define HABILIDADE_SIZE 5

// Inicializa o tabuleiro 10x10 com água (0)
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para mostrar o tabuleiro no console
void mostrarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Adiciona um navio ao tabuleiro em posições específicas
void adicionarNavios(int tabuleiro[SIZE][SIZE]) {
    // Exemplo de navios fixos
    tabuleiro[0][0] = 3;
    tabuleiro[0][1] = 3;
    tabuleiro[0][2] = 3;
    
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[4][2] = 3;
}

// Marca a área afetada pela habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[SIZE][SIZE], int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE], int origemLinha, int origemColuna) {
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTabuleiro = origemLinha + i - HABILIDADE_SIZE / 2;
                int colunaTabuleiro = origemColuna + j - HABILIDADE_SIZE / 2;
                
                // Verifica se está dentro dos limites do tabuleiro
                if (linhaTabuleiro >= 0 && linhaTabuleiro < SIZE && colunaTabuleiro >= 0 && colunaTabuleiro < SIZE) {
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca a área afetada
                    }
                }
            }
        }
    }
}

// Cria a matriz de habilidade em formato de cone
void criarCone(int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE]) {
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            habilidade[i][j] = (j >= HABILIDADE_SIZE / 2 - i && j <= HABILIDADE_SIZE / 2 + i) ? 1 : 0;
        }
    }
}

// Cria a matriz de habilidade em formato de cruz
void criarCruz(int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE]) {
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            habilidade[i][j] = (i == HABILIDADE_SIZE / 2 || j == HABILIDADE_SIZE / 2) ? 1 : 0;
        }
    }
}

// Cria a matriz de habilidade em formato de octaedro
void criarOctaedro(int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE]) {
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            habilidade[i][j] = (abs(j - HABILIDADE_SIZE / 2) + abs(i - HABILIDADE_SIZE / 2) <= HABILIDADE_SIZE / 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[SIZE][SIZE];
    inicializarTabuleiro(tabuleiro);
    adicionarNavios(tabuleiro);
    
    int habilidadeCone[HABILIDADE_SIZE][HABILIDADE_SIZE];
    int habilidadeCruz[HABILIDADE_SIZE][HABILIDADE_SIZE];
    int habilidadeOctaedro[HABILIDADE_SIZE][HABILIDADE_SIZE];
    
    criarCone(habilidadeCone);
    criarCruz(habilidadeCruz);
    criarOctaedro(habilidadeOctaedro);
    
    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 4, 4);
    aplicarHabilidade(tabuleiro, habilidadeCruz, 2, 7);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 7, 2);
    
    // Mostrar o tabuleiro final
    mostrarTabuleiro(tabuleiro);
    
    return 0;
}