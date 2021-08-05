#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

int pai (int i);

int esquerda(int i);

int direita(int i);

void trocar (int V[], int a, int b);

void imprimir (int V[], int size);

void max_heapify (int V[], int size, int i);

void build_max_heap (int V[], int size);

void heap_sort (int V[], int size);

#endif // HEAPSORT_H_INCLUDED
