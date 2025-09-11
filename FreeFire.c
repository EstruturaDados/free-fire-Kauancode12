#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10// Define a capacidade maxima do inventario.

// Cria a struct e coloca o apelido Item para facilitar seu uso.
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Prototipos das funções.
void inserirItem(Item mochila[], int *contador);
void listarItens(Item mochila[], int contador);
void removerItem(Item mochila[], int *contador);
void buscarItem(Item mochila[], int contador);
void pausar();

int main() {
    Item mochila[TAM];
    int contador_item = 0;
    int opcao;

    // Menu interativo que chama as funções.
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

// Função de inserir item no inventário, primeiro verifica se o inventário está cheio por meio do contador, se sim ele não continua,
// se tiver espaço ele cadastra as informações do item e incrementa o contador.
void inserirItem(Item mochila[], int *contador) {
    if (*contador >= TAM) {
        printf("Inventario cheio.\n");
        pausar();
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
    pausar();// Função que pede pro usuario digitar ENTER para continuar.
}

// Função que utiliza um loop for para exibir os itens na mochila,
// antes disso ele verifica se o inventário está vazio
void listarItens(Item mochila[], int contador) {
    if (contador == 0) {
        printf("Inventario vazio.\n");
        pausar();
        return;
    }

    printf("\n=== Itens na mochila ===\n");
    for (int i = 0; i < contador; i++) {
        printf("%d - Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }

    pausar();
}

// Função que remove itens por meio de seu nome,
// também verifica se o inventário está vazio, e se o nome digitado não existir ele invalida a tentativa.
void removerItem(Item mochila[], int *contador) {
    if (*contador ==0) {
        printf("Inventario vazio.\n");
        pausar();
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
        pausar();
        return;
    }
    
    for (int i = pos; i < *contador - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*contador)--;
    printf("Item removido com sucesso.\n");
    pausar();
}

// Função que busca um item especifico com base no seu nome,
// também contém medidas para validar as escolhas.
void buscarItem(Item mochila[], int contador) {
    if (contador == 0) {
        printf("Inventario vazio.\n");
        pausar();
        return;
    }

    char nome[30];
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < contador; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            pausar();
            return;
        }
    }

    printf("Item nao encontrado.\n");
    pausar();
}

// Função que pausa o programa e pede um ENTER para prosseguir.
void pausar() {
    printf("\nPressione ENTER para prosseguir...");
        getchar();
        getchar();
}

