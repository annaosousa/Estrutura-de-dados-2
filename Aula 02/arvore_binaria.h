#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void);
Arvore* constroi_arv (char c, Arvore *e, Arvore *d);
int verifica_arv_vazia (Arvore *a);
void arv_libera (Arvore* a);

void pre_ordem(Arvore *a);
void in_ordem(Arvore *a);
void pos_ordem(Arvore *a);
int pertence_arv (Arvore *a, char c);
int conta_nos (Arvore *a);
int calcula_altura_arvore (Arvore *a);
int conta_nos_folha (Arvore *a);

#endif // ARVORE_BINARIA_H_INCLUDED
