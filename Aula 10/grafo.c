#include "grafo.h"

/*--------Grafo com lista de adjacência--------*/
/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

/*Cria arestas para um lista de adjacência, sem pesos*/
void cria_aresta_adj_sem_peso(GrafoA *G, int i, int j){
    NoA *ultimo = NULL;

    for(NoA *aux = G->Adj[i]; aux != NULL; aux = aux->next){
        if(aux->id == j)
            printf("Aresta ja existe\n");
        ultimo = aux;
    }

    NoA *lista = (NoA*)malloc(sizeof(NoA));
    lista->id = j;
    lista->next = NULL;
    if(ultimo != NULL)
        ultimo->next = lista;
    else
        G->Adj[i] = lista;
}

/*Arestas não direcionadas, são interligadas por ambas as direções, sem peso*/
void aresta_adj_transposta_sem_peso(GrafoA *G, int i, int j){
    cria_aresta_adj_sem_peso(G, i , j);
    cria_aresta_adj_sem_peso(G, j , i);
    G->E++;
}

/*Cria arestas para um lista de adjacência, para os exercicios 1 e 2 o pesos deve ser desconsiderado*/
void cria_aresta_adj(GrafoA *G, int i, int j, int peso){
    NoA *ultimo = NULL;

    for(NoA *aux = G->Adj[i]; aux != NULL; aux = aux->next){
        if(aux->id == j)
            printf("Aresta ja existe\n");
        ultimo = aux;
    }

    NoA *lista = (NoA*)malloc(sizeof(NoA));
    lista->id = j;
    lista->next = NULL;
    lista->peso = peso;
    if(ultimo != NULL)
        ultimo->next = lista;
    else
        G->Adj[i] = lista;
}

/*Arestas não direcionadas, são interligadas por ambas as direções*/
void aresta_adj_transposta(GrafoA *G, int i, int j, int peso){
    cria_aresta_adj(G, i , j, peso);
    cria_aresta_adj(G, j , i, peso);
    G->E++;
}

/*Grafo direcionado com lista de adjacência transposta, arestas invertidas*/
void lista_transposta(GrafoA *G,  int i, int j){
    NoA *ultimo = NULL;

    for(NoA *aux = G->Adj[j]; aux != NULL; aux = aux->next){
        if(aux->id == i)
            printf("Aresta ja existe\n");
        ultimo = aux;
    }

    NoA *lista = (NoA*)malloc(sizeof(NoA));
    lista->id = i;
    lista->next = NULL;
    if(ultimo != NULL)
        ultimo->next = lista;
    else
        G->Adj[j] = lista;
}

/*Imprime a lista de adjacência sem os pesos nas arestas*/
void imprime_grafo_lista_sem_peso(GrafoA *G){
    for(int i = 0; i < G->V; i++){
        printf("%d -> ", i);
        for(NoA *u = G->Adj[i]; u != NULL; u = u->next){
            printf("%d ", u->id);
        }
        printf("\n");
    }
}

/*Imprime a lista de adjacencia, sendo que para os exercicios 1 e 2 o peso deve ser desconsiderado*/
void imprime_grafo_lista(GrafoA *G){
    for(int i = 0; i < G->V; i++){
        printf("%d -> ", i);
        for(NoA *u = G->Adj[i]; u != NULL; u = u->next){
            printf("%d (w:%d) ", u->id, u->peso); //para o exercicio 3 foi adicionado o peso
        }
        printf("\n");
    }
}

/*Calcula o número de arestas incidentes em uma lista adjacente*/
void aresta_incidentes_adj(GrafoA *G, int info){
    int soma = 0;

    for(int i = 0; i < G->V; i++)
        for(NoA *j = G->Adj[i]; j != NULL; j = j->next)
            if(j->id == info)
                soma++;
    printf("Numero de arestas incidentes ao vertice %d: %d\n", info, soma);
}

/*Calcula o número de aresta que saem do vertice em uma lista adjacente*/
void aresta_saem_adj(GrafoA *G, int info){
    int soma = 0;

    for(NoA *j = G->Adj[info]; j != NULL; j = j->next)
        soma++;
    printf("Numero de arestas que saem do vertice %d: %d\n", info, soma);
}

/*Imprime quais são os vértices adjacentes a um determinado vértice da lista de adjacência*/
void vertices_adj(GrafoA *G, int info){
    printf("Vertices adjacentes ao vertice %d: ", info);
    for(NoA *j = G->Adj[info]; j != NULL; j = j->next)
        printf("%d ", j->id);
    printf("\n");
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*--------Grafo com matriz de adjacência--------*/
/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   return G;
}

/*Matriz adjacente com peso nas arestas*/
void adiciona_aresta_matriz(GrafoM *G, int i, int j, int peso){
    if(G->Mat[i][j])
        printf("Aresta existente\n");
    else{
        G->Mat[i][j] = peso;
        //G->Mat[j][i] = peso;
        G->E++;
    }
}

/*Matriz adjacente sem peso nas arestas*/
void adiciona_aresta_matriz_sem_peso(GrafoM *G, int i, int j){
    if(G->Mat[i][j])
        printf("Aresta existente\n");
    else{
        G->Mat[i][j] = 1;
        G->Mat[j][i] = 1; //Para resolução do exercicio 2, é necessário comentar está parte pois o mesmo é direcionado
        G->E++;
    }
}


/*Calcula o número de arestas incidentes em uma matriz adjacente*/
void arestas_incidentes_matriz(GrafoM *G, int info){
    int soma = 0;

    for(int i = 0; i < G->V; i++)
        if(G->Mat[i][info] != 0)
                soma++;
    printf("Numero de arestas incidentes ao vertice %d: %d\n", info, soma);
}

/*Calcula o número de aresta que saem do vertice em uma matriz adjacente*/
void vertices_saem_matriz(GrafoM *G , int info){
    int soma = 0;

    for(int i = 0; i < G->V; i++)
        if(G->Mat[info][i] != 0)
                soma++;
    printf("Numero de arestas que saem do vertice %d: %d\n", info, soma);
}

/*Imprime quais são os vértices adjacentes a um determinado vértice da matriz de adjacência*/
void vertices_adjacentes_matriz(GrafoM *G, int info){
    printf("Vertices adjacentes ao vertice %d: ", info);
    for(int i = 0; i < G->V; i++)
        if(G->Mat[info][i] != 0)
            printf("%d ", i);
    printf("\n");
}

/*Função para impressão de um grafo construido com matriz de adjacências*/
void imprime_grafo_mat(GrafoM *G){
    for(int i = 0; i < G->V; i++){
        for(int j = 0; j < G->V; j++)
            printf("%d ", G->Mat[i][j]);
        printf("\n");
    }
}

/*Grafo direcionado matriz de adjacência transposta, arestas invertidas*/
void matriz_transposta(GrafoM *G, int i, int j){
    if(G->Mat[j][i])
        printf("Aresta existente\n");
    else{
        G->Mat[j][i] = 1;
        G->E++;
    }
}

/*Função para destruir um grafo construído com matriz de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}

/*Preenche o grafo (matriz de adjacência) inicialmente com zeros*/
void preenche_grafo(GrafoM *G){
    for(int i = 0; i < G->V; i++)
        for(int j = 0; j < G->V; j++)
            G->Mat[i][j] = 0;
}

/* */
int main () {

   //int Va = 10; /*Número de vértices*/

   //GrafoA* Ga = criar_grafo_adj (Va);

   int Vm = 10; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);

   preenche_grafo(Gm);
   //imprime_grafo_mat(Gm);

    /*Exercicio 1 - Matriz de adjacência (grafo não direcionado)*/
   adiciona_aresta_matriz_sem_peso(Gm, 0, 1);
   adiciona_aresta_matriz_sem_peso(Gm, 0, 2);
   adiciona_aresta_matriz_sem_peso(Gm, 0, 5);
   adiciona_aresta_matriz_sem_peso(Gm, 1, 2);
   adiciona_aresta_matriz_sem_peso(Gm, 1, 3);
   adiciona_aresta_matriz_sem_peso(Gm, 2, 3);
   adiciona_aresta_matriz_sem_peso(Gm, 2, 4);
   adiciona_aresta_matriz_sem_peso(Gm, 3, 4);
   adiciona_aresta_matriz_sem_peso(Gm, 4, 5);

   /*Exercicio 1 - Lista de adjacência (grafo não direcionado)*/
   /*aresta_adj_transposta_sem_peso(Ga, 0, 1);
   aresta_adj_transposta_sem_peso(Ga, 0, 2);
   aresta_adj_transposta_sem_peso(Ga, 0, 5);
   aresta_adj_transposta_sem_peso(Ga, 1, 2);
   aresta_adj_transposta_sem_peso(Ga, 1, 3);
   aresta_adj_transposta_sem_peso(Ga, 2, 3);
   aresta_adj_transposta_sem_peso(Ga, 2, 4);
   aresta_adj_transposta_sem_peso(Ga, 3, 4);
   aresta_adj_transposta_sem_peso(Ga, 4, 5);
   imprime_grafo_lista_sem_peso(Ga);*/

   /*Exercicio 2 - Matriz de adjacência (grafo direcionado)*/
   /*adiciona_aresta_matriz_sem_peso(Gm, 0, 1);
   adiciona_aresta_matriz_sem_peso(Gm, 0, 5);
   adiciona_aresta_matriz_sem_peso(Gm, 1, 2);
   adiciona_aresta_matriz_sem_peso(Gm, 1, 3);
   adiciona_aresta_matriz_sem_peso(Gm, 2, 0);
   adiciona_aresta_matriz_sem_peso(Gm, 2, 4);
   adiciona_aresta_matriz_sem_peso(Gm, 3, 2);
   adiciona_aresta_matriz_sem_peso(Gm, 4, 3);
   adiciona_aresta_matriz_sem_peso(Gm, 5, 4);*/

   /*Exercicio 2 - Lista de adjacência (grafo direcionado)*/
   /*cria_aresta_adj_sem_peso(Ga, 0, 1);
   cria_aresta_adj_sem_peso(Ga, 0, 5);
   cria_aresta_adj_sem_peso(Ga, 1, 2);
   cria_aresta_adj_sem_peso(Ga, 1, 3);
   cria_aresta_adj_sem_peso(Ga, 2, 0);
   cria_aresta_adj_sem_peso(Ga, 2, 4);
   cria_aresta_adj_sem_peso(Ga, 3, 2);
   cria_aresta_adj_sem_peso(Ga, 4, 3);
   cria_aresta_adj_sem_peso(Ga, 5, 4);
   imprime_grafo_lista_sem_peso(Ga);*/


   /*Exercicio 3 - Matriz de adjacência (grafo direcionado com pesos)*/
   /*adiciona_aresta_matriz(Gm, 0, 1, 1);
   adiciona_aresta_matriz(Gm, 0, 3, 5);
   adiciona_aresta_matriz(Gm, 1, 3, 8);
   adiciona_aresta_matriz(Gm, 2, 0, 5);
   adiciona_aresta_matriz(Gm, 2, 3, 4);
   adiciona_aresta_matriz(Gm, 3, 3, 6);
   adiciona_aresta_matriz(Gm, 3, 4, 3);
   adiciona_aresta_matriz(Gm, 4, 2, 7);
   adiciona_aresta_matriz(Gm, 4, 5, 9);
   adiciona_aresta_matriz(Gm, 5, 0, 2);

    arestas_incidentes_matriz(Gm, 3);
    vertices_saem_matriz(Gm, 4);
    vertices_adjacentes_matriz(Gm, 2);*/


   /*Exercicio 3 - Lista de adjacência (grafo direcionado com pesos)*/
   /*cria_aresta_adj(Ga, 0, 1, 1);
   cria_aresta_adj(Ga, 0, 3, 5);
   cria_aresta_adj(Ga, 1, 3, 8);
   cria_aresta_adj(Ga, 2, 0, 5);
   cria_aresta_adj(Ga, 2, 3, 4);
   cria_aresta_adj(Ga, 3, 3, 6);
   cria_aresta_adj(Ga, 3, 4, 3);
   cria_aresta_adj(Ga, 4, 2, 7);
   cria_aresta_adj(Ga, 4, 5, 9);
   cria_aresta_adj(Ga, 5, 0, 2);

   imprime_grafo_lista(Ga);
   aresta_incidentes_adj(Ga, 3);
   aresta_saem_adj(Ga, 4);
   vertices_adj(Ga, 2);*/

   /*Exercicio 4 - Matriz de adjacência (grafo transposto)*/
   /*matriz_transposta(Gm, 0, 1);
   matriz_transposta(Gm, 0, 5);
   matriz_transposta(Gm, 1, 2);
   matriz_transposta(Gm, 1, 3);
   matriz_transposta(Gm, 2, 0);
   matriz_transposta(Gm, 2, 4);
   matriz_transposta(Gm, 3, 2);
   matriz_transposta(Gm, 4, 3);
   matriz_transposta(Gm, 5, 4);*/

   /*Exercicio 4 - Lista de adjacência (grafo transposto)*/
   /*lista_transposta(Ga, 0, 1);
   lista_transposta(Ga, 0, 5);
   lista_transposta(Ga, 1, 2);
   lista_transposta(Ga, 1, 3);
   lista_transposta(Ga, 2, 0);
   lista_transposta(Ga, 2, 4);
   lista_transposta(Ga, 3, 2);
   lista_transposta(Ga, 4, 3);
   lista_transposta(Ga, 5, 4);
   imprime_grafo_lista_sem_peso(Ga);*/

   printf("\n");

   imprime_grafo_mat(Gm);

   //liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}
