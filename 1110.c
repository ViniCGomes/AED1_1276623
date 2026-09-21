/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1110>>
Data        : 01/09/2026
Objetivo    : Desempilhar cartas e chegar no ultimo elemento
Dificuldade : <<<Logica de pilhas e filas, sintaxe e afins>>>
Uso de IA   : <<<   >>>
-----------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int number;
    struct cel *prox;
} cel;

cel* criar_base_final_falso();
void inserir(cel **, int);
int retirar(cel *, cel **);
void liberar_lista(cel *);

int main(){
    int n;

    while(scanf("%d", &n) == 1 && n != 0){
        
        int *vet_aux = (int*) malloc(sizeof(int)*n);
        int qtd_descartes = 0;

        cel *topo_cabeca = criar_base_final_falso();
        cel *base_fim = topo_cabeca;

        for(int i = 1; i <= n; i++){
            inserir(&base_fim, i);
        }

        while(topo_cabeca->prox != base_fim){
            vet_aux[qtd_descartes++] = retirar(topo_cabeca, &base_fim);

            int carta_mover = retirar(topo_cabeca, &base_fim);
            inserir(&base_fim, carta_mover);
        }

        printf("Discarded cards:");
        for(int i = 0; i < qtd_descartes; i++){
            if(i == 0){
                printf(" %d", vet_aux[i]);
            } else {
                printf(", %d", vet_aux[i]);
            }
        }
        printf("\n");

        printf("Remaining card: %d\n", topo_cabeca->prox->number);

        free(vet_aux);
        liberar_lista(topo_cabeca);
    }

    return 0;
}

cel* criar_base_final_falso(){

    cel *topo_cabeca = (cel*) malloc(sizeof(cel));
    topo_cabeca->prox = NULL;
    return topo_cabeca;

}

void inserir(cel **base_fim, int valor){
    
    cel *novo = (cel*) malloc(sizeof(cel));
    
    novo->number = valor;
    novo->prox = NULL;
    (*base_fim)->prox = novo;//endereco do final_item(que eh o topo), foi passado como parametro. Acesso ele por (*nome),desreferenciando, e recebe o novo endereco
    *base_fim = novo;//endereco do final_main. Acesso ele por (*nome),desreferenciando, e recebe o novo endereco.
    
    /* Na verdade oque ocorreu, 2 coisas diferentes receberam o mesmo valor no final. 
    Uma foi o novo_item do final(nesse caso o topo) e o outro foi o endereco auxiliar da main.*/
}

int retirar(cel *topo_cabeca, cel **base_fim){

    cel *removido = topo_cabeca->prox;

    if(removido == NULL){
        return -1;
    }

    int valor = removido->number;
    topo_cabeca->prox = removido->prox;

    if(topo_cabeca->prox == NULL){
        *base_fim = topo_cabeca;
    }

    free(removido);
    return valor;

}

void liberar_lista(cel *topo_cabeca){

    cel *atual = topo_cabeca;
    while(atual != NULL){
        cel *temp = atual->prox;
        free(atual);
        atual = temp;
    }

}