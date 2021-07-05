#include <stdio.h>
#include "arvore_binaria.h"

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exerc�cio 1 - pr�-ordem ====

void pre_ordem(Arvore *a){
    if(!verifica_arv_vazia(a)){
        printf("%c\n",a->info);
        pre_ordem(a->esq);
        pre_ordem(a->dir);
    }
}

//========= Exerc�cio 1 - in-ordem ====

void in_ordem(Arvore *a){
    if(!verifica_arv_vazia(a)){
        in_ordem(a->esq);
        printf("%c\n", a->info);
        in_ordem(a->dir);
    }
}
//========= Exerc�cio 1 - p�s-ordem ====

void pos_ordem(Arvore *a){
    if(!verifica_arv_vazia(a)){
        pos_ordem(a->esq);
        pos_ordem(a->dir);
        printf("%c\n", a->info);
    }
}
//========= Exerc�cio 2 - pertence ====

int pertence_arv (Arvore *a, char c){
    if(!verifica_arv_vazia(a)){
        if( c == a->info || c == a->esq || c == a->dir)
            return 1;
    }
    return 0;
}
//========= Exerc�cio 3 - conta n�s ====

int conta_nos (Arvore *a){
    if(!verifica_arv_vazia(a)){
        return (conta_nos(a->esq)+conta_nos(a->dir)+1);
    }
    return 0;
}
//========= Exerc�cio 4 - calcula altura ====

int calcula_altura_arvore (Arvore *a){
    if (verifica_arv_vazia(a))
        return -1;
    else{
        int alt_esq = calcula_altura_arvore(a->esq);
        int alt_dir = calcula_altura_arvore(a->dir);

        if (alt_esq < alt_dir)
            return (alt_dir + 1);
        else
            return (alt_esq + 1);
    }
}
//========= Exerc�cio 5 - conta folhas ====

int conta_nos_folha (Arvore *a){
    if(!verifica_arv_vazia(a)){
        if(a->esq == NULL && a->dir == NULL)
            return 1;
        else
            return (conta_nos_folha(a->esq) + conta_nos_folha(a->dir));
    }
    return 0;
}
