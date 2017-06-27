#ifndef ARVORERN_H
#define ARVORERN_H

typedef struct ArvoreRN rn;

struct ArvoreRN {
    int raiz;
    char cor;
    rn *esq;
    rn *dir;
    rn *pai;
};

rn *iniciaArvoreRN();
void insereNoRN(rn *A, int valorNo);
void rotacaoEsq(rn *A, rn *noDesbalanceado);
void rotacaoDir(rn *A, rn *noDesbalanceado);
void removeNoRN(rn* A, int valor);
void balanceamentornInsercao(rn *A, rn *z);
#endif /* ARVORERN_H */

