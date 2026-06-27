#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void exibir(Aluno *a) {
    printf("Nome: %s\n", a->nome);
    printf("Idade: %d\n", a->idade);
    printf("Nota: %.2f\n", a->nota);
}

int main() {
    Aluno a1;

    printf("Digite o nome: ");
    scanf(" %[^\n]", a1.nome);
    printf("Digite a idade: ");
    scanf("%d", &a1.idade);
    printf("Digite a nota: ");
    scanf("%f", &a1.nota);

    exibir(&a1);
    return 0;
}