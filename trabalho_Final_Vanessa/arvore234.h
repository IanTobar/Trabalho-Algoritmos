#ifndef ARVORE234_H
#define ARVORE234_H

#define MAX_CHAVES 3
#define MAX_FILHOS 4


typedef struct Arvore234 arv234;
typedef struct No234 no;

struct Arvore234 {
    no *raiz;
};

struct No234 {
    int chave[MAX_CHAVES]; //Vetor que armazena as 3 chaves, que é o maximo que um nó 234 pode ter
    no *filhos[MAX_FILHOS]; //Ponteiro para os 4 filhos, que é o maximo que um nó 234 pode ter
    no *pai; //ponteiro para o pai do nó
    int vazios;
};

#endif /* ARVORE234_H */

