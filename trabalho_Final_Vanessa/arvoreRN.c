#include <stdlib.h>
#include <stdio.h>
#include "arvoreRN.h"

rn *iniciaArvoreRN() {
    rn *sentinela = (rn*) malloc(sizeof (rn));
    sentinela->raiz = -1000;
    sentinela->esq = NULL;
    sentinela->dir = NULL;
    sentinela->pai = NULL;
    sentinela->cor = 'p';
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
    //confere o balanceamento da arvore se o pai nao e o sentinela
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

    noAux = A->dir; //seta o ponteiro auxiliar com a raiz da arvore

    if (noAux == NULL) {
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
            balanceiaRemocaoRN(A, noAux, NULL, NULL, noAux->pai->esq);
        } else {
            noAux->pai->esq = NULL;
            balanceiaRemocaoRN(A, noAux, NULL, NULL, noAux->pai->dir);
        }


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

            if (noAux->pai->raiz > noAux->raiz) {
                noAux->pai->esq = noAux->esq;
                balanceiaRemocaoRN(A, noAux, NULL, NULL, noAux->pai->dir);
            } else {
                noAux->pai->dir = noAux->esq;
                balanceiaRemocaoRN(A, noAux, NULL, NULL, noAux->pai->esq);
            }

            free(noAux);
            return;
        }

        //Checa se o noSucessor foi encontrado com sucesso
        if (noSucessor == NULL) {
            printf("Erro ao procurar pelo nó sucessor!\n");
            return;
        } else
            printf("Sucessor encontrado: %d\n", noSucessor->raiz);

        /*Agora que achamos o sucessor, temos que ver suas caracteristicas:*/

        if (noAux->dir == noSucessor) {
            printf("No sucessor esta a direita do no removido!\n");
            rn* x;

            if (noAux->esq != NULL)
                noSucessor->esq = noAux->esq;

            if (noSucessor->dir != NULL)
                x = noSucessor->dir;
            else x = NULL;

            if (noAux->pai->raiz > noAux->raiz) {
                noAux->pai->esq = noSucessor;
                balanceiaRemocaoRN(A, noAux, noSucessor, x, noAux->pai->dir);
            } else {
                noAux->pai->dir = noSucessor;
                balanceiaRemocaoRN(A, noAux, noSucessor, x, noAux->pai->esq);
            }
        } else {
            printf("No sucessor nao esta a direita do no removido!\n");

            if (noSucessor->dir == NULL) {
                noSucessor->pai->esq = NULL;

                if (noAux->pai->raiz > noAux->raiz) {
                    noAux->pai->esq = noSucessor;
                    balanceiaRemocaoRN(A, noAux, noSucessor, NULL, noAux->pai->dir);
                } else {
                    noAux->pai->dir = noSucessor;
                    balanceiaRemocaoRN(A, noAux, noSucessor, NULL, noAux->pai->esq);
                }
            } else {
                rn* x;
                x = noSucessor->dir;
                noSucessor->pai->esq = noSucessor->dir;
                noSucessor->dir = NULL;

                if (noAux->pai->raiz > noAux->raiz) {
                    noAux->pai->esq = noSucessor;
                    balanceiaRemocaoRN(A, noAux, noSucessor, x, noAux->pai->dir);
                } else {
                    noAux->pai->dir = noSucessor;
                    balanceiaRemocaoRN(A, noAux, noSucessor, x, noAux->pai->esq);
                }
            }
        }

        free(noSucessor);
        free(noAux);
    }
}

void balanceiaRemocaoRN(rn *A, rn* z, rn* y, rn* x, rn* w) {
    //printf("Funcao de balanceamento chamada!\n");
    /*
     * y = z se z possuía um ou nenhum filho
     * y = sucessor(z) se z possuía dois filhos.
     * x é o filho de y antes da remoção de z ou NULO caso y nao
     * possuísse filho.
     * w é o irmão de y.
     */
    char corIrmao;

    if (w == NULL)
        corIrmao = 'p';
    else corIrmao = w->cor;

    rn *aux = z->dir;

    printf("Procurando Sucessor...\n");

    /*
     * y = z se z possuia um ou nenhum filho
     * y = sucessor(z) se z possuia os dois filhos
     * 
     * sucessor = no mais a esquerda da arvore direita de z
     */
    /*if (z->dir != NULL && z->esq != NULL) {
        if (aux != NULL) {
            while (aux->esq != NULL) {
                aux = aux->esq;
            }
            y = aux;
            /*
     * x = filho de y antes da remocao de z, ou nulo caso y nao
     * possui se filho.
     * w = irmao de y.
     */
    /*        x = y->dir; //seta o filho do sucessor.
            w = y->pai->dir; //seta o irmão do sucessor.
        } else {
            y = (rn*) malloc(sizeof (rn));
            y->cor = 'p';
            printf("O no removido nao tem sucessor!\n");
        }
    } else {
        y = z;
    }*/
    /*BALANCEANDO !!!*/

    //Situacao 1
    if (z->cor == 'v') {
        printf("Situacao 1\n");
        printf("\nNo removido e vermelho entao nada sera feito!\n\n");
        A->cor = 'p';
        return;
    }

    //Situacao 2
    if (z->cor == 'p' && y->cor == 'v') {
        printf("Situacao 2\n");
        y->cor = 'p';
        A->cor = 'p';
        return;
    }

    //Situacao 3(PIOR CASO)
    if (z->cor == 'p' && y->cor == 'p') {
        printf("Situacao 3\n");
        //Leva a 4 novos casos

        if (x->pai->esq == x) {
            //Caso 1 (w vermelho)
            if (w->cor = 'v' && w != NULL) {
                printf("Caso 1\n");
                w->cor = 'p';
                w->pai->cor = 'v';
                rotacaoEsq(NULL, w->pai);
                x->pai->dir = w;
            }

            if (corIrmao == 'p') {
                //Caso 2 (w preto e ambos filhos pretos)
                if (w != NULL) {
                    if ((w->esq->cor == 'p' || w->esq == NULL) && (w->dir->cor == 'p' || w->dir == NULL)) {
                        printf("Caso 2\n");
                        if (w->pai->cor == 'v') {
                            w->cor = 'v';
                            w->pai->cor = 'p';
                        } else {
                            w->cor = 'v';
                        }
                        A->cor = 'p';
                        return;
                    }

                    //Caso 3 (w preto e filho esquerda vermelho e direita preto)
                    if (w->esq->cor == 'v' && (w->dir->cor == 'p' || w->dir == NULL)) {
                        printf("Caso 3\n");
                        w->esq->cor = 'p';
                        w->cor = 'v';
                        rotacaoDir(NULL, w);
                        w = x->pai->dir;
                    }
                    //Caso 4 (w preto e filho da direita e vermelho)
                    if (w->dir->cor == 'v') {
                        printf("Caso 4\n");
                        w->cor = w->pai->cor;
                        w->pai->cor = 'p';
                        w->dir->cor = 'p';
                        rotacaoEsq(NULL, x->pai);
                        x->raiz = A->raiz; //?
                    }
                }
            }
        } else {
            //Caso 1 (w vermelho)
            if (w->cor = 'v') {
                printf("Caso 1\n");
                w->cor = 'p';
                w->pai->cor = 'v';
                rotacaoDir(NULL, w->pai);
                w = x->pai->esq;
            }
            if (corIrmao == 'p') {
                //Caso 2 (w preto e ambos filhos pretos)
                if (w != NULL) {
                    //Caso 2 (w preto e ambos filhos pretos)
                    if ((w->esq->cor == 'p' || w->esq == NULL) && (w->dir->cor == 'p' || w->dir == NULL)) {
                        printf("Caso 2\n");
                        if (w->pai->cor == 'v') {
                            w->cor = 'v';
                            w->pai->cor = 'p';
                        } else {
                            w->cor = 'v';
                        }
                        A->cor = 'p';
                        return;
                    }
                    //Caso 3 (w preto e filho esquerda vermelho e direita preto)
                    if (w->dir->cor == 'v' && (w->esq->cor == 'p' || w->esq == NULL)) {
                        printf("Caso 3\n");
                        w->dir->cor = 'p';
                        w->cor = 'v';
                        rotacaoEsq(NULL, w);
                        w = x->pai->esq;
                    }
                    //Caso 4 (w preto e filho da direita e vermelho)
                    if (w->esq->cor == 'v') {
                        printf("Caso 4\n");
                        w->cor = w->pai->cor;
                        w->pai->cor = 'p';
                        w->esq->cor = 'p';
                        rotacaoDir(NULL, x->pai);
                        x = A->raiz;
                    }
                }
            }
        }
    }
    A->cor = 'p';
}