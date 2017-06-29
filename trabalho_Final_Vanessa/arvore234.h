#ifndef ARVORE234_H
#define ARVORE234_H

#define T          2
#define MAX_CHAVES 3
#define MAX_FILHOS 4
#define MIN_OCUP   1

#define true  1
#define false 0

typedef int bool;

typedef struct no_arvoreB arvoreB;

struct no_arvoreB {
    int num_chaves; //Quantidades de chaves contida no nó
    int chaves[MAX_CHAVES]; //Chaves armazenadas no nó
    arvoreB *filhos[MAX_FILHOS]; //Ponteiro para os filhos
};

void selectionSort(int vetorDesordenado[], int tamanhoVetor);



#endif /* ARVORE234_H */

