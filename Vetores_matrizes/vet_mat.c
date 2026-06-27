#include <stdio.h>

int main() {
  
    int numeros[5] = {1, 2, 3, 4, 5};
    int soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += numeros[i];
    }
    printf("Soma do vetor: %d\n", soma);


    int matriz[2][2] = {{1, 2}, {3, 4}};
    printf("Elementos da matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}