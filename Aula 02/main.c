#include <stdio.h>
#include "arvore_binaria.h"

int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );

   printf("Percurso pre-ordem:\n");
   pre_ordem(a);
   printf("\n");
   printf("Percurso in-ordem:\n");
   in_ordem(a);
   printf("\n");
   printf("Percurso pos-ordem:\n");
   pos_ordem(a);
   printf("\n");

   printf("O caracter pertence? %d\n", pertence_arv(a,'m'));

   printf("Numero de nos de uma arvora binaria: %d\n", conta_nos(a));
   printf("Altura da arvore: %d\n", calcula_altura_arvore(a)); ////
   printf("Numero de nos folhas: %d\n", conta_nos_folha(a));

   arv_libera (a);

   return 0;
}
