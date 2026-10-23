//
#include <stdio.h> 
#include <stdlib.h>

void limpar_ecra();

int main(){
    limpar_ecra();
    
    int n, *ptr;
    ptr = (int*) malloc(n * sizeof(int));

    printf("Digite o numero de pacotes a ser recebidos: ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Quantidade Invalida!\n");
        return 1;
    }

    ptr = (int *) malloc(n * sizeof(int));

    if(ptr == NULL){
        printf("Erro: Memoria insuficiente.\n");
        return 1;
    }

    

    free(ptr);
    ptr = NULL;
    
}

void limpar_ecra() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
