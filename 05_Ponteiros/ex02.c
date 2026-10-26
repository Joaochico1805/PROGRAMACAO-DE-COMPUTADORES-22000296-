//Implemente um algoritmo que recebe dois ponteiros para inteiros e troca os valores das variáveis apontadas por esses ponteiros.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 0

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
};

int main(){

    int x, y;

    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    printf("\nTrocando valores...\n");
    troca(&x, &y);
    printf("Valores trocados.\n\n");

    printf("O valor de x: %d\n", x);
    printf("O valor de y: %d\n", y);

    return 0;
}