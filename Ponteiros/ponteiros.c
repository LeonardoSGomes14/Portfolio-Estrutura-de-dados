#include <stdio.h>

// exemplo de uso de ponteiros

int main() {
    int a = 5;
    int *p = &a;

    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", &a);
    printf("Valor através do ponteiro: %d\n", *p);

    *p = 20; // altera o valor de a através do ponteiro
    printf("Novo valor de a: %d\n", a);

    return 0;
}