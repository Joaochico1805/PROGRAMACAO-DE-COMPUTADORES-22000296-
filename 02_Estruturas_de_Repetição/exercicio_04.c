#include <stdio.h>
#include <stdlib.h>

#include <string.h>

//Faça um algoritmo para ler base e altura de 50 triângulos e imprimir a sua área.

int main() {

    float base, altura, area;

    for(int i = 0; i < 50; i++) {
        printf("Digite a base do triângulo %d: ", i + 1);
        scanf("%f", &base);
        printf("Digite a altura do triângulo %d: ", i + 1);
        scanf("%f", &altura);
        area = (base * altura) / 2;
        printf("A área do triângulo %d é: %.2f\n", i + 1, area);
    }

    return 0;
}