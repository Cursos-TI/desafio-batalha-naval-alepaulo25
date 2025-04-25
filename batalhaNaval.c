#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar a matriz de habilidade em forma de cone
void criarCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2) - i && j <= (TAMANHO_HABILIDADE / 2) + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para inicializar a matriz de habilidade em forma de cruz
void criarCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para inicializar a matriz de habilidade em forma de octaedro
void criarOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para aplicar uma matriz de habilidade ao tabuleiro no ponto de origem
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origem_linha, int origem_coluna) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha = origem_linha - offset + i;
            int coluna = origem_coluna - offset + j;

            // Verifica limites do tabuleiro
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) printf("0 ");
            else if (tabuleiro[i][j] == NAVIO) printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE) printf("5 ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // --- POSICIONA NAVIOS (mesmo do nível anterior) ---
    // Horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[2][4 + i] = NAVIO;
    }
    // Vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[5 + i][7] = NAVIO;
    }
    // Diagonal principal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[0 + i][0 + i] = NAVIO;
    }
    // Diagonal secundária
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[0 + i][9 - i] = NAVIO;
    }

    // --- HABILIDADES ---
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicar as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 6, 2);      // Exemplo: Cone com origem em (6,2)
    aplicarHabilidade(tabuleiro, cruz, 3, 5);      // Exemplo: Cruz com origem em (3,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Exemplo: Octaedro com origem em (7,7)

    // --- EXIBIR ---
    exibirTabuleiro(tabuleiro);

    return 0;
}


