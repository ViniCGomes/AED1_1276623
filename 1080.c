/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1080>>
Data        : 25/08/2026
Objetivo    : Leia T valores inteiros. Apresente então o maior valor lido e a posição entre os T valores lidos.
Dificuldade : <<<Situacao ja trabalhada antes>>>
Uso de IA   : <<<Uso apos para conferencia de logica arrumar erros de sintaxe e formatacao. Sugestao do Gemini para nao usar vetor, mas sim trocar somente a variavel>>>
-----------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

#define T 100

int main(){
    
    int Vet[T];

    for(int i=0; i < T; i++){
        scanf("%d", &Vet[i]);
    }
    
    int m_aux = Vet[0], pos_aux = 0;
    
    //procura pelo maior elemento dentro do vetor 
    for (int i = 1; i < T; i++){
        if(m_aux < Vet[i]){
            m_aux = Vet[i];
            pos_aux = i;
        }
    }

    printf("%d\n", m_aux);

    //correcao indice para usuario
    printf("%d\n", pos_aux + 1);

    return 0;

}