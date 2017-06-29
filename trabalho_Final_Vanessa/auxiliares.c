#include "arvore234.h"
#include "arvoreRN.h"
#include "auxiliar.h"
#include "io.h"
#include <stdlib.h>
#include <stdio.h>

void converte234ToRN(arvoreB* A, rn* B) {
    rn* x = (rn*) malloc(sizeof (rn));
    rn* y = (rn*) malloc(sizeof (rn));
    rn* z = (rn*) malloc(sizeof (rn));

    //y é o pai
    //x e z são filhos de y

    if (B->raiz == -1000) {

        if (A->num_chaves == 0) {
            return;
        }

        if (A->num_chaves == 1) {
            y = A->chaves[0];
            x = NULL;
            z = NULL;
        } else {
            if (A->num_chaves == 1) {
                y = A->chaves[0];
                x = z = NULL;
            } else {
                if (A->num_chaves == 1) {
                    y = A->chaves[0];
                    x = z = NULL;
                } else {

                }
            }
        }

    }

    y->esq = x;
    y->dir = z;

    x = A->chaves[0];
    y = A->chaves[1];
    z = A->chaves[2];

    B = y;

}