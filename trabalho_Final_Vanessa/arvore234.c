#include "arvore234.h"
#include <stdio.h>
#include <stdlib.h>

//Abreviação da função malloc
#define malloc(x) ((x*) malloc(sizeof(x)))
//Abreviação da função printf
#define LOG(x) (printf x)

int isLeaf(no234 *no) {
    if ((no->filho1 == NULL) && (no->filho2 == NULL) &&(no->filho3 == NULL) && (no->filho4 == NULL)) {
        return 1;
    } else {
        return 0;
    }
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
    novoNo->tipoNo = tipoNo;

    return novoNo;
}

/*no234 *quebraNo(no234 *no, int val, int *rval, no234 *subarvore) {
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
        z`
                no->right = NULL;
        no->center = subarvore;
        return paux;
    }
}
 */
void adicionaChave(no234 *no, int num) { //funcao para inserir uma chave em um no com 1 ou 2 chaves ja existentes.
    if (no->cChave == 1) { //se Contem apenas 1 registro
        if (num < no->lChave) { //se num for menor q a chave existente (Sempre sera a menor)
            no->cChave = no->lChave; // copia o menor para uma posicao a mais
            no->lChave = num; //insere num em lchave(antiga menor chave)
            no->tipoNo++; //atualiza o tipo do no(quantidade de chaves no no)
            return; //nada mais a fazer retorna
        } else { //senao for <
            no->cChave = num; //
            no->tipoNo++;
            return;
        }
    } else { //senao for == 1 entao sera == 2
        if (num < no->lChave) {//se o num a ser inserido for menor q o menor numero existente nesse no
            no->rChave = no->cChave; //copia maior numero para seu lugar
            no->cChave = no->lChave; //copia o menor numero para o lugar do antigo maios
            no->lChave = num; //insere o num como menor numero
            no->tipoNo++; //atualiza o contador de espacos preenchidos
            return;
        } else { //senao num > lChave
            if (num < no->cChave) {
                no->rChave = no->cChave; //copia maior numero para seu lugar
                no->cChave = num; //insere o numero em sua posicao
                no->tipoNo++; //atualiza o tipo no
                return;
            } else {
                no->rChave = num;
                no->tipoNo++;
                return;
            }
        }
    }
}

// insere val em no (se necessario retorna o novo no e um valor
// rval)

/*no234 *insere234(no234 *no, int val, int *rval) {
    no234 *paux, *paux2;
    int vaux, promov;

    if (*no == NULL) { // arvore vazia
 *no = (no234 *) malloc(sizeof (no234));
 *no = criaNo234(val, 0, 0, NULL, NULL, NULL, NULL, 1); // cria no folha com um valor 
        return NULL; // nada a fazer depois
    }
    if (isLeaf(*no)) { // chegou a folha
        if ((no->tipoNo == 1) || (no->tipoNo == 2)) { // caso fácil
            adicionaChave(*no, val, NULL);
            return NULL;
        } else {
            paux = quebraNo(*no, val, &vaux, NULL);
 *rval = vaux;
            return paux;
        }
    } else { // continua a procura

        if (val < (no->lChave) {
                paux = insere234(&(no->filho1), val, &vaux);
            } else if (no->tipoNo == 1) || (val < no->rkey))
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
}*/




no234 *insere234(no234 *no, int num) {
    if (no == NULL) { //se arvore esta vazia
        *no = (no234 *) malloc(sizeof (no234)); //aloca no
        *no = criaNo234(num, 0, 0, NULL, NULL, NULL, NULL, 1); // cria no folha com um valor 
        return no;
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