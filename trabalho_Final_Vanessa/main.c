#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "arvore234.h"
#include "arvoreRN.h"
#include "auxiliar.h"

int main(int argc, char** argv) {
    rn *arvoreRN = iniciaArvoreRN();
    arvoreB *raiz;
    int *dados, op, num, i, rVal;
    dados = leDados();
    int contador;
    raiz = NULL;
    /*for (i = 0; i < 20; i++) {
        raiz = insere_arvoreB(raiz,i);
        em_ordem(raiz);
        printf("\n**************************************************\n");
    }*/
    
       for (contador = 9; contador > 0; contador--) {
        raiz = insere_arvoreB(raiz, contador);
                em_ordem(raiz);
                printf("\n**************************************************\n");
    }

    do {
        printf("Arvores Balanceadas: Menu\n1. Inserir novo elemento na arvore 2,3,4\n2.Remover elemento da arvore 2,3,4\n3. Imprimir arvore 2,3,4\n4. Converter em uma arvore rubro-negra\n5. Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Digite o numero que deseja inserir\n");
                scanf("%d", &num);

                break;
            case 2:

                break;
            case 3:

                break;

            case 4:
                system("clear");
                do {
                    printf("Arvores Balanceadas: Menu\n1. Inserir novo elemento na arvore rubro-negra\n2. Remover elemento da arvore rubro-negra\n3. Imprimir arvore rubro-negra\n4. Sair\n");
                    scanf("%d", &op);

                    switch (op) {
                        case 1:
                            printf("Digite o numero que se deseja inserir\n");
                            scanf("%d", &num);
                            insereNoRN(arvoreRN, num);
                            printf("Elemento inserido com sucesso\n");
                            break;
                        case 2:
                            printf("Digite o numero que se deseja remover\n");
                            scanf("%d", &num);
                            removeNoRN(arvoreRN, num);
                            break;
                        case 3:
                            percorreOrdemRN(arvoreRN->dir);
                            printf("\n");
                            break;
                        case 4:
                            return (0);
                            break;
                        default:
                            printf("Operacao Invalida\n");
                    }
                } while (op != 4);
                break;
            case 5:
                return 0;
                break;
            default:
                printf("operacao Invalida\n");
        }

    } while (op != 5);


    return (EXIT_SUCCESS);
}
