#ifndef ARVORERN_H
#define ARVORERN_H

typedef struct rn {
    int raiz;
    char cor;
    struct rn *esq;
    struct rn *dir;
    struct rn *pai;
} rn;

rn *iniciaArvoreRN();
void insereNoRN(rn *A, int valorNo);
void rotacaoEsq(rn *A, rn *noDesbalanceado);
void rotacaoDir(rn *A, rn *noDesbalanceado);
void removeNoRN(rn* A, int valor);
void balanceamentornInsercao(rn *A, rn *z);
#endif /* ARVORERN_H */

