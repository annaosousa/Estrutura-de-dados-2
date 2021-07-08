#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arvora_binaria_busca.h"

int main () {
   srand(time(NULL));
   clock_t start, end;
   double elapsed_time;

   int i;

   Arvore *a = cria_arvore_vazia ();

   //inserir
   a = inserir (a, 50);
   a = inserir (a, 30);
   a = inserir (a, 90);
   a = inserir (a, 20);
   a = inserir (a, 40);
   a = inserir (a, 95);
   a = inserir (a, 10);
   a = inserir (a, 35);
   a = inserir (a, 45);

   //.....


   printf("\n");
   printf("Arvore em pre-ordem: ");
   pre_order (a);
   printf("\n");

   int minimo = min(a);
   printf("O valor minimo da arvore binaria e: %d \n", minimo);
   int maximo = max(a);
   printf("O valor maximo da arvore binaria e: %d \n", maximo);

   //========= Q3 - letra a e letra b =====

   Arvore *a1, *a2;
   a1 = cria_arvore_vazia();
   a2 = cria_arvore_vazia();

   for(int i=0; i<100000; i++){
      a1 = inserir(a1,i);
   }

   for(int i=0; i<100000; i++){
      a2 = inserir(a2,rand()%100000);
   }

    //Arvore ordenada
    start = clock();
    if (buscar(a1, 100001))//busca arvore ordenada
        printf("Valor encontrado\n");
    else
        printf("Valor nao encontrado\n");
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de busca na arvore ordenada: %.8f\n", elapsed_time);

    //Arvore aleatoria
    /*start = clock();
    buscar(a2, 1001); //busca arvore aleatoria
    end = clock();
    elapsed_time = (end - start)/CLOCKS_PER_SEC;
    printf("Tempo de busca na arvore aleatoria: %.2f\n", elapsed_time);
*/
// ====== Q3 ====
    printf("Arvore decrescente: ");
    imprime_decrescente(a);
    printf("\n");

   return 0;
}

