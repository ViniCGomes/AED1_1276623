/* ------------------------------------------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1062>>
Data        : 13/10/2026
Objetivo    : Trilhos e vagões
Dificuldade : <<<Implementacao de busca binaria>>>
Uso de IA   : <<<   >>>
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

// Inicializa a pilha alocando memória dinamicamente
Pilha* criarPilha(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (int*) malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, int valor) {
    if (p->topo < p->capacidade - 1) {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}

void desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
    }
}

int obterTopo(Pilha *p) {
    if (!estaVazia(p)) {
        return p->dados[p->topo];
    }
    return -1;
}

// Libera a memória alocada para a pilha
void destruirPilha(Pilha *p) {
    if (p != NULL) {
        free(p->dados);
        free(p);
    }
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        while (1) {
            // Alocação dinâmica para o vetor da permutação desejada
            int *desejado = (int*) malloc(N * sizeof(int));

            scanf("%d", &desejado[0]);

            // 0 indica o fim do bloco de testes para o N atual
            if (desejado[0] == 0) {
                free(desejado);
                printf("\n");
                break;
            }

            for (int i = 1; i < N; i++) {
                scanf("%d", &desejado[i]);
            }

            // Criando a pilha dinamicamente com o tamanho exato N
            Pilha *estacao = criarPilha(N);

            int vagao_atual = 1;
            int idx_desejado = 0;

            // Simulação do movimento dos vagões
            while (vagao_atual <= N) {
                empilhar(estacao, vagao_atual);
                vagao_atual++;

                while (!estaVazia(estacao) && obterTopo(estacao) == desejado[idx_desejado]) {
                    desempilhar(estacao);
                    idx_desejado++;
                }
            }

            if (idx_desejado == N) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            // Liberação da memória
            destruirPilha(estacao);
            free(desejado);
        }
    }

    return 0;
}