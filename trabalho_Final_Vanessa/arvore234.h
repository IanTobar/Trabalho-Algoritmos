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
void insere_chave(arvoreB *raiz, int info, arvoreB *filhodir);
arvoreB *insere(arvoreB *raiz, int info, bool *h, int *info_retorno);
arvoreB *insere_arvoreB(arvoreB *raiz, int info);
arvoreB *retira_arvoreB(arvoreB *raiz, int info);
int busca_binaria(arvoreB *no, int info);
bool busca(arvoreB *raiz, int info);
void em_ordem(arvoreB *raiz);



#endif /* ARVORE234_H */

