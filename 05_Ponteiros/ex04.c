//Crie uma matriz de 3x3 e preencha com valores. Utilizando ponteiros, imprima os elementos da matriz e calcule a soma de todos os elementos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

int main(){

    int matriz[TAM][TAM] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int *ptr = (int*)matriz, soma = 0;

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            printf("%d ", *ptr);
            soma += *ptr;
            ptr++;
        }
        printf("\n");
    }

    printf("A soma de todos os elementos eh: %d", soma);

    return 0;
}