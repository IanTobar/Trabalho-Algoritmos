#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "arvore234.h"
#include "arvoreRN.h"

int contaLinhas(FILE *entrada) { //conta quantas linhas existem em um arquivo composto por numeros inteiros
    int linhas = 0, aux;
    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("Arquivo inexistente\n");
        return;
    }
    while (!(feof(entrada))) { //percorre o arquivo ate o EOF 
        fscanf(entrada, "%d\n", &aux); //le em um auxiliar
        linhas++; //incrementa o contador de linhas
    }
    fclose(entrada); //fecha o arquivo
    return linhas; // retorna o numero de linhas
}

int *leDados() { //le dados de um arquivo de inteiros 
    FILE *entrada;
    int *aux, i = 0;
    entrada = fopen("entrada.txt", "r"); //abre o arquivo
    if (entrada == NULL) { //verifica existencia do arquivo
        printf("Arquivo inexistente\n");
        return;
    }
    aux = (int*) malloc((contaLinhas(entrada)) * sizeof (int)); //aloca o vetor auxiliar com base no return da func contaLinhas
    while (!(feof(entrada))) { //loop para percorrer o arquivo ate o EOF
        fscanf(entrada, "%d\n", &aux[i]); //le dados do arquivo para o vetor auxiliar
        i++; //incrementa variavel para acessar as posicoews do vetor
    }
    return aux; //retorna o vetor
}

int printaVet(int *vet) {
    int i, tamVet;
    tamVet = 20;
    for (i = 0; i < tamVet; i++) {
        printf("%d ", vet[i]);
    }

}

//Percorre a Ã¡rvore em ordem.
// No caso da sentinela *A deve ser A->dir
// Mostrar a cor do nÃ³

void percorreOrdemRN(rn *A) {
    if (A == NULL)
        return;
    percorreOrdemRN(A->esq);
    printf(" %d %c -- ", A->raiz, A->cor);
    percorreOrdemRN(A->dir);
    
}

