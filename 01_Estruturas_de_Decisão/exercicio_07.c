#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Para tornar o algoritmo anterior mais genérico, altere-o para que permita ao usuário digitar o salário e a porcentagem de aumento e então mostre o valor do novo salário.

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    float salario, porcentagem_aumento, aumento, salario_final;

    printf("Digite o valor do salário: ");
    scanf("%f", &salario);
    printf("Digite a porcentagem de aumento: ");
    scanf("%f", &porcentagem_aumento);

    aumento = salario * (porcentagem_aumento / 100);
    salario_final = salario + aumento;

    printf("O salário com aumento de %.2f%% é: %.2f\n", porcentagem_aumento, salario_final);

    return 0;
}