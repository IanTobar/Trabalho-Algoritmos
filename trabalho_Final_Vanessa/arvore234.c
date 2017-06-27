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
        novo->filhos[0] = NULL;
        novo->filhos[1] = NULL;
        novo->filhos[2] = NULL;
        novo->filhos[3] = NULL;
        novo->vazios = MAX_CHAVES;
        a->raiz = novo;
    } else {
        LOG(("Erro ao alocar arvore"));
    }

    return a;
} 