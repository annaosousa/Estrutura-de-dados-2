#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
   int peso;
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

GrafoA* criar_grafo_adj (int tamanho);

void cria_aresta_adj_sem_peso(GrafoA *G, int i, int j);

void aresta_adj_transposta_sem_peso(GrafoA *G, int i, int j);

void cria_aresta_adj(GrafoA *G, int i, int j, int peso);

void aresta_adj_transposta(GrafoA *G, int i, int j, int peso);

void lista_transposta(GrafoA *G,  int i, int j);

void imprime_grafo_lista_sem_peso(GrafoA *G);

void imprime_grafo_lista(GrafoA *G);

void aresta_incidentes_adj(GrafoA *G, int info);

void aresta_saem_adj(GrafoA *G, int info);

void vertices_adj(GrafoA *G, int info);

void liberar_grafo_adj (GrafoA *G);

GrafoM* criar_grafo_mat (int tamanho);

void adiciona_aresta_matriz(GrafoM *G, int i, int j, int peso);

void adiciona_aresta_matriz_sem_peso(GrafoM *G, int i, int j);

void arestas_incidentes_matriz(GrafoM *G, int info);

void vertices_saem_matriz(GrafoM *G , int info);

void vertices_adjacentes_matriz(GrafoM *G, int info);

void imprime_grafo_mat(GrafoM *G);

void matriz_transposta(GrafoM *G, int i, int j);

void liberar_grafo_mat (GrafoM *G);

void preenche_grafo(GrafoM *G);

#endif // GRAFO_H_INCLUDED
