#include "arvore234.h"
#include <stdio.h>
#include <stdlib.h>

//Abreviação da função malloc
#define malloc(x) ((x*) malloc(sizeof(x)))
//Abreviação da função printf
#define LOG(x) (printf x)

void isLeaf(no234 *no) {

}

no234 *criaNo234(int ch1, int ch2, int ch3, no234 *f1, no234 *f2, no234 *f3, no234 *f4, int tipoNo) {
    no234 *novoNo;
    novoNo = (no234*) malloc(sizeof (no234));
    novoNo->lChave = ch1;
    novoNo->cChave = ch2;
    novoNo->rChave = ch3;
    novoNo->filho1 = f1;
    novoNo->filho2 = f2;
    novoNo->filho3 = f3;
    novoNo->filho4 = f4;
    novoNo->tipoArvore = tipoNo;




}

no234 *quebraNo(no234 *no, int val, int *rval, no234 *subarvore) {
    no234 *paux;

    if (val > no->rkey) { // val esta mais a direita
        *rval = no->rkey; // promove a antiga maior
        paux = no->right;
        no->right = NULL; // elimina o terceiro filho
        no->nkeys = 1; // atualiza o número de chaves
        return criaNo234(val, 0, 1, paux, subarvore, NULL);
    } else if (val >= no->lkey) { // val esta no meio
        *rval = val; // continua sendo promovido
        paux = no->right;
        no->right = NULL;
        no->nkeys = 1;
        return criaNo(no->rkey, 0, 1, subarvore, paux, NULL);
    } else { // val esta a mais a esquerda
        *rval = no->lkey;
        // primeiro cria o nó a direita
        paux = criaNo(no->rkey, 0, 1, no->center, no->right, NULL);
        no->lkey = val; // em seguida arruma o nó a esquerda
        no->nkeys = 1;
        no->right = NULL;
        no->center = subarvore;
        return paux;
    }
}




// insere val em no (se necessario retorna o novo no e um valor
// rval)

no234 *insere234(no234 **no, int val, int *rval) {
    no234 *paux, *paux2;
    int vaux, promov;

    if (*no == NULL) { // arvore vazia
        *no = (no234 *) malloc(sizeof (no234));
        *no = criaNo234(val, 0, 0, NULL, NULL, NULL, NULL, 1); // cria no folha com um valor 
        return NULL; // nada a fazer depois
    }
    if (isLeaf(*no)) { // chegou a folha
        if ((*no)->vazios == 1) { // caso fácil
            adicionaChave(*no, val, NULL);
            return NULL;
        } else {
            paux = quebraNo(*no, val, &vaux, NULL);
            *rval = vaux;
            return paux;
        }
    } else { // continua a procura
        if (val < (*no)->lkey)
            paux = insere(&((*no)->left), val, &vaux);
        else if (((*no)->nkeys == 1) || (val < (*no)->rkey))
            paux = insere(&((*no)->center), val, &vaux);
        else
            paux = insere(&((*no)->right), val, &vaux);
        if (paux == NULL) // nao promoveu
            return NULL;
        else
            if ((*no)->nkeys == 1) {
            adicionaChave(*no, vaux, paux);
            return NULL;
        } else {
            paux2 = quebraNo(*no, vaux, &promov, paux);
            *rval = promov;
            return paux2;
        }
    }
}

no234 *find(no234 *raiz, int key) {
    if (raiz == NULL)
        return NULL; // não encontrou
    if (key == raiz->lkey)
        return raiz; // é a chave esquerda
    if ((raiz->nkeys == 2) && (key == raiz->rkey))
        return raiz; // é a chave direita
    if (key < raiz->lkey)
        return find(raiz->left, key);
    else if (raiz->nkeys == 1)
        return find(raiz->center, key);
    else if (key < raiz->rkey)
        return find(raiz->center, key);
    else
        return find(raiz->right, key);

}