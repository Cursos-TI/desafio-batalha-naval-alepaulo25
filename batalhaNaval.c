#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -----------------------------
    // POSICIONAMENTO DOS NAVIOS
    // -----------------------------

    // 1. Navio Horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal não cabe no tabuleiro.\n");
        return 1;
    }

    // 2. Navio Vertical
    int linha_vertical = 5;
    int coluna_vertical = 7;

    int sobreposicao = 0;
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            }
        } else {
            printf("Erro: Navio vertical sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical não cabe no tabuleiro.\n");
        return 1;
    }

    // 3. Navio Diagonal Principal (↘)
    int linha_diag1 = 0;
    int coluna_diag1 = 0;
    sobreposicao = 0;

    if (linha_diag1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        coluna_diag1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diag1 + i][coluna_diag1 + i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_diag1 + i][coluna_diag1 + i] = NAVIO;
            }
        } else {
            printf("Erro: Navio diagonal principal sobrepõe outro navio.\n");
            return 1;
        }

    } else {
        printf("Erro: Navio diagonal principal não cabe no tabuleiro.\n");
        return 1;
    }

    // 4. Navio Diagonal Secundária (↙)
    int linha_diag2 = 0;
    int coluna_diag2 = 9;
    sobreposicao = 0;

    if (linha_diag2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        coluna_diag2 - (TAMANHO_NAVIO - 1) >= 0) {

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diag2 + i][coluna_diag2 - i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_diag2 + i][coluna_diag2 - i] = NAVIO;
            }
        } else {
            printf("Erro: Navio diagonal secundária sobrepõe outro navio.\n");
            return 1;
        }

    } else {
        printf("Erro: Navio diagonal secundária não cabe no tabuleiro.\n");
        return 1;
    }

    // -----------------------------
    // EXIBIÇÃO DO TABULEIRO
    // -----------------------------

    printf("\nTabuleiro (0 = água | 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

