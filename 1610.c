/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1610>>
Data        : 17/11/2026
Objetivo    : Verificar loops em grafos.
Dificuldade : <<< Implementacao DFS, com 3 indices de resposta. Tratamento do beecrow>>>
Uso de IA   : <<<Sim, implementacao e tratamento de dados do beecrowd>>>
ATENCAO : O exercicio realmente feito eh o 1610lgc.c , este tem somente com o tratamento de dados por acabar a memoria,
o que adicionou uma consideravel dificuldade no entendimento e assimilacao, que nao convem para a intencao do exercicio
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define MAXN 10005
#define MAXM 30005

int head[MAXN];
int to[MAXM];
int prox[MAXM];
int visitado[MAXN];
int qtd_arestas;

void adiciona_aresta(int u, int v) {
    to[qtd_arestas] = v;
    prox[qtd_arestas] = head[u];
    head[u] = qtd_arestas;
    qtd_arestas++;
}

int dfs(int o) {
    visitado[o] = 1; 

    
    for (int e = head[o]; e != -1; e = prox[e]) {
        int i = to[e];

        if (visitado[i] == 1) {
            return 1; 
        }
        if (visitado[i] == 0) {
            if (dfs(i) == 1) {
                return 1;
            }
        }
    }

    visitado[o] = 2; 
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);

        
        qtd_arestas = 0;
        memset(head, -1, (N + 1) * sizeof(int));
        memset(visitado, 0, (N + 1) * sizeof(int));

        for (int j = 0; j < M; j++) {
            int l, c;
            scanf("%d %d", &l, &c);
            adiciona_aresta(l, c); 
        }

        int tem_ciclo = 0;
        for (int j = 1; j <= N; j++) {
            if (visitado[j] == 0) {
                if (dfs(j) == 1) {
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
    }

    return 0;
}