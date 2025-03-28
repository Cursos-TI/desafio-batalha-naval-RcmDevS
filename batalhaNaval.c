#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
#define HABILIDADE_SIZE 5

// Inicializa o tabuleiro 10x10 com água (0)
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    // Percorre cada posição do tabuleiro de 10x10
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0; // Define cada posição como 0, representando água
        }
    }
}

// Função para mostrar o tabuleiro no console
void mostrarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    // Percorre as linhas do tabuleiro
    for (int i = 0; i < SIZE; i++) {
        // Percorre as colunas do tabuleiro
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor atual do tabuleiro
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }
}

// Adiciona um navio ao tabuleiro em posições específicas
void adicionarNavios(int tabuleiro[SIZE][SIZE]) {
    // Define algumas posições específicas com o valor 3 para representar navios
    tabuleiro[0][0] = 3; // Navio começando na posição (0,0)
    tabuleiro[0][1] = 3; // Continuando o navio na posição (0,1)
    tabuleiro[0][2] = 3; // Continuando o navio na posição (0,2)
    
    tabuleiro[2][2] = 3; // Outro navio começando na posição (2,2)
    tabuleiro[3][2] = 3; // Continuando o navio na posição (3,2)
    tabuleiro[4][2] = 3; // Continuando o navio na posição (4,2)
}

// Marca a área afetada pela habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[SIZE][SIZE], int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE], int origemLinha, int origemColuna) {
    // Percorre a matriz da habilidade
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            // Verifica se a posição na matriz de habilidade é afetada (valor 1)
            if (habilidade[i][j] == 1) {
                // Calcula a posição correspondente no tabuleiro
                int linhaTabuleiro = origemLinha + i - HABILIDADE_SIZE / 2;
                int colunaTabuleiro = origemColuna + j - HABILIDADE_SIZE / 2;
                
                // Verifica se a posição calculada está dentro dos limites do tabuleiro
                if (linhaTabuleiro >= 0 && linhaTabuleiro < SIZE && colunaTabuleiro >= 0 && colunaTabuleiro < SIZE) {
                    // Se a posição do tabuleiro for água (0), marca como afetada (5)
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }
}

// Cria a matriz de habilidade em formato de cone
void criarCone(int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE]) {
    // Preenche a matriz 5x5 para formar um cone
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            // Define 1 para posições que formam um triângulo invertido
            habilidade[i][j] = (j >= HABILIDADE_SIZE / 2 - i && j <= HABILIDADE_SIZE / 2 + i) ? 1 : 0;
        }
    }
}

// Cria a matriz de habilidade em formato de cruz
void criarCruz(int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE]) {
    // Preenche a matriz 5x5 para formar uma cruz
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            // Define 1 para a linha e coluna central
            habilidade[i][j] = (i == HABILIDADE_SIZE / 2 || j == HABILIDADE_SIZE / 2) ? 1 : 0;
        }
    }
}

// Cria a matriz de habilidade em formato de octaedro
void criarOctaedro(int habilidade[HABILIDADE_SIZE][HABILIDADE_SIZE]) {
    // Preenche a matriz 5x5 para formar a vista frontal de um octaedro
    for (int i = 0; i < HABILIDADE_SIZE; i++) {
        for (int j = 0; j < HABILIDADE_SIZE; j++) {
            // Define 1 para formar um losango central
            habilidade[i][j] = (abs(j - HABILIDADE_SIZE / 2) + abs(i - HABILIDADE_SIZE / 2) <= HABILIDADE_SIZE / 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[SIZE][SIZE]; // Define o tabuleiro de jogo
    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro com água
    adicionarNavios(tabuleiro); // Adiciona navios ao tabuleiro
    
    int habilidadeCone[HABILIDADE_SIZE][HABILIDADE_SIZE]; // Matriz para habilidade em cone
    int habilidadeCruz[HABILIDADE_SIZE][HABILIDADE_SIZE]; // Matriz para habilidade em cruz
    int habilidadeOctaedro[HABILIDADE_SIZE][HABILIDADE_SIZE]; // Matriz para habilidade em octaedro
    
    criarCone(habilidadeCone); // Cria a matriz de cone
    criarCruz(habilidadeCruz); // Cria a matriz de cruz
    criarOctaedro(habilidadeOctaedro); // Cria a matriz de octaedro
    
    // Aplica as habilidades no tabuleiro em posições específicas
    aplicarHabilidade(tabuleiro, habilidadeCone, 4, 4);
    aplicarHabilidade(tabuleiro, habilidadeCruz, 2, 7);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 7, 2);
    
    // Exibe o tabuleiro final com as áreas afetadas
    mostrarTabuleiro(tabuleiro);
    
    return 0; // Encerra o programa
}