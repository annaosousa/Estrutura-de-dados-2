#ifndef ENDERECAMENTO_ABERTO_H_INCLUDED
#define ENDERECAMENTO_ABERTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -99999

typedef struct _hash {
   int key;
} Hash;

int linear_probing (int chave, int iter, int M);

int quadratic_probing (int chave, int iter, int M);

int double_hash (int chave, int iter, int M);

Hash* create_hash (int M);

void free_hash (Hash *H, int M);

int hash_search (Hash *H, int M, int key);

int hash_insert (Hash *H, int M, int key, int *colisoes);

void hash_print (Hash *H, int M);

#endif // ENDERECAMENTO_ABERTO_H_INCLUDED
