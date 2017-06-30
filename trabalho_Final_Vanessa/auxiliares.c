#include "arvore234.h"
#include "arvoreRN.h"
#include "auxiliar.h"
#include "io.h"
#include <stdlib.h>
#include <stdio.h>

void converteArvore(arvoreB *arvore234, rn *arvoreRN) {
    rn *aux1, *aux2, *aux3;
    if (arvore234->num_chaves == 3) {
        aux1 = (rn*) malloc(sizeof (rn));
        aux2 = (rn*) malloc(sizeof (rn));
        aux3 = (rn*) malloc(sizeof (rn));
        aux1->raiz = arvore234->chaves[1];
        aux1->cor = 'v';
        aux2->raiz = arvore234->chaves[0];
        aux2->cor = 'p';
        aux3->raiz = arvore234->chaves[2];
        aux3->cor = 'p';
        aux1->esq = &aux2;
        aux1->dir = &aux3;
        if (aux1 > arvoreRN->raiz) {
            arvoreRN->dir = &aux1;
            converteArvore(arvore234->filhos[0], arvoreRN->esq);
            converteArvore(arvore234->filhos[2], arvoreRN->dir);
        } else {
            arvoreRN->esq = &aux1;

            converteArvore(arvore234->filhos[0], arvoreRN->esq);
            converteArvore(arvore234->filhos[2], arvoreRN->dir);
        }
    } else {
        if (arvore234->num_chaves == 2) {
            aux1 = (rn*) malloc(sizeof (rn));
            aux2 = (rn*) malloc(sizeof (rn));

            aux1->raiz = arvore234->chaves[1];
            aux1->cor = 'v';

            aux2->raiz = arvore234->chaves[0];
            aux2->cor = 'p';

            aux1->esq = &aux2;
            aux1->dir = NULL;
            if (aux1 > arvoreRN->raiz) {
                arvoreRN->dir = &aux1;

                converteArvore(arvore234->filhos[0], arvoreRN->esq);
                converteArvore(arvore234->filhos[2], arvoreRN->dir);
            } else {
                arvoreRN->esq = &aux1;

                converteArvore(arvore234->filhos[0], arvoreRN->esq);
                converteArvore(arvore234->filhos[2], arvoreRN->dir);
            }

        } else {
            aux1 = (rn*) malloc(sizeof (rn));
            aux1->raiz = arvore234->chaves[0];
            aux1->cor = 'v';
            aux1->dir = NULL;
            aux1->esq = NULL;
            if (aux1 > arvoreRN->raiz) {
                arvoreRN->dir = &aux1;

                converteArvore(arvore234->filhos[0], arvoreRN->esq);
                converteArvore(arvore234->filhos[2], arvoreRN->dir);
            } else {
                arvoreRN->esq = &aux1;

                converteArvore(arvore234->filhos[0], arvoreRN->esq);
                converteArvore(arvore234->filhos[2], arvoreRN->dir);
            }

        }
    }


}