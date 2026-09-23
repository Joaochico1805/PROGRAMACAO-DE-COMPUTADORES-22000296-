#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Faça um algoritmo que leia dois números que o usuário do computador digitará no teclado, some-os e mostre o resultado na tela do computador.

int main() {
    
    int num1, num2, soma;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    soma = num1 + num2;
    
    printf("A soma dos números é: %d\n", soma);

    return 0;
}