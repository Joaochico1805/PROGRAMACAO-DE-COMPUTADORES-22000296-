#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//O preço de um automóvel é calculado pela soma do preço de fábrica com o preço dos impostos (45% do preço de fábrica) e a percentagem do revendedor (28% do preço de fábrica). Faça um algoritmo que leia o nome do automóvel e o preço de fábrica e imprima o nome do automóvel e o preço final.

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    char nome_carro[100];
    float preco_fabrica, preco_impostos, preco_revendedor, preco_final;

    printf("Digite o nome do automóvel: ");
    scanf("%s", nome_carro);
    printf("Digite o preço de fábrica: ");
    scanf("%f", &preco_fabrica);

    preco_impostos = preco_fabrica * 0.45;
    preco_revendedor = preco_fabrica * 0.28;
    preco_final = preco_fabrica + preco_impostos + preco_revendedor;

    printf("Nome do automóvel: %s\n", nome_carro);
    printf("Preço final: %.2f\n", preco_final);

    return 0;
}