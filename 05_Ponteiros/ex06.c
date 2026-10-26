//Dinamicamente aloque memória para duas strings, 'nome' e 'sobrenome'. Preencha essas strings com valores e, em seguida, concatene-as para formar o nome completo. Por fim, libere a memória alocada.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int main(){

    char *tmp;
    char *nome = (char*) malloc(TAM * sizeof(char));
    char *sobrenome = (char*) malloc(TAM * sizeof(char));
    if(nome == NULL || sobrenome == NULL){
        printf("Erro na alocacao!");
        return 1;
    }


    printf("Digite seu nome: ");
    fgets(nome, TAM, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    tmp = (char*) realloc(nome, (strlen(nome) + 1) * sizeof(char));
    if(tmp != NULL) nome = tmp;

    printf("Digite seu sobrenome: ");   
    fgets(sobrenome, TAM, stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';
    tmp = (char*) realloc(sobrenome, (strlen(sobrenome) + 1) * sizeof(char));
    if(tmp != NULL) sobrenome = tmp;

    char *nome_completo = (char*) malloc((strlen(nome) + strlen(sobrenome) + 2) * sizeof(char));
    if(nome_completo == NULL){
        printf("Erro na alocacao!");
        return 1;
    }


    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome);

    printf("O seu nome completo eh: %s", nome_completo);

    free(nome);
    free(sobrenome);
    free(nome_completo);

    return 0;
}