#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "arvore234.h"
#include "arvoreRN.h"
#include "auxiliar.h"

int main(int argc, char** argv) {
    rn *arvoreRB;
    arv234 *arvore234;

    printf("Iniciando o programa\n");
    printf("Alocando arvore 2,3,4\n");
    arvore234 = criaArvore();
    printf("Arvore iniciada com sucesso\n");

    return (EXIT_SUCCESS);
}

