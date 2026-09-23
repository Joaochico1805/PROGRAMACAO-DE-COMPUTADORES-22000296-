#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Faça um algoritmo para ler a base e a altura de um triângulo. Em seguida, escreva a área do mesmo. Obs: área = ( Base * Altura ) / 2

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    float base, altura, area;

    printf("Digite a base do triângulo: ");
    scanf("%f", &base);
    printf("Digite a altura do triângulo: ");
    scanf("%f", &altura);

    area = (base * altura) / 2;

    printf("AArea do triângulo: %.2f\n", area);

    return 0;
}  