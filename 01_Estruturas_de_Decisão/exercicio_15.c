#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Faça um programa leia o nome por extenso de um Mes (janeiro, fevereiro, março...) e informe o número de dias que ele tem. Observação: use estrutura switch e tipo de variável caracter.

int main() {
    
    char mes[20];

    printf("Digite o nome do Mes: ");
    fgets(mes, sizeof(mes), stdin);
    mes[strcspn(mes, "\n")] = 0; // Remove o caractere de nova linha do final da string
    switch (mes[0]) {
        case 'j':
        case 'J':
            if (strcmp(mes, "janeiro") == 0 || strcmp(mes, "Janeiro") == 0) {
                printf("Janeiro tem 31 dias.\n");
            } else if (strcmp(mes, "junho") == 0 || strcmp(mes, "Junho") == 0) {
                printf("Junho tem 30 dias.\n");
            } else if (strcmp(mes, "julho") == 0 || strcmp(mes, "Julho") == 0) {
                printf("Julho tem 31 dias.\n");
            } else {
                printf("Mes invalido.\n");
            }
            break;
        case 'f':
        case 'F':
            if (strcmp(mes, "fevereiro") == 0 || strcmp(mes, "Fevereiro") == 0) {
                printf("Fevereiro tem 28 ou 29 dias.\n");
            } else {
                printf("Mes invalido.\n");
            }
            break;
        case 'm':
        case 'M':
            if (strcmp(mes, "março") == 0 || strcmp(mes, "Março") == 0) {
                printf("Março tem 31 dias.\n");
            } else if (strcmp(mes, "maio") == 0 || strcmp(mes, "Maio") == 0) {
                printf("Maio tem 31 dias.\n");
            } else {
                printf("Mes invalido.\n");
            }
            break;
        case 'a':
        case 'A':
            if (strcmp(mes, "abril") == 0 || strcmp(mes, "Abril") == 0) {
                printf("Abril tem 30 dias.\n");
            } else if (strcmp(mes, "agosto") == 0 || strcmp(mes, "Agosto") == 0) {
                printf("Agosto tem 31 dias.\n");
            } else {
                printf("Mes invalido.\n");
            }
            break;
        case 's':
        case 'S':
            if (strcmp(mes, "setembro") == 0 || strcmp(mes, "Setembro") == 0) {
                printf("Setembro tem 30 dias.\n");
            } else {
                printf("Mes invalido.\n");
            }
            break;
        default:
            printf("Mes invalido.\n");
    }

    return 0;
}