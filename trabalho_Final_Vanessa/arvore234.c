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
                return; //nada mais a fazer
            } else { //senao
                no->rChave = num; //num eh inserido em maior filho
                no->tipoNo++; //atualiza numero de chaves
                return; //nada mais a fazer
            }
        }
    }
}

void split234() {

}

no234 *insere234(no234 *no, int num) {
    no234 *nAux;
    int vAux;
    if (no == NULL) { //se arvore esta vazia
        *no = (no234 *) malloc(sizeof (no234)); //aloca no
        *no = criaNo234(num, 0, 0, NULL, NULL, NULL, NULL, 1); // cria no folha com uma chave 
        return no; //retorna no
    }
    if (isLeaf(no)) { //verifica se chegou a folha
        if ((no->tipoNo == 1) || (no->tipoNo == 2)) { //casos mais faceis de insercao
            adicionaChave(no, num);
            return no;
        } else {
            nAux = split234(no, num, &vAux, NULL);
            return nAux;
        }

    } else {

    }   


}



