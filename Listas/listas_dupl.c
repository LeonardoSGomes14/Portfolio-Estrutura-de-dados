#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* ant;
    struct lista* prox;
} Lista;

Lista* criarNo(int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

Lista* inserirInicio(Lista* l, int valor) {
    Lista* novo = criarNo(valor);
    novo->prox = l;
    if (l != NULL) {
        l->ant = novo;
    }
    return novo;
}

Lista* inserirFinal(Lista* l, int valor) {
    Lista* novo = criarNo(valor);
    if (l == NULL) {
        return novo;
    }
    Lista* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    novo->ant = p;
    return l;
}

void imprimir(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
}

void imprimirReverso(Lista* l) {
    if (l == NULL) {
        return;
    }
    Lista* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->ant;
    }
}