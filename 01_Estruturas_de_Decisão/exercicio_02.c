#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Faça um algoritmo que leia um número e mostre se ele é positivo, negativo ou zero. 

int main() {
    
    int numero;
   
    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O número é positivo.\n");
    } else if (numero < 0) {
        printf("O número é negativo.\n");
    } else {
        printf("O número é zero.\n");
    }

    return 0;
}