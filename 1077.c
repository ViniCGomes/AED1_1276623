/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1077>>
Data        : 24/09/2026
Objetivo    : Infixa para Posfixa
Dificuldade : <<<Logica de pilhas e filas, sintaxe e afins>>>
Uso de IA   : <<<   >>>
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Estrutura do nó da pilha
typedef struct No {
    char dado;
    struct No *prox;
} No;

// Estrutura da pilha com nó cabeça
typedef struct {
    No *cabeca;
    int tamanho;
} Pilha;

// 1. Função para criar a pilha com nó cabeça
Pilha* criarPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->cabeca = (No*) malloc(sizeof(No));
        if (p->cabeca != NULL) {
            p->cabeca->prox = NULL;
            p->cabeca->dado = '\0'; // Valor sentinela
        }
        p->tamanho = 0;
    }
    return p;
}

// 2. Função para verificar se a pilha está vazia
int estaVazia(Pilha *p) {
    return (p == NULL || p->cabeca->prox == NULL);
}

// 3. Função Push (empilhar)
void push(Pilha *p, char c) {
    if (p == NULL || p->cabeca == NULL) return;

    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;

    novo->dado = c;
    novo->prox = p->cabeca->prox;
    p->cabeca->prox = novo;
    p->tamanho++;
}

// 4. Função Pop (desempilhar)
char pop(Pilha *p) {
    if (estaVazia(p)) return '\0';

    No *remover = p->cabeca->prox;
    char valor = remover->dado;

    p->cabeca->prox = remover->prox;
    free(remover);
    p->tamanho--;

    return valor;
}

// 5. Função para espiar o topo sem remover (peek)
char topo(Pilha *p) {
    if (estaVazia(p)) return '\0';
    return p->cabeca->prox->dado;
}

// 6. Função para destruir e liberar a memória da pilha
void destruirPilha(Pilha *p) {
    if (p == NULL) return;

    while (!estaVazia(p)) {
        pop(p);
    }
    free(p->cabeca);
    free(p);
}

// 7. Avaliação da precedência do operador
int precedencia(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

// 8. Processamento do caractere da expressão
void processarCaractere(char c, Pilha *p) {
    // Operando: imprime diretamente
    if (isalnum(c)) {
        printf("%c", c);
    }
    // Parêntese de abertura
    else if (c == '(') {
        push(p, c);
    }
    // Parêntese de fechamento
    else if (c == ')') {
        while (!estaVazia(p) && topo(p) != '(') {
            printf("%c", pop(p));
        }
        if (!estaVazia(p) && topo(p) == '(') {
            pop(p); // Remove '(' da pilha sem imprimir
        }
    }
    // Operador
    else {
        while (!estaVazia(p) && precedencia(topo(p)) >= precedencia(c)) {
            printf("%c", pop(p));
        }
        push(p, c);
    }
}

// 9. Conversão da expressão
void infixaParaPosfixa(const char *infixa) {
    Pilha *p = criarPilha();

    for (int i = 0; infixa[i] != '\0'; i++) {
        processarCaractere(infixa[i], p);
    }

    // Esvazia os operadores restantes
    while (!estaVazia(p)) {
        printf("%c", pop(p));
    }
    printf("\n");

    destruirPilha(p);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char expressao[500];
    for (int i = 0; i < n; i++) {
        scanf("%s", expressao);
        infixaParaPosfixa(expressao);
    }

    return 0;
}