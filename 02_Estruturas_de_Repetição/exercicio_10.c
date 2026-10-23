#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define funcionario 10

//

int main() {

    int horas, dependentes, id;
    float sbruto, sliquido, inss, ir; 

    for(int i = 0; i < funcionario; i++) {

        printf("Digite o numero do id: ");
        scanf("%d", &id);
        printf("Digite o numero de dependentes: ");
        scanf("%d", &dependentes);
        printf("Digite a quantidade de horas trabalhadas: ");
        scanf("%d", &horas);

        sbruto = (12 * horas) + (40 * dependentes);
        inss = 0.085 * sbruto;
        ir = 0.05 * sbruto;
        sliquido = sbruto - (inss + ir);

        printf("===================================\n");
        printf("id: %d\n", id);
        printf("Desconto de INSS: %.2f\n", inss);
        printf("Desconto de IR: %.2f\n", ir);
        printf("Salario liquido: %.2f\n", sliquido);
        printf("===================================\n");

    }
    
    return 0;
}