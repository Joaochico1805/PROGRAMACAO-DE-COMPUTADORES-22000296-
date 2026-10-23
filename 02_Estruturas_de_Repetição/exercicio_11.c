#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Faça um programa que mostre os divisores de um número inteiro fornecido pelo usuário.

int main() {

    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("Os divisores de %d sao: ", numero);
    for(int i = 1; i <= numero; i++) {
        if(numero % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}