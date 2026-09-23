#include <stdio.h>
#include <stdlib.h>

#include <string.h>

//Dado um conjunto de n registros cada registro contendo um valor real, faça um algoritmo que calcule a média dos valores maiores que 4.

int main() {

    int n;
    float valores[100];
    float soma = 0, media;
    int count = 0;

    printf("Digite o número de registros: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &valores[i]);
        if(valores[i] > 4) {
            soma += valores[i];
            count++;
        }
    }

    if(count > 0) {
        media = soma / count;
        printf("A média dos valores maiores que 4 é: %.2f\n", media);
    } else {
        printf("Nenhum valor é maior que 4.\n");
    }

    return 0;
}