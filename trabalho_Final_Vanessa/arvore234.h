/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvore234.h
 * Author: ruan
 *
 * Created on 19 de Junho de 2017, 21:12
 */

#include <stdlib.h>

#ifndef ARVORE234_H
#define ARVORE234_H

#define MAX_CHAVES 3
#define MAX_FILHOS 4


typedef struct Arvore234 arv234;
typedef struct No234 no;

struct Arvore234{
    no *raiz;
};

struct No234{
    int count;//Contador, irá indicar a quantidade de chaves no nó
    int chave[MAX_CHAVES];//Vetor que armazena as 3 chaves, que é o maximo que um nó 234 pode ter
    no *filhos[MAX_FILHOS];//Ponteiro para os 4 filhos, que é o maximo que um nó 234 pode ter
    no *pai;//ponteiro para o pai do nó
};

#endif /* ARVORE234_H */

