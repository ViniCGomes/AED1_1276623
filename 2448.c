/* ------------------------------------------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<2448>>
Data        : 12/10/2026
Objetivo    : Carteiro
Dificuldade : <<<Implementacao de busca binaria>>>
Uso de IA   : <<<   >>>
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REPETICOES 1 // Para o Beecrowd, 1 repetição lê e processa a entrada real

// Busca binária para obter o índice da casa
int busca_binaria(int casas[], int n, int x) {
    int e = -1;
    int d = n;

    while (e < d - 1) {
        int m = e + (d - e) / 2;

        if (casas[m] < x) {
            e = m;
        } else {
            d = m;
        }
    }

    return d; // Retorna a posição exata da casa
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    scanf("%d", &m);

    int *casas = (int *)malloc(n * sizeof(int));
    int *encomendas = (int *)malloc(m * sizeof(int));

    if (casas == NULL || encomendas == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &encomendas[i]);
    }

    // Variáveis de medição de tempo
    clock_t inicio, fim;
    //tempo_total eh para o carteiro do beecrowd, se n n haveria 
    long long tempo_total = 0;

    // Medição do tempo de processamento
    inicio = clock();

    for (int r = 0; r < REPETICOES; r++) {
        // ex estipula que para mudar de posicao para uma adjacente no vetor, demora 1 unidade de tempo
        tempo_total = 0;
        int pos_atual = 0;

        for (int i = 0; i < m; i++) {
            int prox_pos = busca_binaria(casas, n, encomendas[i]);
            /* 
            funcao modulo `abs(x)`: No caso do carteiro ter que voltar casas, o numero ficaria negativo,
            somando tempo negativo, oq nao queremos, queremos a variacao do tempo
            */
            tempo_total += abs(prox_pos - pos_atual);
            pos_atual = prox_pos;
        }
    }

    fim = clock();

    // Cálculo do tempo em segundos
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Tempo Total percorrido pelo carteiro
    printf("%lld\n", tempo_total);

    //No Beecrowd foi utilizado apenas ateh aqui -------------------------------------------- 
    printf("\n--- Medicao de Desempenho ---\n");
    printf("Repeticoes: %d\n", REPETICOES);
    printf("Tempo total de CPU:\n");
    printf("  %.6f segundos\n", tempo);
    printf("Tempo medio por repeticao:\n");
    printf("  %.6f microssegundos\n", (tempo * 1000000.0) / REPETICOES);
    //----------------------------------------------------------------------------------------
    free(casas);
    free(encomendas);
    
    return 0;
}