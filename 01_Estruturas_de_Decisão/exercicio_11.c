#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Uma empresa tem para um determinado funcionário uma ficha contendo o nome, número de horas trabalhadas e o número de dependentes de um funcionário. Considerando que: a) a empresa paga 12 reais por hora e 40 reais por dependentes. b) sobre o salário são feito descontos de 8,5% para o INSS e 5% para IR. Faça um algoritmo para ler o Nome, número de horas trabalhadas e número de dependentes de um funcionário. Após a leitura, escreva qual o Nome, salário bruto, os valores descontados para cada tipo de imposto e finalmente qual o salário líquido do funcionário.

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    char nome[100];
    int horas_trabalhadas, dependentes;
    float salario_bruto, inss, ir, salario_liquido;

    printf("Digite o nome do funcionário: ");
    scanf("%s", nome);
    printf("Digite o número de horas trabalhadas: ");
    scanf("%d", &horas_trabalhadas);
    printf("Digite o número de dependentes: ");
    scanf("%d", &dependentes);

    salario_bruto = horas_trabalhadas * 12 + dependentes * 40;
    inss = salario_bruto * 0.085;
    ir = salario_bruto * 0.05;
    salario_liquido = salario_bruto - inss - ir;

    printf("Nome: %s\n", nome);
    printf("Salário bruto: %.2f\n", salario_bruto);
    printf("Desconto INSS: %.2f\n", inss);
    printf("Desconto IR: %.2f\n", ir);
    printf("Salário líquido: %.2f\n", salario_liquido);

    return 0;
}