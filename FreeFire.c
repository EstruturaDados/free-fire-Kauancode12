#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {
    Item mochila[TAM];
    int contador_item = 0;
    int opcao;
}

void inserirItem(Item mochila[], int *contador) {
    if (*contador >= TAM) {
        printf("Inventario cheio.\n");
        return;
    }

    Item novo;
    printf("Digite o nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Digite o tipo do item: ");
    scanf(" %[^\n]", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*contador] = novo;
    (*contador)++;

    printf("Item inserido com sucesso.\n");
}

void listarItens(Item mochila[], int contador) {
    if (contador == 0) {
        printf("Inventario vazio.\n");
        return;
    }

    printf("=== Itens na mochila ===\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d - Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}



