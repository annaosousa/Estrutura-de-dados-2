#ifndef ARVORA_BINARIA_BUSCA_H_INCLUDED
#define ARVORA_BINARIA_BUSCA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arvore_vazia (void);
void arvore_libera (Arvore* a);
Arvore* inserir (Arvore *a, int v);
Arvore* remover (Arvore *a, int v);
int buscar (Arvore *a, int v);
int min(Arvore *a);
int max(Arvore *a);
void imprime_decrescente (Arvore *a);
void pre_order (Arvore* a);


#endif // ARVORA_BINARIA_BUSCA_H_INCLUDED
