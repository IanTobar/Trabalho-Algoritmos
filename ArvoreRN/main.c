/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ruan
 *
 * Created on 18 de Maio de 2017, 16:05
 */

#include <stdio.h>
#include <stdlib.h>
#include "rubroNegra.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
   FILE *entrada;
   
   int v[11];
   int i = 0;
   
   entrada = fopen("entrada.txt","r");
   if(entrada ==NULL){
       printf("Erro ao abrir o arquivo\n");
       return 1;
   }
   
   while(!feof(entrada)){;
       fscanf(entrada,"%d",&v[i]);
       i++;
   }
   rb *A = inicializaArvore();
   for(i=0;i<11;i++){
       insereNoRB(A,v[i]);
   }
   
   percorreOrdem(A->dir);
   
    return (EXIT_SUCCESS);
}

