#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arvora_binaria_busca.h"

Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
    if (a == NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }

    else if(v < a->info){
        a->esq = inserir(a->esq, v);
    }

    else{
        a->dir = inserir(a->dir, v);
    }

   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
    if (a == NULL)
        return NULL;

    else{
        if (a->info > v)
            a->esq = remover(a->esq, v);
        else if (a->info < v)
            a->dir = remover(a->dir, v);
        else{
            if ((a->esq == NULL) && (a->dir == NULL)){
                free(a);
                a = NULL;
            }
            else if (a->dir == NULL){
                Arvore *aux = a;
                a = a->esq;
                free(aux);
            }
            else if (a->esq == NULL){
                Arvore *aux = a;
                a = a->dir;
                free(aux);
            }
            else{
                Arvore *aux = a->esq;

                while (aux->dir != NULL)
                    aux = aux->dir;
                a->info = aux->info;
                aux->info = v;
                a->esq = remover(a->esq, v);
            }
        }
        return a;
    }
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
    if (a == NULL){
        return 0;
    }
    else if (v < a->info){
        return buscar(a->esq, v);
    }
    else if (v > a->info){
        return buscar(a->dir, v);
    }
    else{
        return 1;
    }
}

//========= Q2 - min =====
int min (Arvore *a){
    if(a != NULL && a->esq == NULL)
        return a->info;
    else
        return min(a->esq);
    return 0;
}

//========= Q2 - max =====
int max (Arvore *a){
    if(a != NULL && a->dir == NULL)
        return a->info;
    else
        return max(a->dir);
    return 0;
}

//========= Q3 - encontra-se na MAIN ====
/*O tempo de busca para a arvore ordenada foi 0,0013360 enquanto que para a arvore aleatoria o tempo foi 0,000050*/

/*O principal motivo que ocasiona a diferença de tempo entre as execuções
é a forma como os elementos são inseridos. Pois, em uma inserção ordenada
todos os valores tendem ao lado direito da arvore, condicionando em uma arvore
degenerada, e com isso um maior tempo de busca quando comparado com a arvore
de valores aleatorios.*/

//========= Q4 - imprime_decrescent =====
void imprime_decrescente (Arvore *a){
    if(a != NULL){
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
    }
}

void pre_order (Arvore* a) {
    if(a != NULL){
        printf("%d ", a->info);
        pre_order(a->esq);
        pre_order(a->dir);
    }
}
