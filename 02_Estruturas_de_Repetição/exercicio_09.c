#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//

int main() {

    int num;
    int qtdPares = 0, qtdImpares = 0;
    int somaPares = 0, somaImpares = 0;
    float mediaImpares = 0.0; 

    for (int i = 0; i < 10; i++) {

        printf("Digite um numero: ");
        scanf("%d", &num);

        if(num % 2 == 0){

            qtdPares++;
            somaPares += num;

        }else{

            qtdImpares++;
            somaImpares += num;

        }

    }

    printf("============================\n");
    printf("Numeros pares: %d\n", qtdPares);
    printf("Numeros impares: %d\n", qtdImpares);
    printf("Soma dos pares: %d\n", somaImpares);
    printf("Media dos impares: %.2f\n", (float)somaImpares/qtdImpares);
    printf("============================\n");
    
    return 0;
}