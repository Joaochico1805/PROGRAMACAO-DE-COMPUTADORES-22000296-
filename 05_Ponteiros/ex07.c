//Dinamicamente aloque memória para dois arrays de inteiros, 'array1' e 'array2'. Preencha esses arrays com valores e, em seguida, some os elementos correspondentes dos arrays, armazenando o resultado em um terceiro array 'soma'. Imprima os resultados e libere a memória alocada.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

int main(){

    int *array1 = (int*) malloc(TAM * sizeof(int));
    int *array2 = (int*) malloc(TAM * sizeof(int));
    int *soma   = (int*) malloc(TAM * sizeof(int));

    for (int i = 0; i < TAM; i++){

        printf("Digite o valor para array1[%d]: ", i);
        scanf("%d", array1 + i);
        printf("Digite o valor para array2[%d]: ", i);
        scanf("%d", array2 + i);
        soma[i] = array1[i] + array2[i];
    }

    for (int i = 0; i < TAM; i++){
        printf("soma[%d]: %d\n", i, soma[i]);
    }

    free(array1);
    free(array2);
    free(soma);

    return 0;
}