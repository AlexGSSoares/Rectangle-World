#include "visualizacao.h"
#include "config.h"

extern Retangulo *inicio; // Usar a lista de retângulos definida em retangulos.c

void desenhar_mundo() {
    const int largura = MAX_WIDTH;
    const int altura = MAX_HEIGHT;
    char tela[altura][MAX_WIDTH + 1]; // +1 para o caractere nulo de terminação

    // Inicializa a tela com o grid
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            tela[i][j] = ' '; // Usando espaço para células vazias para melhor visualização
        }
        tela[i][largura] = '\0'; // Caractere nulo para terminar a string
    }

    // Desenha retângulos na tela
    Retangulo *atual = inicio;
    while (atual != NULL) {
        for (int i = 0; i < atual->altura; i++) {
            for (int j = 0; j < atual->largura; j++) {
                int telaY = altura - (atual->y + i); // Calcula a posição correta em Y na tela
                int telaX = atual->x + j - 1;        // Calcula a posição correta em X na tela
                if (telaY < 0 || telaY >= altura || telaX < 0 || telaX >= largura) {
                    continue; // Evita escrever fora dos limites da tela
                }

                // Verifica se é borda
                if (i == 0 || i == atual->altura - 1 || j == 0 || j == atual->largura - 1) {
                    tela[telaY][telaX] = 'X'; // Desenha a borda com 'X'
                } else {
                    tela[telaY][telaX] = 'O'; // Preenche o interior com 'O'
                }
            }
        }
        atual = atual->prox; // Move para o próximo retângulo na lista
    }

    // Imprime a tela
    for (int i = 0; i < altura; i++) {
        printf("%s\n", tela[i]);
    }
}
