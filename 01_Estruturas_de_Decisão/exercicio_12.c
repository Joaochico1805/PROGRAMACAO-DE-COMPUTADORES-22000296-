#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Faça um algoritmo que leia 3 números e diga se podem ser lados de um triângulo. Observe: A, B e C são lados de um triângulo se: A < (B+C) e B < (C+A) e C < (A+B).

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    float A, B, C;

    printf("Digite o valor de A: ");
    scanf("%f", &A);
    printf("Digite o valor de B: ");
    scanf("%f", &B);
    printf("Digite o valor de C: ");
    scanf("%f", &C);

    if (A < (B + C) && B < (C + A) && C < (A + B)) {
        printf("Os valores podem ser lados de um triângulo.\n");
    } else {
        printf("Os valores não podem ser lados de um triângulo.\n");
    }

    return 0;
}