#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

// Cria uma pilha vazia
Pilha* cria() {
    Pilha *nova;
    nova = (Pilha*) malloc(sizeof(Pilha));
    nova->topo = NULL;
    return nova;
}

// Insere um elemento no topo da pilha
void push(Pilha *p, int v) {
    No *novo;
    novo = (No*) malloc(sizeof(No));
    if (novo != NULL) {
        novo->prox = p->topo;
        novo->info = v;
        p->topo = novo;
    } else {
        printf("ERRO");
    }
}

// Verifica se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == NULL;
}

// Remove e retorna o elemento do topo da pilha
int pop(Pilha *p) {
    No *aux = p->topo;
    int v;
    if (!vazia(p)) {
        p->topo = aux->prox;
        v = aux->info;
        free(aux);
        return v;
    } else {
        printf("Pilha vazia");
        return -1;
    }
}

// Imprime os elementos da pilha, do topo até a base
void imprimir(Pilha *p) {
    No *aux = p->topo;
    while (aux != NULL) {
        printf("[%d]\n", aux->info);
        aux = aux->prox;
    }
}

int main() {
    Pilha *p = cria();

    push(p, 4);
    push(p, 3);
    push(p, 2);

    printf("Pilha:\n");
    imprimir(p); // [2] [3] [4]

    int removido = pop(p);
    printf("\nValor removido: %d\n", removido);

    printf("Pilha apos pop:\n");
    imprimir(p); // [3] [4]

    return 0;
}