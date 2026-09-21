/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1068>>
Data        : 21/09/2026
Objetivo    : Arrumar parenteses
Dificuldade : <<<Logica de pilhas e filas, sintaxe e afins>>>
Uso de IA   : <<<   >>>
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    char caractere;
    struct cel *prox;
} cel;

cel* criar_topo_cabeca_falso();
void empilhar(cel *, char);
int desempilhar(cel *);
void liberar_lista(cel *);

int main(){
    char expressao[1001];

    while(scanf(" %[^\n]", expressao) != EOF){

        cel *topo_cabeca = criar_topo_cabeca_falso();
        int correto = 1;

        for(int i = 0; expressao[i] != '\0'; i++){
            if(expressao[i] == '('){
                empilhar(topo_cabeca, '(');
            } else if(expressao[i] == ')'){
                if(desempilhar(topo_cabeca) == -1){
                    correto = 0;
                    break;
                }
            }
        }

        if(correto && topo_cabeca->prox == NULL){
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        liberar_lista(topo_cabeca);
    }

    return 0;
}

cel* criar_topo_cabeca_falso(){

    cel *topo_cabeca = (cel*) malloc(sizeof(cel));
    topo_cabeca->prox = NULL;
    return topo_cabeca;

}

void empilhar(cel *topo_cabeca, char valor){

    cel *novo = (cel*) malloc(sizeof(cel));

    novo->caractere = valor;
    novo->prox = topo_cabeca->prox;
    topo_cabeca->prox = novo;

}

int desempilhar(cel *topo_cabeca){

    cel *removido = topo_cabeca->prox;

    if(removido == NULL){
        return -1;
    }

    topo_cabeca->prox = removido->prox;

    free(removido);
    return 1;

}

void liberar_lista(cel *topo_cabeca){

    cel *atual = topo_cabeca;
    while(atual != NULL){
        cel *temp = atual->prox;
        free(atual);
        atual = temp;
    }

}