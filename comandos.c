#include "comandos.h"
#include "retangulos.h"
#include "config.h"

void processar_comando(char* comando) {
    int x, y, l, h, p;
    int x1, y1, x2, y2;
    if (sscanf(comando, "create %d,%d+%d,%d", &x, &y, &l, &h) == 4) {
        criar_retangulo(x, y, l, h);
    } else if (sscanf(comando, "moveright %d,%d+%d", &x, &y, &p) == 3) {
        mover_retangulo_direita(x, y, p);
    } else if (sscanf(comando, "moveleft %d,%d+%d", &x, &y, &p) == 3) {
        mover_retangulo_esquerda(x, y, p);
    } else if (sscanf(comando, "merge %d,%d+%d,%d", &x1, &y1, &x2, &y2) == 4) {
        mergeRetangulos(x1, y1, x2, y2);
    } else {
        printf("Comando inválido ou mal formatado: [%s]\n", comando);
    }
}