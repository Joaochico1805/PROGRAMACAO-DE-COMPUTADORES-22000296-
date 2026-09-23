// Nome: João Francisco Borges Ferreira
// Matrícula: 25201454
// Curso: Engenharia Eletrônica
// Disciplina: Programação de Computadores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRATOS 50

// --- ESTRUTURAS ---
typedef struct {
    int id;
    char nome[50];
    float preco;
} Prato;

typedef struct Pedido {
    int id_prato;
    int quantidade;
    struct Pedido* prox;
} Pedido;


// --- PROTÓTIPOS DAS FUNÇÕES ---
void limpar_ecra();
void pausar();
void exibir_cardapio(Prato cardapio[], int total_itens);
Pedido* registrar_pedido(Pedido* cabeca, int id, int qtd);
Pedido* fechar_conta(Pedido* cabeca, Prato cardapio[], int total_itens);

void menu_salao(Prato cardapio[], int total_itens, Pedido** mesa);
void menu_cozinha();
void menu_caixa(Pedido** mesa, Prato cardapio[], int total_itens);
void menu_gerencia(Prato cardapio[], int *total_itens);


// --- FUNÇÕES DE UTILIDADE ---
void limpar_ecra() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    int c;
    // Limpa o buffer de entrada residual deixado pelo scanf
    while ((c = getchar()) != '\n' && c != EOF);
    // Aguarda que o utilizador pressione ENTER
    getchar(); 
}


// --- FUNÇÕES DE LÓGICA E PROCESSAMENTO ---
void exibir_cardapio(Prato cardapio[], int total_itens) {
    printf("\n--- CARDAPIO ---\n");
    for (int i = 0; i < total_itens; i++) {
        printf("%d. %s - R$ %.2f\n", cardapio[i].id, cardapio[i].nome, cardapio[i].preco);
    }
    printf("----------------\n");
}

Pedido* registrar_pedido(Pedido* cabeca, int id, int qtd) {
    Pedido* novo_pedido = (Pedido*)malloc(sizeof(Pedido));
    if (novo_pedido == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return cabeca;
    }
    novo_pedido->id_prato = id;
    novo_pedido->quantidade = qtd;
    novo_pedido->prox = cabeca;
    printf("Pedido registrado com sucesso!\n");
    return novo_pedido;
}

Pedido* fechar_conta(Pedido* cabeca, Prato cardapio[], int total_itens) {
    if (cabeca == NULL) {
        printf("\nNenhum pedido na mesa no momento.\n");
        return NULL;
    }
    float total_consumido = 0.0;
    
    FILE *arquivo = fopen("pedidos_encerrados.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return cabeca;
    }
    
    fprintf(arquivo, "--- FECHAMENTO DE CONTA ---\n");
    printf("\n--- RESUMO DA CONTA ---\n");

    Pedido* atual = cabeca;
    Pedido* proximo;
    
    while (atual != NULL) {
        float preco = 0;
        char nome[50] = "";
        
        for (int i = 0; i < total_itens; i++) {
            if (cardapio[i].id == atual->id_prato) {
                preco = cardapio[i].preco;
                strcpy(nome, cardapio[i].nome);
                break;
            }
        }
        
        float sub = preco * atual->quantidade;
        total_consumido += sub;
        
        printf("%dx %s - R$ %.2f\n", atual->quantidade, nome, sub);
        fprintf(arquivo, "%dx %s - R$ %.2f\n", atual->quantidade, nome, sub);
        
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    
    printf("\nTotal a pagar: R$ %.2f\n", total_consumido);
    fprintf(arquivo, "Total Final: R$ %.2f\n\n", total_consumido);
    fclose(arquivo);
    
    printf("Conta fechada e salva no arquivo 'pedidos_encerrados.txt'!\n");
    return NULL; 
}


// --- FUNÇÕES DE INTERFACE (MENUS) ---
void menu_salao(Prato cardapio[], int total_itens, Pedido** mesa) {
    int opcao, id, qtd;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("         MENU DO SALAO         \n");
        printf("===============================\n");
        printf("1- Cardapio\n");
        printf("2- Ver Mesas (Livres/Ocupadas)\n");
        printf("3- Abrir Mesa (Iniciar Atendimento)\n");
        printf("4- Lancar Novo Pedido na Mesa\n");
        printf("5- Ver Parcial de Consumo da Mesa\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                limpar_ecra();
                exibir_cardapio(cardapio, total_itens);
                pausar();
                break;
            case 2:
            case 3:
            case 5:
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
                pausar();
                break;
            case 4:
                limpar_ecra();
                exibir_cardapio(cardapio, total_itens);
                printf("\nDigite o ID do prato: ");
                scanf("%d", &id);
                if (id >= 1 && id <= total_itens) {
                    printf("Digite a quantidade: ");
                    scanf("%d", &qtd);
                    if(qtd > 0) {
                        *mesa = registrar_pedido(*mesa, id, qtd);
                    } else {
                        printf("Quantidade invalida!\n");
                    }
                } else {
                    printf("Prato nao encontrado!\n");
                }
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

void menu_cozinha() {
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("         MENU DA COZINHA       \n");
        printf("===============================\n");
        printf("1- Listar Pedidos Pendentes (Fila)\n");
        printf("2- Iniciar Preparo\n");
        printf("3- Marcar como 'Pronto'\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if(opcao >= 1 && opcao <= 3) {
            limpar_ecra();
            printf("\n[Funcionalidade em desenvolvimento]\n");
            pausar();
        } else if (opcao != 0) {
            printf("\nOpcao invalida!\n");
            pausar();
        }
    } while (opcao != 0);
}

void menu_caixa(Pedido** mesa, Prato cardapio[], int total_itens) {
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("          MENU DO CAIXA        \n");
        printf("===============================\n");
        printf("1- Fechar Conta de uma Mesa\n");
        printf("2- Registrar Pagamento\n");
        printf("3- Exibir Faturamento do Turno\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                limpar_ecra();
                *mesa = fechar_conta(*mesa, cardapio, total_itens);
                pausar();
                break;
            case 2:
            case 3:
                limpar_ecra();
                printf("\n[Funcionalidade em desenvolvimento]\n");
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

void menu_gerencia(Prato cardapio[], int *total_itens) {
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("    MENU DA GERENCIA (ADMIN)   \n");
        printf("===============================\n");
        printf("1- Cadastrar Item no Cardapio\n");
        printf("2- Remover Item do Cardapio\n");
        printf("3- Salvar Cardapio em Arquivo\n");
        printf("4- Carregar Cardapio do Arquivo\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao >= 1 && opcao <= 4) {
            limpar_ecra();
            printf("\n[Funcionalidade em desenvolvimento]\n");
            pausar();
        } else if (opcao != 0) {
            printf("\nOpcao invalida!\n");
            pausar();
        }
    } while (opcao != 0);
}


// --- FUNÇÃO PRINCIPAL ---
int main() {
    Prato cardapio[MAX_PRATOS] = {
        {1, "X-Bacon", 25.50},
        {2, "Porcao de Fritas", 18.00},
        {3, "Refrigerante Lata", 6.00},
        {4, "Suco Natural", 9.50},
        {5, "Sobremesa do Dia", 12.00}
    };
    int qtd_pratos = 5;
    Pedido* mesa_unica = NULL; 
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
                menu_salao(cardapio, qtd_pratos, &mesa_unica);
                break;
            case 2:
                menu_cozinha();
                break;
            case 3:
                menu_caixa(&mesa_unica, cardapio, qtd_pratos);
                break;
            case 4:
                menu_gerencia(cardapio, &qtd_pratos);
                break;
            case 0:
                limpar_ecra();
                printf("\nEncerrando o sistema...\n");
                while(mesa_unica != NULL) {
                    Pedido* temp = mesa_unica;
                    mesa_unica = mesa_unica->prox;
                    free(temp);
                }
                break;
            default:
                printf("\nOperacao invalida!\n");
                pausar();
        }
    } while (opcao_principal != 0);

    return 0;
}