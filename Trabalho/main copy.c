// Nome: João Francisco Borges Ferreira
// Matrícula: 25201454
// Curso: Engenharia Eletrônica
// Disciplina: Programação de Computadores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRATOS 20
#define LINHAS_SALAO 3
#define COLUNAS_SALAO 3
#define TOTAL_MESAS (LINHAS_SALAO * COLUNAS_SALAO)

typedef struct {
    int id;
    char nome[50];
    float preco;
} Prato;

typedef struct {
    int numero_mesa;
    int id_prato;
    int qtd;
} Pedido;

typedef struct NoPedido {
    Pedido dados;
    struct NoPedido* proximo;
} NoPedido;

// Prototipos das funcoes auxiliares
void limpar_ecra();
void pausar();

// Prototipos dos menus dos setores
void menu_salao(Prato cardapio[], int qnt_pratos, NoPedido** fila_pedidos, float comandas[LINHAS_SALAO][COLUNAS_SALAO]);
void menu_cozinha(NoPedido** fila_pedidos, Prato cardapio[], int qnt_pratos);
void menu_caixa(float comandas[LINHAS_SALAO][COLUNAS_SALAO], float *faturamento_turno, int *comandas_fechadas);
void menu_gerencia(Prato cardapio[], int *qnt_pratos);

// Prototipos das operacoes do sistema
void exibir_cardapio(Prato cardapio[], int qnt_pratos);
void exibir_mapa_mesas(float comandas[LINHAS_SALAO][COLUNAS_SALAO]);
float buscar_preco_prato(Prato cardapio[], int qnt_pratos, int id_busca);

void enfileirar_pedido(NoPedido** fila, Pedido p);
void desenfileirar_pedido(NoPedido** fila);
void liberar_fila(NoPedido** fila);

void cadastrar_prato(Prato cardapio[], int *qnt_pratos);
void remover_prato(Prato cardapio[], int *qnt_pratos);
void salvar_cardapio(Prato cardapio[], int qnt_pratos);
void carregar_cardapio(Prato cardapio[], int *qnt_pratos);

int main() {
    Prato cardapio[MAX_PRATOS] = {
        {1, "Prato Feito Executivo", 22.00},
        {2, "Bauru", 35.50},
        {3, "Xis Tradicional", 18.00},
        {4, "Porcao de Fritas", 15.00},
        {5, "Refrigerante Lata", 6.50}
    };
    int qnt_pratos = 5;
    int opcao_principal;

    // Matriz bidimensional representando as 9 mesas do salao (3x3) inicializada com 0.0
    float comandas[LINHAS_SALAO][COLUNAS_SALAO] = {0.0};

    // Acumulador e contador do turno para o Caixa
    float faturamento_turno = 0.0;
    int comandas_fechadas = 0;

    // Inicializacao do ponteiro da lista encadeada sem cabeca (Fila vazia)
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
                menu_salao(cardapio, qnt_pratos, &fila_pedidos, comandas);
                break;
            case 2:
                menu_cozinha(&fila_pedidos, cardapio, qnt_pratos);
                break;
            case 3:
                menu_caixa(comandas, &faturamento_turno, &comandas_fechadas);
                break;
            case 4:
                menu_gerencia(cardapio, &qnt_pratos);
                break;
            case 0:
                limpar_ecra();
                liberar_fila(&fila_pedidos);
                printf("\nMemoria liberada. Encerrando o sistema...\n");
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

float buscar_preco_prato(Prato cardapio[], int qnt_pratos, int id_busca) {
    for (int i = 0; i < qnt_pratos; i++) {
        if (cardapio[i].id == id_busca) {
            return cardapio[i].preco;
        }
    }
    return -1.0;
}

// Exibe a matriz bidimensional mostrando apenas o numero da mesa (1 a 9)
void exibir_mapa_mesas(float comandas[LINHAS_SALAO][COLUNAS_SALAO]) {
    int num_mesa = 1;
    printf("\n---------------- MAPA DE MESAS DO SALAO ----------------\n");
    for (int i = 0; i < LINHAS_SALAO; i++) {
        for (int j = 0; j < COLUNAS_SALAO; j++) {
            if (comandas[i][j] == 0.0) {
                printf("[Mesa %d: LIVRE   ]  ", num_mesa);
            } else {
                printf("[Mesa %d: R$%6.2f]  ", num_mesa, comandas[i][j]);
            }
            num_mesa++;
        }
        printf("\n");
    }
    printf("--------------------------------------------------------\n");
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

    printf("\nPedido da Mesa %d - Prato ID %d (Qtd: %d) finalizado e entregue!\n",
           no_remover->dados.numero_mesa,
           no_remover->dados.id_prato, no_remover->dados.qtd);

    free(no_remover);
    no_remover = NULL;
}

void liberar_fila(NoPedido** fila) {
    NoPedido* aux;
    while (*fila != NULL) {
        aux = *fila;
        *fila = (*fila)->proximo;
        free(aux);
        aux = NULL;
    }
}

void menu_salao(Prato cardapio[], int qnt_pratos, NoPedido** fila_pedidos, float comandas[LINHAS_SALAO][COLUNAS_SALAO]) {
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("          MENU DO SALAO        \n");
        printf("===============================\n");
        printf("1- Ver Cardapio\n");
        printf("2- Ver Mapa de Mesas\n");
        printf("3- Lancar Pedido\n");
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
                exibir_mapa_mesas(comandas);
                pausar();
                break;
            case 3: {
                limpar_ecra();
                exibir_mapa_mesas(comandas);
                exibir_cardapio(cardapio, qnt_pratos);

                Pedido novo_pedido;
                printf("\nInforme o numero da Mesa (1 a %d): ", TOTAL_MESAS);
                scanf("%d", &novo_pedido.numero_mesa);

                // Validacao do numero da mesa usando operador logico (||) e relacionais
                if (novo_pedido.numero_mesa < 1 || novo_pedido.numero_mesa > TOTAL_MESAS) {
                    printf("\nErro: Numero de mesa invalido!\n");
                    pausar();
                    break;
                }

                printf("Digite o ID do prato: ");
                scanf("%d", &novo_pedido.id_prato);
                printf("Digite a quantidade: ");
                scanf("%d", &novo_pedido.qtd);

                float preco_unitario = buscar_preco_prato(cardapio, qnt_pratos, novo_pedido.id_prato);

                // Validacao do prato e quantidade usando operador logico &&
                if (preco_unitario > 0.0 && novo_pedido.qtd > 0) {
                    enfileirar_pedido(fila_pedidos, novo_pedido);

                    // Converte o numero da mesa (1 a 9) para os indices da matriz 3x3
                    int lin = (novo_pedido.numero_mesa - 1) / COLUNAS_SALAO;
                    int col = (novo_pedido.numero_mesa - 1) % COLUNAS_SALAO;

                    comandas[lin][col] += (preco_unitario * novo_pedido.qtd);
                    printf("\nPedido enviado para a cozinha e lancado na Mesa %d!\n", novo_pedido.numero_mesa);
                } else {
                    printf("\nErro: ID de prato inexistente ou quantidade invalida!\n");
                }
                pausar();
                break;
            }
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
    } while(opcao != 0);
}

void menu_cozinha(NoPedido** fila_pedidos, Prato cardapio[], int qnt_pratos) {
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
            case 1: {
                limpar_ecra();
                printf("--- Fila de Pedidos Pendentes (FIFO) ---\n");
                NoPedido* aux = *fila_pedidos;
                if (aux == NULL) {
                    printf("A fila esta vazia.\n");
                } else {
                    int pos = 1;
                    while (aux != NULL) {
                        // Busca o nome do prato correspondente ao ID
                        char nome_prato[50] = "Desconhecido";
                        for (int i = 0; i < qnt_pratos; i++) {
                            if (cardapio[i].id == aux->dados.id_prato) {
                                strcpy(nome_prato, cardapio[i].nome);
                                break;
                            }
                        }

                        printf("%d. Mesa %d | Prato: %s (Qtd: %d)\n",
                               pos++, aux->dados.numero_mesa,
                               nome_prato, aux->dados.qtd);
                        aux = aux->proximo;
                    }
                }
                pausar();
                break;
            }
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

void menu_caixa(float comandas[LINHAS_SALAO][COLUNAS_SALAO], float *faturamento_turno, int *comandas_fechadas) {
    int opcao;
    do {
        limpar_ecra();
        printf("===============================\n");
        printf("         MENU DO CAIXA         \n");
        printf("===============================\n");
        printf("Faturamento Atual do Turno: R$ %.2f (%d comandas pagas)\n", *faturamento_turno, *comandas_fechadas);
        printf("-------------------------------\n");
        printf("1- Fechar Comanda de Mesa\n");
        printf("2- Fechar Turno (Salvar Relatorio em Arquivo)\n");
        printf("0- Voltar ao Menu Principal\n");
        printf("===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                limpar_ecra();
                exibir_mapa_mesas(comandas);
                int num_mesa;
                printf("\nInforme o numero da Mesa para fechar a conta (1 a %d): ", TOTAL_MESAS);
                scanf("%d", &num_mesa);

                if (num_mesa >= 1 && num_mesa <= TOTAL_MESAS) {
                    int lin = (num_mesa - 1) / COLUNAS_SALAO;
                    int col = (num_mesa - 1) % COLUNAS_SALAO;

                    if (comandas[lin][col] > 0.0) {
                        float total_mesa = comandas[lin][col];
                        printf("\nValor total da Mesa %d: R$ %.2f\n", num_mesa, total_mesa);
                        *faturamento_turno = *faturamento_turno + total_mesa; // Acumulador
                        (*comandas_fechadas)++; // Contador
                        comandas[lin][col] = 0.0; // Libera a mesa na matriz
                        printf("Pagamento registrado com sucesso! Mesa %d liberada.\n", num_mesa);
                    } else {
                        printf("\nA Mesa %d esta livre (nao possui valores em aberto).\n", num_mesa);
                    }
                } else {
                    printf("\nErro: Numero de mesa invalido!\n");
                }
                pausar();
                break;
            }
            case 2: {
                limpar_ecra();
                float pendente_mesas = 0.0;
                for (int i = 0; i < LINHAS_SALAO; i++) {
                    for (int j = 0; j < COLUNAS_SALAO; j++) {
                        pendente_mesas += comandas[i][j];
                    }
                }

                FILE *fp = fopen("relatorio_caixa.txt", "a");
                if (fp == NULL) {
                    printf("\nErro ao abrir o arquivo de relatorio!\n");
                } else {
                    fprintf(fp, "=== FECHAMENTO DE TURNO ===\n");
                    fprintf(fp, "Comandas pagas: %d\n", *comandas_fechadas);
                    fprintf(fp, "Faturamento recebido: R$ %.2f\n", *faturamento_turno);
                    fprintf(fp, "Saldo pendente nas mesas: R$ %.2f\n", pendente_mesas);
                    fprintf(fp, "===========================\n\n");
                    fclose(fp);

                    printf("--- Relatorio do Turno ---\n");
                    printf("Comandas Pagas: %d\n", *comandas_fechadas);
                    printf("Faturamento Total: R$ %.2f\n", *faturamento_turno);
                    printf("Pendente em Mesas Abertas: R$ %.2f\n", pendente_mesas);
                    printf("\nDados gravados com sucesso em 'relatorio_caixa.txt'!\n");
                }
                pausar();
                break;
            }
            case 0:
                break;
            default:
                printf("\nOpcao invalida!\n");
                pausar();
        }
    } while (opcao != 0);
}

void menu_gerencia(Prato cardapio[], int *qnt_pratos) {
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
                cadastrar_prato(cardapio, qnt_pratos);
                pausar();
                break;
            case 2:
                limpar_ecra();
                remover_prato(cardapio, qnt_pratos);
                pausar();
                break;
            case 3:
                limpar_ecra();
                salvar_cardapio(cardapio, *qnt_pratos);
                pausar();
                break;
            case 4:
                limpar_ecra();
                carregar_cardapio(cardapio, qnt_pratos);
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

void cadastrar_prato(Prato cardapio[], int *qnt_pratos) {
    if (*qnt_pratos >= MAX_PRATOS) {
        printf("\nErro: O cardapio atingiu o limite maximo de %d pratos!\n", MAX_PRATOS);
        return;
    }

    Prato novo;
    int flag_duplicado = 0;

    printf("--- Cadastrar Novo Prato ---\n");
    printf("Digite o ID do prato: ");
    scanf("%d", &novo.id);

    for (int i = 0; i < *qnt_pratos; i++) {
        if (cardapio[i].id == novo.id) {
            flag_duplicado = 1;
            break;
        }
    }

    if (flag_duplicado == 1 || novo.id <= 0) {
        printf("\nErro: ID invalido ou ja existente no cardapio!\n");
        return;
    }

    printf("Digite o nome do prato: ");
    scanf(" %49[^\n]", novo.nome);

    printf("Digite o preco do prato (R$): ");
    scanf("%f", &novo.preco);

    if (!(novo.preco > 0.0)) {
        printf("\nErro: O preco deve ser maior que zero!\n");
        return;
    }

    cardapio[*qnt_pratos] = novo;
    (*qnt_pratos)++;

    printf("\nPrato '%s' cadastrado com sucesso!\n", novo.nome);
}

void remover_prato(Prato cardapio[], int *qnt_pratos) {
    if (*qnt_pratos == 0) {
        printf("\nO cardapio esta vazio!\n");
        return;
    }

    exibir_cardapio(cardapio, *qnt_pratos);

    int id_remover;
    int indice_encontrado = -1;

    printf("\nDigite o ID do prato que deseja remover: ");
    scanf("%d", &id_remover);

    for (int i = 0; i < *qnt_pratos; i++) {
        if (cardapio[i].id == id_remover) {
            indice_encontrado = i;
            break;
        }
    }

    if (indice_encontrado == -1) {
        printf("\nErro: Prato com ID %d nao encontrado!\n", id_remover);
        return;
    }

    for (int i = indice_encontrado; i < (*qnt_pratos) - 1; i++) {
        cardapio[i] = cardapio[i + 1];
    }

    (*qnt_pratos)--;
    printf("\nPrato removido com sucesso!\n");
}

void salvar_cardapio(Prato cardapio[], int qnt_pratos) {
    FILE *fp = fopen("cardapio.txt", "w");
    if (fp == NULL) {
        printf("\nErro ao abrir o arquivo para escrita!\n");
        return;
    }

    for (int i = 0; i < qnt_pratos; i++) {
        fprintf(fp, "%d;%s;%.2f\n", cardapio[i].id, cardapio[i].nome, cardapio[i].preco);
    }

    fclose(fp);
    printf("\nCardapio salvo com sucesso em 'cardapio.txt' (%d itens)!\n", qnt_pratos);
}

void carregar_cardapio(Prato cardapio[], int *qnt_pratos) {
    FILE *fp = fopen("cardapio.txt", "r");
    if (fp == NULL) {
        printf("\nErro: Arquivo 'cardapio.txt' nao encontrado! Salve um cardapio primeiro.\n");
        return;
    }

    int contador = 0;
    while (contador < MAX_PRATOS &&
           fscanf(fp, "%d;%49[^;];%f\n", &cardapio[contador].id, cardapio[contador].nome, &cardapio[contador].preco) == 3) {
        contador++;
    }

    *qnt_pratos = contador;
    fclose(fp);
    printf("\nCardapio carregado com sucesso! (%d itens lidos de 'cardapio.txt').\n", *qnt_pratos);
}

void exibir_cardapio(Prato cardapio[], int qnt_pratos) {
    printf("\n===============================\n");
    printf("           CARDAPIO            \n");
    printf("===============================\n");
    for (int i = 0; i < qnt_pratos; i++) {
        printf("%d - %-22s - R$ %6.2f\n", cardapio[i].id, cardapio[i].nome, cardapio[i].preco);
    }
    printf("===============================\n");
}