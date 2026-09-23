#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Faça um algoritmo que leia os lados de um retângulo e mostre sua área.

int main() {
    
    float base, altura, area;
    printf("Digite a base do retângulo: ");
    scanf("%f", &base);
    printf("Digite a altura do retângulo: ");
    scanf("%f", &altura);

    area = base * altura;

    printf("A área do retângulo é: %.2f\n", area);

    return 0;
}