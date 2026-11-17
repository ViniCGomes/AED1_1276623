/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1082>>
Data        : 17/11/2026
Objetivo    : Verificar conectividade em grafos
Dificuldade : <<< Implementacao BFS de forma a percorrer todos os elementos,
              mesmo que o grafo seja desconexo e tratamento da output do beecrowd.>>>
Uso de IA   : <<<Sim, implementacao e tratamento de dados do beecrowd>>>
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

void bfs(int **grafo, int fila[], int *inicio, int *fim, int visitado[], int termos);

int main() {
    
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        printf("Case #%d:\n", i + 1);
        int V, E;
        scanf("%d", &V);
        scanf("%d", &E);

        int **A = (int **)malloc(V * sizeof(int *));
        if (A == NULL) {
            return 1;
        }
        for (int j = 0; j < V; j++) {
            A[j] = (int *)malloc(V * sizeof(int));
            if (A[j] == NULL) {
                for (int k = 0; k < j; k++) {
                    free(A[k]);
                }
                free(A);
                return 1;
            }
        }

        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                A[u][v] = 0;
            }
        }

        char u, v;
        for (int j = 0; j < E; j++) {
            scanf(" %c %c", &u, &v);
            A[u - 'a'][v - 'a'] = 1;
            A[v - 'a'][u - 'a'] = 1;
        }

        int *fila = (int *)calloc(V, sizeof(int));
        int inicio = 0, fim = 0;
        int *visitado = (int *)calloc(V, sizeof(int));
        int origem;
        int cont = 0;

        for (int j = 0; j < V; j++) {
            if (visitado[j] == 0) {
                cont++;
                
                int *antes = (int *)malloc(V * sizeof(int));
                for (int k = 0; k < V; k++) {
                    antes[k] = visitado[k];
                }

                origem = j;
                visitado[origem] = 1;
                fila[fim++] = origem;
                
                bfs(A, fila, &inicio, &fim, visitado, V);

                for (int k = 0; k < V; k++) {
                    if (visitado[k] == 1 && antes[k] == 0) {
                        printf("%c,", k + 'a');
                    }
                }
                printf("\n");
                free(antes);
            }
        }

        printf("%d connected components\n\n", cont);

        for (int j = 0; j < V; j++) {
            free(A[j]);
        }
        free(A);
        free(visitado);
        free(fila);
    }
    return 0;
}

void bfs(int **grafo, int fila[], int *inicio, int *fim, int visitado[], int termos) {
    if (*inicio == *fim)
        return;

    int v = fila[(*inicio)++];
    for (int i = 0; i < termos; i++) {
        if (grafo[v][i] == 1 && visitado[i] != 1) {
            visitado[i] = 1;
            fila[(*fim)++] = i;
        }
    }
    bfs(grafo, fila, inicio, fim, visitado, termos);
}