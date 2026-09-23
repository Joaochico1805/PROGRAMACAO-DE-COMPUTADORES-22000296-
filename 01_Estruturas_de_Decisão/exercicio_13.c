#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Faça um algoritmo que leia a média e a frequência de um aluno e mostre se ele foi aprovado. Os critérios de aprovação são: - Se a média for maior ou igual a 7.0 e a frequência maior que 75 então aluno está aprovado. - Se a média for maior que 9.0 o aluno é aprovado com qualquer frequência. - Se a média for maior que 5.0 e frequência maior ou igual a 75 então o aluno fica para recuperação.

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    float media, frequencia;
    printf("Digite a media do aluno: ");
    scanf("%f", &media);
    printf("Digite a frequencia do aluno: ");
    scanf("%f", &frequencia);

    if (media >= 7.0 && frequencia > 75) {
        printf("Aluno aprovado.\n");
    } else if (media > 9.0) {
        printf("Aluno aprovado com qualquer frequencia.\n");
    } else if (media > 5.0 && frequencia >= 75) {
        printf("Aluno fica para recuperacao.\n");
    } else {
        printf("Aluno reprovado.\n");
    }

    return 0;
}