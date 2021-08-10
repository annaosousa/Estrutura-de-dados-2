#ifndef MIN_HEAP_H_INCLUDED
#define MIN_HEAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int pai (int i);

int esquerda (int i);

int direita (int i);

void trocar (int V[], int a, int b);

void imprimir (int V[], int size);

void min_heapify (int V[], int size, int i);

void build_min_heap (int V[], int size);

int heap_extract_min (int V[], int *size);

void heap_decrease_key (int V[], int i, int chave, int size);

void min_heap_insert (int V[], int chave, int *size);

#endif // MIN_HEAP_H_INCLUDED
