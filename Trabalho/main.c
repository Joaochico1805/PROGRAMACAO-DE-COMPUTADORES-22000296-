#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRATOS 20

// Nome: João Francisco Borges Ferreira
// Matrícula: 25201454
// Curso: Engenharia Eletrônica
// Disciplina: Programação de Computadores

typedef struct {
    int id;
    char nome[50];
    float preco;
} Prato;

typedef struct {
    int id_prato;
    int qtd;
} Pedido;

typedef struct NoPedido {
    Pedido dados;
    struct NoPedido* proximo;
} NoPedido;

void limpar_ecra();
void pausar();

void menu_salao(Prato cardapio[], int qnt_pratos, NoPedido** fila_pedidos);
void menu_cozinha(NoPedido** fila_pedidos);
void menu_caixa();
void menu_gerencia();

void exibir_cardapio(Prato cardapio[], int qnt_pratos);
void enfileirar_pedido(NoPedido** fila, Pedido p);
void desenfileirar_pedido(NoPedido** fila);

int main() {
    Prato cardapio[MAX_PRATOS] = {
        {1, "Prato 1", 10.0},
        {2, "Prato 2", 12.5},
        {3, "Prato 3", 15.0},
        {4, "Prato 4", 8.0},
        {5, "Prato 5", 20.0}
    };
    int qnt_pratos = 5; 
    int opcao_principal;
    
    // Inicialização do ponteiro cabeça da lista encadeada (Fila vazia)
    NoPedido* fila_pedidos = NULL; 

    do {
        limpar_ecra();
        printf("===============================\n");
        printf("    SISTEMA DE RESTAURANTE     \n");
        printf("===============================\n");
        printf("1- Salao\n");
        printf("2- Cozinha\n");
        printf("3- Caixa\n");
        printf("4- Gerencia (admin)\n");
        printf("0- Sair do Sistema\n");
        printf("===============================\n");
        printf("Digite a operacao desejada: ");
        scanf("%d", &opcao_principal);

        switch(opcao_principal) {
            case 1:
                menu_salao(cardapio, qnt_pratos, &fila_pedidos);
                break;
            case 2:
                menu_cozinha(&fila_pedidos);
                break;
            case 3:
                menu_caixa();
                break;
            case 4:
                menu_gerencia();
                break;
            case 0:
                limpar_ecra();
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
    } while(opcao_principal != 0);

    return 0;
}

void limpar_ecra() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void pausar() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); 
    getchar(); 
}

void enfileirar_pedido(NoPedido** fila, Pedido p) {
    NoPedido* novo_no = (NoPedido*)malloc(sizeof(NoPedido));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo_no->dados = p;
    novo_no->proximo = NULL;

    if (*fila == NULL) {
        *fila = novo_no;
    } else {
        NoPedido* aux = *fila;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo_no;
    }
}

void desenfileirar_pedido(NoPedido** fila) {
    if (*fila == NULL) {
        printf("\nNao ha pedidos pendentes na cozinha!\n");
        return;
    }
    NoPedido* no_remover = *fila;
    *fila = (*fila)->proximo;
    
    printf("\nPedido do prato ID %d (Qtd: %d) finalizado e removido da fila!\n", no_remover->dados.id_prato, no_remover->dados.qtd);
    free(no_remover);
}

void menu_salao(Prato cardapio[], int qnt_pratos, NoPedido** fila_pedidos) {
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("          MENU DO SALAO        \n");
        printf("===============================\n");
        printf("1- Cardapio\n");
        printf("2- Lancar Pedido\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                limpar_ecra();
                exibir_cardapio(cardapio, qnt_pratos);
                pausar();
                break;
            case 2:
                limpar_ecra();
                exibir_cardapio(cardapio, qnt_pratos);
                Pedido novo_pedido;
                printf("\nDigite o ID do prato: ");
                scanf("%d", &novo_pedido.id_prato);
                printf("Digite a quantidade: ");
                scanf("%d", &novo_pedido.qtd);
                
                enfileirar_pedido(fila_pedidos, novo_pedido);
                printf("\nPedido enviado para a cozinha com sucesso!\n");
                pausar();
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
    } while(opcao != 0);
}

void menu_cozinha(NoPedido** fila_pedidos) {
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("         MENU DA COZINHA       \n");
        printf("===============================\n");
        printf("1- Ver Fila de Pedidos\n");
        printf("2- Finalizar Proximo Pedido (Dar baixa)\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                limpar_ecra();
                printf("--- Fila de Pedidos Pendentes ---\n");
                NoPedido* aux = *fila_pedidos;
                if (aux == NULL) {
                    printf("A fila esta vazia.\n");
                } else {
                    int pos = 1;
                    while (aux != NULL) {
                        printf("%d. Prato ID: %d | Qtd: %d\n", pos++, aux->dados.id_prato, aux->dados.qtd);
                        aux = aux->proximo;
                    }
                }
                pausar();
                break;
            case 2:
                limpar_ecra();
                desenfileirar_pedido(fila_pedidos);
                pausar();
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
    } while (opcao != 0);
}

void menu_caixa(){
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("         MENU DO CAIXA         \n");
        printf("===============================\n");
        printf("1- Fechar Comanda\n");
        printf("2- Fechar Turno\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
            case 2:
                limpar_ecra();
                printf("\n[Funcionalidade para a Etapa 4 - Arquivos]\n");
                pausar();
                break;
            case 0: break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
    } while (opcao != 0);
}

void menu_gerencia(){
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("        MENU DA GERENCIA       \n");
        printf("===============================\n");
        printf("1- Cadastrar Item no Cardapio\n");
        printf("2- Remover Item do Cardapio\n");
        printf("3- Salvar Cardapio em Arquivo\n");
        printf("4- Carregar Cardapio do Arquivo\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
            case 2:
            case 3:
            case 4:
                limpar_ecra();
                printf("\n[Funcionalidade para a Etapa 4 - Arquivos]\n");
                pausar();
                break;
            case 0: break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
    } while (opcao != 0);
}

void exibir_cardapio(Prato cardapio[], int qnt_pratos) {
    printf("\n===============================\n");
    printf("          CARDAPIO             \n");
    printf("===============================\n");
    for (int i = 0; i < qnt_pratos; i++) {
        printf("%d - %s - R$ %.2f\n", cardapio[i].id, cardapio[i].nome, cardapio[i].preco);
    }
    printf("===============================\n");
}