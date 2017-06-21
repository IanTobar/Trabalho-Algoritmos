#ifndef ARVORERN_H
#define ARVORERN_H

typedef struct rn {
    int raiz;
    char cor;
    struct rn *esq;
    struct rn *dir;
    struct rn *pai;
} rn;

//Inicializa a Ã¡rvore Rubro Negra, criando a sentinela com raiz = -1000 e preta
rn *inicializaArvore();

//Insere o nÃ³ na Ã¡rvore normalmente. Ao final, chama a funÃ§Ã£o balanceamentoRBInsercao
void insereNoRB(rn *A, int valorNo);

//RotaÃ§Ã£o Ã  esquerda
void rotacaoEsq(rn *A, rn *noDesbalanceado);

//RotaÃ§Ã£o Ã  direita
void rotacaoDir(rn *A, rn *noDesbalanceado);

//Percorre a Ã¡rvore em ordem.
// No caso da sentinela *A deve ser A->dir
// Mostrar a cor do nÃ³
void percorreOrdem(rn *A);

//Chama as rotaÃ§Ãµes corretas para ajustar o balanceamento e faz o ajuste correto dos FBs
void balanceamentoRBInsercao(rn *A, rn *noInserido);
#endif /* ARVORERN_H */

