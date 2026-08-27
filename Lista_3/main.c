#include <stdio.h>
#include <stdlib.h>
// Faça um algoritmo que, em um vetor, leia a nota de 10 alunos, calcule a média das notas e escreva a quantidade de alunos com notas maiores que a média.
#define QTD_ALUNOS 10

int main(int argc, char const *argv[])
{
    
    float notas[QTD_ALUNOS], media, s = 0;
    int maior_que_media = 0;

    for (int i = 0; i < QTD_ALUNOS; i++){
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        s = s + notas[i];
    }
    
    media = (s / QTD_ALUNOS);

    for (int i = 0; i < QTD_ALUNOS; i++){
        if (notas[i] > media){
            maior_que_media++;
        }
    }

    printf("\nExistem %d notas maiores que a media %.2f.\n\n", maior_que_media, media);

    return 0;
}