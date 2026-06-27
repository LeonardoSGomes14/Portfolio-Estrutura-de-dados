#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

Lista* busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v)
            return p;
    }
    return NULL;
}

Lista* remove_ultimo(Lista* l) {
    if (l == NULL) {
        return NULL;
    }
    if (l->prox == NULL) {
        free(l);
        return NULL;
    }
    Lista* p = l;
    while (p->prox->prox != NULL) {
        p = p->prox;
    }
    free(p->prox);
    p->prox = NULL;
    return l;
}

void libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
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
    Lista* l = NULL;


    l = insere(l, 5);
    l = insere(l, 4);
    l = insere(l, 3);
    l = insere(l, 2);
    l = insere(l, 1);

    printf("Lista inicial:\n");
    imprime(l);


    int valor = 3;
    Lista* resultado = busca(l, valor);
    if (resultado != NULL)
        printf("Valor %d encontrado na lista.\n", valor);
    else
        printf("Valor %d nao encontrado.\n", valor);


    l = remove_ultimo(l);
    printf("\nApos remover o ultimo elemento:\n");
    imprime(l);


    libera(l);
    printf("\nMemoria liberada.\n");

    return 0;
}