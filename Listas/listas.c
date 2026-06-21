#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

Lista* inicializa(void) {
    return NULL;
}

Lista* insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
    printf("NULL\n");
}

int main(void) {
    Lista* l = inicializa();
    int valor, i;

    for (i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &valor);
        l = insere(l, valor);
    }

    printf("\nLista criada:\n");
    imprime(l);
    return 0;
}