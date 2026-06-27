#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

Lista* remove_inicio(Lista* l) {
    if (l == NULL) {
        return NULL;
    }
    Lista* p = l->prox;
    free(l);
    return p;
}

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

    l = remove_inicio(l);
    printf("\nApos remover o inicio (remove 1):\n");
    imprime(l);

  
    l = remove_valor(l, 3);
    printf("\nApos remover por valor (remove 3):\n");
    imprime(l);


    l = remove_posicao(l, 1);
    printf("\nApos remover por posicao 1 (remove 4):\n");
    imprime(l);

    return 0;
}