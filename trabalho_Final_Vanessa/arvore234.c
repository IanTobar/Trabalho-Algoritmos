/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "arvore234.h"
#include <stdio.h>
#include <stdlib.h>

//Abreviação da função malloc
#define malloc(x) ((x*) malloc(sizeof(x)))
//Abreviação da função printf
#define LOG(x) (printf x)

arv234* criaArvore() {
    arv234* a = malloc(arv234);
    no* novo = malloc(no);

    if (a && novo) {
        novo->pai = NULL;
        novo->count = 0;
        novo->filhos[0] = NULL;
        novo->filhos[1] = NULL;
        novo->filhos[2] = NULL;
        novo->filhos[3] = NULL;

        a->raiz = novo;
    } else {
        LOG("Erro ao alocar arvore");
    }

    return a;
} 