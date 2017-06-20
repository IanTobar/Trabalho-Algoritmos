/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rubroNegra.h
 * Author: Ruan
 *
 * Created on 19 de Maio de 2017, 13:43
 */

#ifndef RUBRONEGRA_H
#define RUBRONEGRA_H

typedef struct rb
{
    int raiz;
    char cor;
    struct rb *esq;
    struct rb *dir;
    struct rb *pai;
}rb;

//Inicializa a Ã¡rvore Rubro Negra, criando a sentinela com raiz = -1000 e preta
rb *inicializaArvore();

//Insere o nÃ³ na Ã¡rvore normalmente. Ao final, chama a funÃ§Ã£o balanceamentoRBInsercao
void insereNoRB(rb *A, int valorNo);

//RotaÃ§Ã£o Ã  esquerda
void rotacaoEsq(rb *A, rb *noDesbalanceado);

//RotaÃ§Ã£o Ã  direita
void rotacaoDir(rb *A, rb *noDesbalanceado);

//Percorre a Ã¡rvore em ordem.
// No caso da sentinela *A deve ser A->dir
// Mostrar a cor do nÃ³
void percorreOrdem(rb *A);

//Chama as rotaÃ§Ãµes corretas para ajustar o balanceamento e faz o ajuste correto dos FBs
void balanceamentoRBInsercao(rb *A, rb *noInserido);


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* RUBRONEGRA_H */

