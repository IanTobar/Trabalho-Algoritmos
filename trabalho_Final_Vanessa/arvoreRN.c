#include <stdlib.h>
#include <stdio.h>
#include "arvoreRN.h"

rn *inicializaArvore() {
    rn *sentinela;
    sentinela = (rn*) calloc(1, sizeof (rn));
    sentinela->raiz = -1000;
    sentinela->esq = NULL;
    sentinela->dir = NULL;
    sentinela->pai = NULL;
    sentinela->cor = 'p';
    return sentinela;
}

//Insere o nÃ³ na Ã¡rvore normalmente. Ao final, chama a funÃ§Ã£o balanceamentornInsercao

void insereNorn(rn *A, int valorNo) {
    //aloca novo nÃ³
    rn *novoNo;
    novoNo = (rn*) calloc(1, sizeof (rn));
    novoNo->raiz = valorNo;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->pai = NULL;
    novoNo->cor = 'v';

    //procura o local de inserÃ§Ã£o
    rn *noAtual = A->dir;
    rn *noPai = A;
    while (noAtual != NULL) {
        if (valorNo > noAtual->raiz) {
            noPai = noAtual;
            noAtual = noAtual->dir;
        } else {
            noPai = noAtual;
            noAtual = noAtual->esq;
        }
    }
    //insere o novoNo no local correto
    if (valorNo > noPai->raiz)
        noPai->dir = novoNo;
    else
        noPai->esq = novoNo;
    novoNo->pai = noPai;
    //confere o balanceamento da Ã¡rvore se o pai nÃ£o Ã© a sentinela
    balanceamentornInsercao(A, novoNo);

    return;
}

//RotaÃ§Ã£o Ã  esquerda

void rotacaoEsq(rn *A, rn *p) {
    rn *q;

    q = p->esq;
    //----------------> Realiza a rotação
    p->esq = q->dir;
    if (q->dir != NULL)
        q->dir->pai = p;
    q->dir = p;
    q->pai = p->pai;
    if (p->pai != NULL)
        if (p->pai->esq == p)
            p->pai->esq = q;
        else
            p->pai->dir = q;
    p->pai = q;
}

//RotaÃ§Ã£o Ã  direita

void rotacaoDir(rn *A, rn *p) {
    rn *q;

    q = p->esq;
    //----------------> Realiza a rotação
    p->esq = q->dir;
    if (q->dir != NULL)
        q->dir->pai = p;
    q->dir = p;
    q->pai = p->pai;
    if (p->pai != NULL)
        if (p->pai->esq == p)
            p->pai->esq = q;
        else
            p->pai->dir = q;
    p->pai = q;
    return;
}

//Percorre a Ã¡rvore em ordem.
// No caso da sentinela *A deve ser A->dir
// Mostrar a cor do nÃ³

void percorreOrdem(rn *A) {
    if (A == NULL)
        return;
    percorreOrdem(A->esq);
    printf(" %d %c -- ", A->raiz, A->cor);
    percorreOrdem(A->dir);
}

//Chama as rotaÃ§Ãµes corretas para ajustar o balanceamento e faz o ajuste correto dos FBs

void balanceamentornInsercao(rn *A, rn *z) {
    rn *pai = z->pai;
    rn *avo = z->pai->pai;
    rn *tio;
    char corTio;

    if (pai->cor == 'v') {
        if (z->raiz < avo->raiz) {//Esquerda do avô
            tio = avo->dir;
            if (tio == NULL) {
                corTio = 'p';
            } else {
                corTio = tio->cor;
            }
            //Caso 1
            if (corTio == 'v') {
                pai->cor = 'p';
                tio->cor = 'p';
                avo->cor = 'v';
                balanceamentornInsercao(A, avo);
            }
            //caso 2
            if ((corTio == 'p') && (z->raiz > pai->raiz)) {
                z = pai;
                rotacaoEsq(A, z);
                pai = z->pai; //n muda o avo por causa da rotação
            }
            //caso 3
            if ((corTio == 'p')&&(z->raiz < pai->raiz)) {
                pai->cor = 'p';
                avo->cor = 'v';
                rotacaoDir(A, avo);
            }
        } else {
            if (z->raiz > avo->raiz) {//Esquerda do avô
                tio = avo->dir;
                if (tio == NULL) {
                    corTio = 'p';
                } else {
                    corTio = tio->cor;
                }
                //Caso 1
                if (corTio == 'v') {
                    pai->cor = 'p';
                    tio->cor = 'p';
                    avo->cor = 'v';
                    z = avo;
                    balanceamentornInsercao(A, avo);
                }
                //caso 2
                if ((corTio == 'p') && (z->raiz > pai->raiz)) {
                    z = pai;
                    rotacaoDir(A, z);
                    pai = z->pai; //n muda o avo por causa da rotação
                }
                //caso 3
                if ((corTio == 'p')&&(z->raiz < pai->raiz)) {
                    pai->cor = 'p';
                    avo->cor = 'v';
                    rotacaoEsq(A, avo);
                }
            }
        }
    }
    A->dir->cor = 'p';
}
