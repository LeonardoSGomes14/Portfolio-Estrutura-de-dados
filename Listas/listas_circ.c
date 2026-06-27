#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No* prox;
} Lista;

Lista* inicializa(void) {
    return NULL;
}

Lista* inserirFinal(Lista* l, int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;

    if (l == NULL) {
        novo->prox = novo;
        return novo;
    }

    Lista* p = l;
    while (p->prox != l) {
        p = p->prox;
    }
    p->prox = novo;
    novo->prox = l;
    return l;
}

void imprimir(Lista* l) {
    if (l == NULL) {
        return;
    }
    Lista* p = l;
    do {
        printf("%d -> ", p->info);
        p = p->prox;
    } while (p != l);
    printf("(volta ao inicio)\n");
}

int main(void) {
    Lista* l = inicializa();

    l = inserirFinal(l, 10);
    l = inserirFinal(l, 20);
    l = inserirFinal(l, 30);
    l = inserirFinal(l, 40);

    printf("Lista circular:\n");
    imprimir(l);

    return 0;
}