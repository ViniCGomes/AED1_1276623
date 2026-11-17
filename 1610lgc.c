/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1610>>
Data        : 17/11/2026
Objetivo    : Verificar loops em grafos.
Dificuldade : <<< Implementacao DFS, com 3 indices de resposta. Tratamento do beecrow>>>
Uso de IA   : <<<Sim, implementacao e tratamento de dados do beecrowd>>>
ATENCAO : Esse eh o exercicio realmente feito, o 1610.c esta somente com o tratamento de dados por acabar a memoria,
o que adicionou uma consideravel dificuldade no entendimento e assimilacao, que nao convem para a intencao do exercicio
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int dfs(int **, int, int[], int );

int main() {

    int T;
    scanf ("%d", &T);

    for (int i = 0; i < T;  i++) {
        int N, M;
        scanf("%d", &N);
        scanf("%d", &M);

        int **grafo = (int**) malloc (N * sizeof(int*));
        for (int m = 0; m < N; m++) {
            grafo[m] = (int*) calloc (N, sizeof(int));
        }
        for (int j = 0; j < M; j++) {
            int l,c;
            scanf("%d", &l);
            scanf("%d", &c);
            grafo[l - 1][c - 1] = 1;
        }
        
        int *visitado = (int*) calloc(N, sizeof(int));
        int tem_ciclo = 0;

        for (int j = 0; j < N; j++) {
            if (visitado[j] == 0) {
                if (dfs(grafo, j, visitado, N) == 1) {
                    tem_ciclo = 1;
                    break; 
                }
            }
        }

        if (tem_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        for (int m = 0; m < N; m++) {
            free(grafo[m]);
        }
        free(grafo);
        free(visitado);

    }

    return 0;
}

int dfs(int **grafo, int o, int visitado[], int termos) {
    visitado[o] = 1; 

    for (int i = 0; i < termos; i++) {
        if (grafo[o][i] == 1) {
            if (visitado[i] == 1) {
                return 1; 
            }
            if (visitado[i] == 0) {
                if (dfs(grafo, i, visitado, termos) == 1) {
                    return 1; 
                }
            }
        }
    }

    visitado[o] = 2; 
    return 0;
}