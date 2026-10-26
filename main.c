//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

int main(){

    int *array1 = (int*) malloc(TAM * sizeof(int));
    int *array2 = (int*) malloc(TAM * sizeof(int));
    int *arraysoma = (int*) malloc(TAM * sizeof(int));

    if (array1 == NULL || array2 == NULL || arraysoma == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    for(int i = 0; i < TAM; i++){
        printf("Digite o valor do array1[%d]: ", i);
        scanf("%d", array1 + i);

        printf("Digite o valor do array2[%d]: ", i);
        scanf("%d", array2 + i);

        arraysoma[i] = array1[i] + array2[i];
    }

    printf("\n--- Resultados da Soma ---\n");
    for(int i = 0; i < TAM; i++){
        printf("Soma na posicao [%d]: %d + %d = %d\n", i, array1[i], array2[i], arraysoma[i]);
    }

    free(array1);
    free(array2);
    free(arraysoma);

    return 0;
}