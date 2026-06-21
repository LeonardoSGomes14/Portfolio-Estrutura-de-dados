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