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
    int id;
    int qtd;
} Pedido;

void limpar_ecra();
void pausar();

void menu_salao(Prato cardapio[], int qnt_pratos);
void menu_cozinha();
void menu_caixa();
void menu_gerencia();

void exibir_cardapio(Prato cardapio[], int qnt_pratos);

int main() {

    Prato cardapio[MAX_PRATOS] = {
        {1, "Prato 1", 10.0},
        {2, "Prato 2", 12.5},
        {3, "Prato 3", 15.0},
        {4, "Prato 4", 8.0},
        {5, "Prato 5", 20.0}
    };
    int qnt_pratos = 5; // Quantidade de pratos cadastrados no cardápio
    int opcao_principal;

    do {

        limpar_ecra();
        printf("===============================\n");
        printf("     SISTEMA DE RESTAURANTE    \n");
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
                limpar_ecra();
                menu_salao(cardapio, qnt_pratos);
                break;
            case 2:
                limpar_ecra();
                menu_cozinha();
                break;
            case 3:
                limpar_ecra();
                menu_caixa();
                break;
            case 4:
                limpar_ecra();
                menu_gerencia();
                break;
            case 0:
                limpar_ecra();
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
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
    while (getchar() != '\n'); // Limpa o buffer de entrada
    getchar(); // Aguarda o Enter
}

void menu_salao(Prato cardapio[], int qnt_pratos) {

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
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 0:
                break;
            default:
                limpar_ecra();
                printf("\nOpcao invalida!\n");
                pausar();
        }

    } while(opcao != 0);

}
void menu_cozinha(){

    int opcao;

    do {

        limpar_ecra();
        printf("===============================\n");
        printf("         MENU DA COZINHA       \n");
        printf("===============================\n");
        printf("1- Pedidos Pendentes (Fila)\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 0:
                break;
            default:
                limpar_ecra();
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
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 2:
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 0:
                break;
            default:
                limpar_ecra();
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
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 2:
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 3:
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 4:
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 0:
                break;
            default:
                limpar_ecra();
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