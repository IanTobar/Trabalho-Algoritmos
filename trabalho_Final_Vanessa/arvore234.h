#ifndef ARVORE234_H
#define ARVORE234_H

#define MAX_CHAVES 3
#define MAX_FILHOS 4


typedef struct Arvore234 arv234;
typedef struct No234 no234;

struct Arvore234 {
    no234 *raiz;
};

struct No234 {
    no234 *filho1;
    int rChave;
    no234 *filho2;
    int cChave;
    no234 *filho3;
    int lChave;
    no234 *filho4;

    no234 *pai; //ponteiro para o pai do nó
    int tipoNo;


};

#endif /* ARVORE234_H */

