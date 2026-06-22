#include <stdio.h>
#define MAX 5

typedef struct {
    int dados[MAX];
    int frente;
    int fim;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->fim = -1;
}

int filaVazia(Fila *f) {
    return f->fim < f->frente;
}

void enqueue(Fila *f, int valor) {
    if (f->fim == MAX - 1) {
        printf("Fila cheia!\n");
        return;
    }
    f->fim++;
    f->dados[f->fim] = valor;
}

int dequeue(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->dados[f->frente++];
}

void mostrar(Fila *f) {
    for (int i = f->frente; i <= f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializar(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    printf("Fila: ");
    mostrar(&f); // 10 20 30

    int removido = dequeue(&f);
    printf("Removido: %d\n", removido); // 10

    printf("Fila apos dequeue: ");
    mostrar(&f); // 20 30

    return 0;
}