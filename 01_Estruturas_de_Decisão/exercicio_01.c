#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Faça um algoritmo que leia dois números e mostre se são iguais. Se não forem iguais, mostre o maior.

int main() {
    
    int num1, num2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);     
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    if (num1 == num2) {
        printf("Os números são iguais.\n");
    } else if (num1 > num2) {
        printf("O maior número e: %d\n", num1);
    } else {
        printf("O maior número e: %d\n", num2);
    }

    return 0;
}