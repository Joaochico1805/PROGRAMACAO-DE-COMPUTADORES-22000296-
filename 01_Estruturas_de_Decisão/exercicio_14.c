#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Faça um programa que leia um número que represente um determinado mês do ano. Após a leitura escreva por extenso qual o mês lido. Caso o número digitado não esteja na faixa de 1 até 12 e escreva uma mensagem informando o usuário do erro da digitação. Observação: use estrutura switch.

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    int mes;

    printf("Digite o número do mês (1 a 12): ");
    scanf("%d", &mes);  

    switch(mes){
        case 1:
            printf("Janeiro\n");
            break;
        case 2:
            printf("Fevereiro\n");
            break;
        case 3:
            printf("Março\n");
            break;
        case 4:
            printf("Abril\n");
            break;
        case 5:
            printf("Maio\n");
            break;
        case 6:
            printf("Junho\n");
            break;
        case 7:
            printf("Julho\n");
            break;
        case 8:
            printf("Agosto\n");
            break;
        case 9:
            printf("Setembro\n");
            break;
        case 10:
            printf("Outubro\n");
            break;
        case 11:
            printf("Novembro\n");
            break;
        case 12:
            printf("Dezembro\n");
            break;
        default:
            printf("Mês inválido.\n");
    }

    return 0;
}