#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dado uma série de 20 valores reais, faça um algoritmo que calcule e escreva a média aritmética destes valores, entretanto se a média obtida for maior que 8 deverá ser atribuída 10 para a média.

int main() {

    float valores[20];
    float soma = 0, media;

    for(int i = 0; i < 20; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &valores[i]);
        soma += valores[i];
    }

    media = soma / 20;

    if(media > 8) {
        media = 10;
    }

    printf("A média aritmética é: %.2f\n", media);

    return 0;
}