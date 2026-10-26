//Dinamicamente aloque memória para um array de 5 inteiros. Atribua valores a esses inteiros e, em seguida, libere a memória alocada. Imprima os valores antes e depois da liberação de memória.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

int main(){

    int *array;

    array = (int*) malloc(TAM * sizeof(int));
    if(array == NULL){
        printf("Erro na alocacao!");
        return 1;
    }

    for(int i = 0; i < TAM; i++){
        printf("Digite um valor para array[%d]: ", i);
        scanf("%d", array + i);
    }

    printf("Antes de liberar a memoria: \n");
    for (int i = 0; i < TAM; i++){
        printf("Array[%d]: %d\n", i, array[i]);
    }

    free(array);

    printf("Depois de liberar a memoria: \n");
    for (int i = 0; i < TAM; i++){
        printf("Array[%d]: %d\n", i, array[i]);
    }
    

    return 0;
}