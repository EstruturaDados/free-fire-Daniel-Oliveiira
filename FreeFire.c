#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item da mochila
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int total = 0; // Quantidade de itens cadastrados
    int opcao;

    do {
        printf("\n==============================\n");
        printf("🎒 SISTEMA DE INVENTÁRIO BÁSICO\n");
        printf("==============================\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("==============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch (opcao) {
            case 1: // Adicionar item
                if (total < MAX_ITENS) {
                    printf("\n🔹 Nome do item: ");
                    fgets(mochila[total].nome, 50, stdin);
                    mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

                    printf("🔹 Tipo do item: ");
                    fgets(mochila[total].tipo, 30, stdin);
                    mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

                    printf("🔹 Quantidade: ");
                    scanf("%d", &mochila[total].quantidade);
                    getchar();

                    total++;
                    printf("\n✅ Item adicionado com sucesso!\n");
                } else {
                    printf("\n⚠️ Mochila cheia! Não é possível adicionar mais itens.\n");
                }
                break;

            case 2: { // Remover item
                if (total == 0) {
                    printf("\n⚠️ Nenhum item para remover.\n");
                    break;
                }

                char nomeRemover[50];
                printf("\n🗑️ Digite o nome do item que deseja remover: ");
                fgets(nomeRemover, 50, stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                int encontrado = 0;
                for (int i = 0; i < total; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        encontrado = 1;
                        // Substitui o item removido pelo último
                        mochila[i] = mochila[total - 1];
                        total--;
                        printf("\n✅ Item removido com sucesso!\n");
                        break;
                    }
                }

                if (!encontrado)
                    printf("\n❌ Item não encontrado.\n");
                break;
            }

            case 3: // Listar itens
                if (total == 0) {
                    printf("\n📭 Mochila vazia.\n");
                } else {
                    printf("\n📋 Itens na mochila:\n");
                    printf("--------------------------------------------------\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("--------------------------------------------------\n");
                    for (int i = 0; i < total; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                    printf("--------------------------------------------------\n");
                }
                break;

            case 0:
                printf("\n👋 Saindo do inventário... Até logo!\n");
                break;

            default:
                printf("\n❌ Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
