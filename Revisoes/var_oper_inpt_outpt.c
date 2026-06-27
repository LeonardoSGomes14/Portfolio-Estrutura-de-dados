#include <stdio.h>

int main() {
    int idade;
    float altura;

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite sua altura: ");
    scanf("%f", &altura);

    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);

    return 0;
}