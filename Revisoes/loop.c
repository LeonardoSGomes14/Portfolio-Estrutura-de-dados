#include <stdio.h>

int main() {
    int i, soma = 0;

    for (i = 1; i <= 10; i++) {
        soma = soma + i;
    }
    printf("Soma de 1 a 10: %d\n", soma);

    int opcao;
    do {
        printf("Digite 0 para sair: ");
        scanf("%d", &opcao);
    } while (opcao != 0);

    return 0;
}