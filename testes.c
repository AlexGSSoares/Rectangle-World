#include "minunit.h"
#include "retangulos.h"

int tests_run = 0;

static char *test_create_retangulo() {
    inicializar_mundo();
    criar_retangulo(1, 3, 15, 5);
    mu_assert("Erro: retângulo não foi criado corretamente", inicio != NULL && inicio->x == 1 && inicio->y == 3 && inicio->largura == 15 && inicio->altura == 5);
    liberar_mundo();
    return 0;
}

static char *test_mover_retangulo_esquerda() {
    inicializar_mundo();
    criar_retangulo(23, 7, 6, 5);
    mover_retangulo_esquerda(23, 7, 1);
    mu_assert("Erro: retângulo não se moveu corretamente à esquerda", inicio->x == 22);
    liberar_mundo();
    return 0;
}

static char *test_mover_retangulo_direita() {
    inicializar_mundo();
    criar_retangulo(1, 1, 15, 5);
    mover_retangulo_direita(1, 1, 1); //
    mu_assert("Erro: retângulo não se moveu corretamente à direita", inicio->x == 2);
    mover_retangulo_direita(2, 1, 63);
    mu_assert("Erro: retângulo não respeitou o limite máximo à direita", inicio->x + inicio->largura - 1 <= MAX_WIDTH);
    liberar_mundo();
    return 0;
}


static char *test_merge_retangulos() {
    inicializar_mundo();
    criar_retangulo(23, 12, 6, 5);
    criar_retangulo(23, 17, 6, 5);
    mergeRetangulos(23, 12, 23, 17);
    mu_assert("Erro: merge de retângulos falhou", inicio != NULL && inicio->altura == 10);
    liberar_mundo();
    return 0;
}

static char *all_tests() {
    mu_run_test(test_create_retangulo);
    mu_run_test(test_mover_retangulo_esquerda);
    mu_run_test(test_mover_retangulo_direita);
    mu_run_test(test_merge_retangulos);
    return 0;
}


int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("TODOS OS TESTES PASSARAM\n");
    }
    printf("Testes executados: %d\n", tests_run);

    return result != 0;
}
