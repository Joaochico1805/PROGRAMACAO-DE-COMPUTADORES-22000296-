#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Faça um programa que mostre os divisores de números inteiros fornecidos pelo usuário. Encerrar o programa quando o usuário fornecer o número zero.

int main() {

    int numero;

    do {
        printf("Digite um numero inteiro (0 para sair): ");
        scanf("%d", &numero);

        if (numero != 0) {
            printf("Divisores de %d: ", numero);
            for (int i = 1; i <= numero; i++) {
                if (numero % i == 0) {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }

    } while (numero != 0);
    
    return 0;
}