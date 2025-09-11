#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

void inserirItem(Item mochila[], int *contador);
void listarItens(Item mochila[], int contador);
void removerItem(Item mochila[], int *contador);
void buscarItem(Item mochila[], int contador);

int main() {
    Item mochila[TAM];
    int contador_item = 0;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &contador_item);
                break;
            case 2:
                removerItem(mochila, &contador_item);
                break;
            case 3:
                listarItens(mochila, contador_item);
                break;
            case 4:
                buscarItem(mochila, contador_item);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
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
    for (int i = 0; i < contador; i++) {
        printf("%d - Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void removerItem(Item mochila[], int *contador) {
    if (*contador ==0) {
        printf("Inventario vazio.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item que deseja remover: ");
    scanf(" %[^\n]", nome);

    int pos = -1;
    for (int i = 0; i < *contador; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Item nao encontrado.\n");
        return;
    }
    
    for (int i = pos; i < *contador - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*contador)--;
    printf("Item removido com sucesso.\n");
}

void buscarItem(Item mochila[], int contador) {
    if (contador == 0) {
        printf("Inventario vazio.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < contador; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado.\n");
}

