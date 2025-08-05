#ifndef EFOLIOB_CONFIG_H
#define EFOLIOB_CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Retangulo {
    int x, y;          // Posição do canto inferior esquerdo
    int largura, altura; // Dimensões do retângulo
    struct Retangulo *prox; // Ponteiro para o próximo retângulo na lista
} Retangulo;

extern const int MAX_WIDTH;
extern const int MAX_HEIGHT;

extern Retangulo *inicio;  // Início da lista ligada de retângulos

#endif
