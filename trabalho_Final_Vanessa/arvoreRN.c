#include <stdlib.h>
#include <stdio.h>
#include "arvoreRN.h"

rn *iniciaArvoreRN() {
    printf("Aquiporra");
    rn *sentinela = (rn*) malloc(sizeof (rn));
    sentinela->raiz = -1000;
    sentinela->esq = NULL;
    sentinela->dir = NULL;
    sentinela->pai = NULL;
    sentinela->cor = 'p';
    printf("Aquiporra1");
    return sentinela;
}

//Insere o nÃ³ na Ã¡rvore normalmente. Ao final, chama a funÃ§Ã£o balanceamentornInsercao

void insereNoRN(rn *A, int valorNo) {
    //aloca novo nÃ³
    rn *novoNo;
    novoNo = (rn*) malloc(sizeof (rn));
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

void removeNoRN(rn *A, int valor) {
    printf("Removendo...\n");
    rn *noAux;
    rn *noSucessor;

    noAux = A->dir;//seta o ponteiro auxiliar com a raiz da arvore
    
    if(noAux == NULL){
        printf("Arvore Vazia!\n");
        return;
    }

    //encontra o nó a ser removido
    while (noAux != NULL) {
        if (noAux->raiz != valor) {
            if (valor > noAux->raiz)
                noAux = noAux->dir;
            else
                noAux = noAux->esq;
        } else break;
    }
    //verifica se o nó não existe na árvore
    if (noAux == NULL) {
        printf("O no não existe na arvore\n");
        return;
    } else
        printf("No a ser buscado foi encontrado!\n");
 
    if (noAux->dir == NULL && noAux->esq == NULL) {
        /*
         * Neste caso estamos lidando com um nó folha, o qual será removido de maneira
         * simples.
         */
        printf("O no e uma folha!\n");

        //Verifica de onde é sua origem da esquerda ou da direita de seu pai
        if (noAux->pai->dir == noAux) {
            noAux->pai->dir = NULL;
        } else {
            noAux->pai->esq = NULL;
        }

        noAux = NULL;
        free(noAux);
        return;
    } else {
        /*
         * Neste caso estamos lidando com um nó com filhos, para isso teremos que
         * fazer alterações em seus ponteiros para que nada se perca!
         * 
         * Já que o nó tem filhos, ele tem um sucessor para substitui-lo, então 
         * precisamos achar ele antes de fazer as alterações
         */

        printf("No nao e uma folha!\nProcurando sucessor...\n");

        noSucessor = noAux->dir; //A busca se inicia na arvore esquerda do nó a ser removido

        //Se o valor é null quer dizer que ele não possui sucessor
        if (noSucessor != NULL) {
            //Procura sucessor caso exista arvore direita ao nó a ser removido
            while (noSucessor->esq != NULL) {
                noSucessor = noSucessor->esq;
            }
        } else {
            printf("Nao existe um sucessor para o no a ser removido!\n");
            /*
             * Como ja garantimos acima que esse nó não é uma folha, e que ele não possui
             * sucessor(filho a direita), então obrigatóriamente ele tem um filho a esquerda 
             * que herdará sua posição!
             */
            noAux->raiz = noAux->esq->raiz;
            noAux->esq = NULL;
            return;
        }

        //Checa se o noSucessor foi encontrado com sucesso
        if (noSucessor == NULL) {
            printf("Erro ao procurar pelo nó sucessor!\n");
            return;
        } else
            printf("Sucessor encontrado: %d\n", noSucessor->raiz);

        /*Agora que achamos o sucessor, temos que ver suas caracteristicas:*/

        if (noSucessor->dir == NULL && noSucessor->esq == NULL) {
            printf("No sucessor e uma folha!\n");
            /*Se o nó sucessor for uma folha somente copie ele para a posição do
             do nó removido e sete ele como NULL, ou seja, remova ele*/
            noAux->raiz = noSucessor->raiz;
            if (noSucessor->pai->dir == noSucessor) {
                noSucessor->pai->dir = NULL;
            } else {
                noSucessor->pai->esq = NULL;
            }
            noSucessor = NULL;
            free(noSucessor);
        } else {
            printf("No sucessor nao e uma folha!");
            //por se tratar do sucessor, sabemos que ele é o nó que esta totalmente 
            //a esquerda da arvore direita, então ele não terá filho a esquerda!
            //Então se o programa cair neste caso é porque ele tem um filho a direita.
            noSucessor->raiz = noSucessor->dir->raiz;
            noSucessor->pai->esq = noSucessor->dir;
            noSucessor->dir->pai = noSucessor->pai;
            noAux->raiz = noSucessor->raiz;
            noSucessor = NULL;
            free(noSucessor);
        }
    }
}


void balanceiaRemocao(rn* A, int valor) {
    rn *noAux = A->dir;
    rn *noSucessor = NULL;

    //encontra o nó a ser removido
    while (noAux != NULL && noAux->raiz != valor) {
        if (valor > noAux->raiz)
            noAux = noAux->dir;
        else
            noAux = noAux->esq;
    }
    //verifica se o nó não existe na árvore
    if (noAux == NULL) {
        printf("O no não existe na arvore\n");
        return;
    } else
        printf("Nó a ser buscado foi encontrado!\n");

    noSucessor = noAux->dir;

    printf("aquiantes2\n");
    //Caso 1 -> noRemovido = vermelho e noSucessor = vermelho
    if (noAux->cor == 'v' && noSucessor->cor == 'v') {
        printf("aqui1\n");
        noAux->raiz = noSucessor->raiz;
        if (noSucessor->dir != NULL) {
            printf("aqui2\n");
            noSucessor->pai->esq = noSucessor->dir;
            noSucessor = noSucessor->dir;
        } else {
            printf("aqui3\n");
            noSucessor->pai->esq = NULL;
            free(noSucessor);
        }
    } else {
        //Caso 2 -> noRemovido = preto e noSucessor = vermelho
        if (noAux->cor == 'p' && noSucessor->cor == 'v') {
            noAux->pai = noSucessor;
            noSucessor->cor = 'p';
            noAux = noSucessor;
            if (noSucessor->dir != NULL) {
                noSucessor->pai->esq = noSucessor->dir;
            }
            free(noSucessor);
        } else {
            //Caso 3 -> noRemovido = preto e noSucessor = preto
            if (noAux->cor == 'p' && noSucessor->cor == 'p') {
                rn* noIrmao;

                //Encontra no irmão
                if (noAux == noAux->pai->dir) {
                    noIrmao = noAux->pai->esq;
                } else {
                    noIrmao = noAux->pai->dir;
                }

                if (noIrmao != NULL) {

                    if (noAux->pai->esq = noAux) {
                        //Caso 1 do 3 -> irmão vermelho
                        if (noIrmao->cor == 'v') {
                            noIrmao->cor = 'p';
                            noIrmao->pai->cor = 'v';
                            rotacaoEsq(A, noIrmao->pai);
                            noIrmao = noAux->pai->dir;
                        }

                        //Caso 2 do 3 -> irmao preto e filhos pretos
                        if (noIrmao->cor == 'p' && noIrmao->dir->cor == 'p' && noIrmao->esq->cor == 'p') {
                            if (noIrmao->pai->cor == 'v') {
                                noIrmao->cor = 'v';
                                noIrmao->pai->cor = 'p';
                            } else {
                                noIrmao->cor = 'v';
                            }
                        }

                        //Caso 3 do 3 -> irmão preto e filho esquerdo vermelho e o direito preto
                        if (noIrmao->cor == 'p' && noIrmao->dir->cor == 'p' && noIrmao->esq->cor == 'v') {
                            noIrmao->esq->cor = 'p';
                            noIrmao->cor = 'v';
                            rotacaoDir(A, noIrmao);
                            noIrmao = noAux->pai->dir;
                        }

                        //Caso 4 do 3 -> irmão preto e filho da direita é vermelho e o outro preto
                        if (noIrmao->cor == 'p' && noIrmao->dir->cor == 'v' && noIrmao->esq->cor == 'p') {
                            noIrmao->cor = noIrmao->pai->cor;
                            noIrmao->pai->cor = 'p';
                            noIrmao->dir->cor = 'p';
                            rotacaoEsq(A, noAux);
                            noAux = A;
                        }
                    } else {
                        //Caso 1 do 3 -> irmão vermelho
                        if (noIrmao->cor == 'v') {
                            noIrmao->cor = 'p';
                            noIrmao->pai->cor = 'v';
                            rotacaoDir(A, noIrmao->pai);
                            noIrmao = noAux->pai->esq;
                        }

                        //Caso 2 do 3 -> irmao preto e filhos pretos
                        if (noIrmao->cor == 'p' && noIrmao->dir->cor == 'p' && noIrmao->esq->cor == 'p') {
                            if (noIrmao->pai->cor == 'v') {
                                noIrmao->cor = 'v';
                                noIrmao->pai->cor = 'p';
                            } else {
                                noIrmao->cor = 'v';
                            }
                        }

                        //Caso 3 do 3 -> irmão preto e filho esquerdo vermelho e o direito preto
                        if (noIrmao->cor == 'p' && noIrmao->dir->cor == 'p' && noIrmao->esq->cor == 'v') {
                            noIrmao->dir->cor = 'p';
                            noIrmao->cor = 'v';
                            rotacaoEsq(A, noIrmao);
                            noIrmao = noAux->pai->esq;
                        }

                        //Caso 4 do 3 -> irmão preto e filho da direita é vermelho e o outro preto
                        if (noIrmao->cor == 'p' && noIrmao->dir->cor == 'v' && noIrmao->esq->cor == 'p') {
                            noIrmao->cor = noIrmao->pai->cor;
                            noIrmao->pai->cor = 'p';
                            noIrmao->esq->cor = 'p';
                            rotacaoDir(A, noAux);
                            noAux = A;
                        }
                    }
                } else {

                }
            }
        }
    }
}