#ifndef RETANGULOS_H
#define RETANGULOS_H

#include "config.h"

void criar_retangulo(int x, int y, int largura, int altura);
void mover_retangulo_direita(int x, int y, int p);
void mover_retangulo_esquerda(int x, int y, int p);

void inicializar_mundo();
void liberar_mundo();

bool mergePossivel(Retangulo *r1, Retangulo *r2);
void mergeRetangulos(int x1, int y1, int x2, int y2);
void alertaSobreposicao();
void verificarSobreposicoes();

#endif
