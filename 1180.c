#include <stdio.h>
#include <stdlib.h>
int main(){
    
    int N;
    scanf("%d", &N);
    int *numbers_list = (int*) malloc(sizeof(int)*N);
    for (int i=0;i<N;i++){        // s1d1
        scanf("%d", &numbers_list[i]);
    }
    int menor = numbers_list[0];     // ja declaro como o primeiro elemento do vetor
    int pos_menor = 0 ;
    for(int i=1 ; i<N ; i++){          // comeca a contagem a partir do 2do elemento
        if (menor > numbers_list[i]){
         menor = numbers_list[i];
            pos_menor = i ;       // recebe o indice do programa 
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d ",pos_menor);
    free(numbers_list);
    return 0;
}