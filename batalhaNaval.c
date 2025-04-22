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

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação: garantir que os navios caibam no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posicionar navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }

        // Validação de sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        // Se não houver sobreposição, posiciona o navio vertical
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            }
        } else {
            printf("Erro: Os navios se sobrepõem!\n");
            return 1;
        }

    } else {
        printf("Erro: Coordenadas inválidas. Os navios não cabem no tabuleiro.\n");
        return 1;
    }

    // Exibir o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
