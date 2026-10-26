//Declare uma variável inteira 'num' e um ponteiro para inteiro 'ptr_num'. Atribua um valor a 'num' e faça 'ptr_num' apontar para o endereço de 'num'. Imprima o valor de 'num' e o valor apontado por 'ptr_num'.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 0

int main(){

    int num, *ptr_num = &num;

    printf("Digite um valor para num: ");
    scanf("%d", &num);

    printf("O valor de num eh: %d\n", num);
    printf("O valor apontado por ptr_num eh: %d", *ptr_num);

    return 0;
}