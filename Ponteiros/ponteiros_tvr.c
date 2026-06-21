#include <stdio.h>

// troca os valores usando ponteiros

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    troca(&x, &y);
    printf("x=%d y=%d\n", x, y);
    return 0;
}