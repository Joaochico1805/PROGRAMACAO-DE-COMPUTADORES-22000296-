//Crie um programa que recebe uma string como parâmetro e retorna o número de caracteres nela. Utilize ponteiros para percorrer a string.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int main(){

    char string[TAM];
    int total = 0;

    printf("Digite uma string: ");
    fgets(string, TAM, stdin);

    for(char *ptr = (char*)string; *ptr != '\0'; ptr++){
        if(*ptr != '\n'){
            total++;
        }
    }

    printf("A string possui %d caracteres.", total);

    return 0;
}