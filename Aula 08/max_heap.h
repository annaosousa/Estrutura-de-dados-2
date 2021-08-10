#ifndef MAX_HEAP_H_INCLUDED
#define MAX_HEAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int pai (int i);

int esquerda (int i);

int direita (int i);

void trocar (int V[], int a, int b);

void imprimir (int V[], int size);

void max_heapify (int V[], int size, int i);

void heap_decrease_key (int v[], int i, int chave, int size);

#endif // MAX_HEAP_H_INCLUDED
