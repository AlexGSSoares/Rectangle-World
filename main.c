#include "comandos.h"
#include "visualizacao.h"
#include "config.h"

const int MAX_WIDTH = 80;
const int MAX_HEIGHT = 25;

Retangulo *inicio = NULL;

int main() {
    char comando[100];
    printf("Bem-vindo ao Mundo dos Retangulos!\n");
    while (1) {
        printf("Digite um comando ou 'exit' para sair:\n");
        fgets(comando, sizeof(comando), stdin);
        if (strncmp(comando, "exit", 4) == 0) {
            break;
        }
        processar_comando(comando);
        desenhar_mundo();
    }
    return 0;
}
