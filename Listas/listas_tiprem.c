#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

// Remoção do inicio
Lista* remove_inicio(Lista* l) {
    if (l == NULL) {
        return NULL;
    }
    Lista* p = l->prox;
    free(l);
    return p;
}

// Remoçao por valor
Lista* remove_valor(Lista* l, int v) {
    if (l == NULL) {
        return NULL;
    }
    if (l->info == v) {
        return remove_inicio(l);
    }
    Lista* anterior = l;
    Lista* atual = l->prox;
    while (atual != NULL) {
        if (atual->info == v) {
            anterior->prox = atual->prox;
            free(atual);
            return l;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return l; 
}

// Remoção por posição
Lista* remove_posicao(Lista* l, int pos) {
    if (l == NULL) {
        return NULL;
    }
    if (pos == 0) {
        return remove_inicio(l);
    }
    Lista* anterior = l;
    int i;
    for (i = 0; i < pos - 1 && anterior->prox != NULL; i++) {
        anterior = anterior->prox;
    }
    if (anterior->prox == NULL) {
        return l; 
    }
    Lista* alvo = anterior->prox;
    anterior->prox = alvo->prox;
    free(alvo);
    return l;
}