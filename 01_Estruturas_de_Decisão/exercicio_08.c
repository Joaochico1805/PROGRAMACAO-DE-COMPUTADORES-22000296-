#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Faça um algoritmo que leia três notas e mostre a soma e a média aritmética delas.

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    float nota1, nota2, nota3, soma, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    soma = nota1 + nota2 + nota3;
    media = soma / 3;

    printf("A soma das notas é: %.2f\n", soma);
    printf("A média aritmética das notas é: %.2f\n", media);

    return 0;
}