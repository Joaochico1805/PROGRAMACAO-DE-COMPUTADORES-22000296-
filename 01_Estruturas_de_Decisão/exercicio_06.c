#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Faça um algoritmo que leia o valor de um salário e mostre este salário com um aumento de 20%. 

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    float salario, aumento, salario_final;

    printf("Digite o valor do salário: ");
    scanf("%f", &salario);

    aumento = salario * 0.20;
    salario_final = salario + aumento;

    printf("O salário com aumento de 20%% é: %.2f\n", salario_final);

    return 0;
}