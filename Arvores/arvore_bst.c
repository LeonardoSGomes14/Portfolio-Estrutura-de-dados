#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no* esq;
    struct no* dir;
} No;


No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);
    if (valor < raiz->info)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->info)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}


No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->info == valor)
        return raiz;
    if (valor < raiz->info)
        return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}


void preOrdem(No* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->info);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}


void emOrdem(No* raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esq);
    printf("%d ", raiz->info);
    emOrdem(raiz->dir);
}

void posOrdem(No* raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d ", raiz->info);
}

void destruir(No* raiz) {
    if (raiz == NULL) return;
    destruir(raiz->esq);
    destruir(raiz->dir);
    free(raiz);
}

int main(void) {
    No* raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Pre-ordem:  ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-ordem:   ");
    emOrdem(raiz);
    printf("\n");

    printf("Pos-ordem:  ");
    posOrdem(raiz);
    printf("\n");

    int valor = 40;
    No* resultado = buscar(raiz, valor);
    if (resultado != NULL)
        printf("\nValor %d encontrado na arvore.\n", valor);
    else
        printf("\nValor %d nao encontrado.\n", valor);

    destruir(raiz);
    printf("Memoria liberada.\n");

    return 0;
}