#include "retangulos.h"

void inicializar_mundo() {
    inicio = NULL;
}

void liberar_mundo() {
    Retangulo *atual = inicio;
    while (atual != NULL) {
        Retangulo *tmp = atual;
        atual = atual->prox;
        free(tmp);
    }
    inicio = NULL;
}

void adicionar_retangulo(Retangulo *novo) {
    if (inicio == NULL) {
        inicio = novo;
    } else {
        Retangulo *atual = inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void ajustar_gravidade(Retangulo *novo) {
    bool precisaAjustar;
    do {
        precisaAjustar = false;
        int yBase = 1; // O chão
        Retangulo *atual = inicio;

        while (atual != NULL) {
            if (atual != novo && novo->x < atual->x + atual->largura && novo->x + novo->largura > atual->x) {
                int topoAtual = atual->y + atual->altura;
                if (topoAtual > yBase && atual->y < novo->y) { // Verifica se está realmente abaixo
                    yBase = topoAtual;
                }
            }
            atual = atual->prox;
        }

        if (novo->y != yBase) {
            novo->y = yBase;
            precisaAjustar = true; // Continua se houver mudanças
        }
    } while (precisaAjustar);
}

void atualizar_gravidade_global() {
    Retangulo *atual = inicio;
    while (atual != NULL) {
        ajustar_gravidade(atual);
        atual = atual->prox;
    }
}

void criar_retangulo(int x, int y, int largura, int altura) {
    if (x < 1 || x + largura > 81 || y < 1 || y + altura > 26) {
        printf("Erro: Retangulo fora dos limites permitidos.\n");
        return;
    }
    Retangulo *novo = (Retangulo*) malloc(sizeof(Retangulo));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para um novo retangulo.\n");
        return;
    }
    novo->x = x;
    novo->y = y; // A posição y inicial é temporária
    novo->largura = largura;
    novo->altura = altura;
    novo->prox = NULL;

    ajustar_gravidade(novo); // Ajustar a posição y antes de adicionar à lista

    adicionar_retangulo(novo);
    printf("Criado retangulo em (%d, %d) com largura %d e altura %d\n", novo->x, novo->y, largura, altura);
}


void mover_retangulo_direita(int x, int y, int p) {
    Retangulo *atual = inicio;
    bool retanguloEncontrado = false;

    while (atual != NULL) {
        if (atual->x <= x && x < atual->x + atual->largura &&
            atual->y <= y && y < atual->y + atual->altura) {
            if (atual->x + atual->largura + p <= MAX_WIDTH) {
                atual->x += p;
                printf("Movido retangulo de (%d, %d) para a esquerda %d posicoes\n", x, y, p);
                retanguloEncontrado = true;
                break;
            }  else {
                printf("Movimento invalido. Retangulo sairia dos limites.\n");
                return;
            }
        }
        atual = atual->prox;
    }
    if (!retanguloEncontrado) {
        printf("Retangulo não encontrado.\n");
    } else {
        atualizar_gravidade_global(); // Atualiza a gravidade para todos após o movimento
    }
}


bool mergePossivel(Retangulo *r1, Retangulo *r2) {
    return (r1->x == r2->x && r1->largura == r2->largura && r1->y + r1->altura == r2->y);
}


void mover_retangulo_esquerda(int x, int y, int p) {
    Retangulo *atual = inicio;
    bool retanguloEncontrado = false;
    while (atual != NULL) {
        if (atual->x <= x && x < atual->x + atual->largura &&
            atual->y <= y && y < atual->y + atual->altura) {
            if (atual->x - p >= 1) { // Garante que não saia do limite esquerdo
                atual->x -= p;
                printf("Movido retangulo de (%d, %d) para a esquerda %d posicoes\n", x, y, p);
                retanguloEncontrado = true;
                break;
            } else {
                printf("Movimento invalido. Retangulo sairia dos limites.\n");
                return;
            }
        }
        atual = atual->prox;
    }
    if (!retanguloEncontrado) {
        printf("Retangulo não encontrado.\n");
    } else {
        atualizar_gravidade_global(); // Atualiza a gravidade para todos após o movimento
    }
}

// Função para encontrar o retângulo anterior na lista ligada
Retangulo* encontrarAnterior(Retangulo *retangulo) {
    Retangulo *atual = inicio;
    Retangulo *anterior = NULL;
    while (atual != NULL && atual != retangulo) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == retangulo) {
        return anterior; // Retorna o anterior se o retângulo foi encontrado
    }
    return NULL; // Retorna NULL se o retângulo não foi encontrado
}


void mergeRetangulos(int x1, int y1, int x2, int y2) {
    Retangulo *r1 = NULL, *r2 = NULL;
    Retangulo *atual = inicio;
    while (atual) {
        if (atual->x <= x1 && x1 < atual->x + atual->largura && atual->y <= y1 && y1 < atual->y + atual->altura) {
            r1 = atual;
        }
        if (atual->x <= x2 && x2 < atual->x + atual->largura && atual->y <= y2 && y2 < atual->y + atual->altura) {
            r2 = atual;
        }
        atual = atual->prox;
    }
    if (r1 && r2 && mergePossivel(r1, r2)) {
        r1->altura += r2->altura;
        Retangulo *anterior = encontrarAnterior(r2);
        if (anterior != NULL) {
            anterior->prox = r2->prox; // Atualiza o ponteiro para 'pular' o r2
        } else {
            inicio = r2->prox; // Se r2 for o primeiro na lista, atualiza o início
        }
        free(r2); // Libera a memória de r2
        printf("Retangulos fundidos com sucesso.\n");
    } else {
        printf("Nao e possivel fundir os retangulos.\n");
    }
}

void alertaSobreposicao() {
    printf("Alerta: Sobreposição detectada!\n");
}

void verificarSobreposicoes() {
    Retangulo *r1 = inicio, *r2;
    while (r1) {
        r2 = r1->prox;
        while (r2) {
            if (mergePossivel(r1, r2)) {
                alertaSobreposicao();
                return;
            }
            r2 = r2->prox;
        }
        r1 = r1->prox;
    }
}