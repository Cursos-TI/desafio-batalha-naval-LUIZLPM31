#include <stdio.h>

#define SIZE 10           // Tamanho do tabuleiro (10x10)
#define CONE_LIN 3        // Número de linhas do padrão Cone
#define CONE_COL 5        // Número de colunas do padrão Cone
#define OCTAEDRO_LIN 3    // Número de linhas do padrão Octaedro
#define OCTAEDRO_COL 5    // Número de colunas do padrão Octaedro
#define CRUZ_LIN 3        // Número de linhas do padrão Cruz
#define CRUZ_COL 5        // Número de colunas do padrão Cruz

// Função para inicializar a matriz com zeros
void inicializarMatriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {            
        for (int j = 0; j < SIZE; j++) {        
            matriz[i][j] = 0;                    
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirMatriz(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {             
        for (int j = 0; j < SIZE; j++) {         
            printf("%d ", matriz[i][j]);         
        }
        printf("\n");                            
    }
    printf("\n");                               
}

void desenharCone(int matriz[SIZE][SIZE], int centro_i, int centro_j) {
    // Percorre todas as posições do tabuleiro
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Calcula a diferença em relação ao centro escolhido
            int delta_i = i - centro_i;
            int delta_j = j - centro_j;
            
            // Verifica se a posição está dentro do padrão Cone
            if (delta_i == -1 && delta_j == 0) {
                matriz[i][j] = 1;
            } else if (delta_i == 0 && (delta_j >= -1 && delta_j <= 1)) {
                matriz[i][j] = 1;
            } else if (delta_i == 1 && (delta_j >= -2 && delta_j <= 2)) {
                matriz[i][j] = 1;
            }
        }
    }
}

void desenharOctaedro(int matriz[SIZE][SIZE], int centro_i, int centro_j) {
    // Percorre todas as posições do tabuleiro
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int delta_i = i - centro_i;
            int delta_j = j - centro_j;
            
            // Define as condições para marcar com 1 conforme padrão
            if (delta_i == -1 && delta_j == 0) {
                matriz[i][j] = 1;
            } else if (delta_i == 0 && (delta_j >= -1 && delta_j <= 1)) {
                matriz[i][j] = 1;
            } else if (delta_i == 1 && delta_j == 0) {
                matriz[i][j] = 1;
            }
        }
    }
}

void desenharCruz(int matriz[SIZE][SIZE], int centro_i, int centro_j) {
    // Percorre todas as posições do tabuleiro
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int delta_i = i - centro_i;
            int delta_j = j - centro_j;
            
            // Define as condições para marcar as áreas afetadas na Cruz
            if (delta_i == -1 && delta_j == 0) {
                matriz[i][j] = 1;
            } else if (delta_i == 0 && (delta_j >= -2 && delta_j <= 2)) {
                matriz[i][j] = 1;
            } else if (delta_i == 1 && delta_j == 0) {
                matriz[i][j] = 1;
            }
        }
    }
}

int main() {
    int tabuleiro[SIZE][SIZE];  
    int centroLinha = 5;         
    int centroColuna = 5;        
    
    // Desenhar e exibir o padrão Cone
    inicializarMatriz(tabuleiro);                
    desenharCone(tabuleiro, centroLinha, centroColuna);  
    printf("Padrão Cone:\n");
    imprimirMatriz(tabuleiro);                  
    
    // Desenhar e exibir o padrão Octaedro
    inicializarMatriz(tabuleiro);
    desenharOctaedro(tabuleiro, centroLinha, centroColuna);
    printf("Padrão Octaedro:\n");
    imprimirMatriz(tabuleiro);
    
    // Desenhar e exibir o padrão Cruz
    inicializarMatriz(tabuleiro);
    desenharCruz(tabuleiro, centroLinha, centroColuna);
    printf("Padrão Cruz:\n");
    imprimirMatriz(tabuleiro);
    
    return 0;
}
