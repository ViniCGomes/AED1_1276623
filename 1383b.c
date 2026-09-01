#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, vet_cont[9];
    int **mat_sudoku = (int**) malloc(sizeof(int*)*9);
    if(mat_sudoku == NULL){
        printf("Erro");
        return 1;
    }
    for(int i =  0; i < 9; i++){
        mat_sudoku[i] = (int*) malloc(sizeof(int)*9);
        if (mat_sudoku[i] == NULL){
            printf("Erro");
            return 1;
        }
    }

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        
        int erro = 0;

        //preenchimento da matriz com input (x9 linhas, tam da matriz 9x9): a b c d e f g h i 
        for (int j = 0; j < 9; j++){
            for (int l = 0; l < 9; l++){
                scanf("%d", &mat_sudoku[j][l]);
            }
        }
        //verificacao linha
        for (int j = 0; j < 9; j++){
            
            //inicializador de 0`s do vet de verificacao
            for (int ini = 0; ini < 9; ini++){
                vet_cont[ini] = 0;
            }
            //verificador de 1 a 9 na mat, em um vet aux que recebe cont++ para cada intercorrencia
            for (int l = 0; l < 9; l++){
                //Isso soh pode ser feito porque foi garantido que os n digitados seriam de 1 a 9
                vet_cont[ mat_sudoku[j][l] - 1 ]++;
            }
            for (int l = 0; l < 9; l++){
                if(vet_cont[l] != 1){
                    erro ++;
                    break;
                }
                if(erro !=0){
                    break;
                }
            }
            if(erro !=0){
                break;
            }
        }

        //verificacao coluna
        //quero interromper as verificacoes logo nas linhas, se nao for sudoku
        if(erro == 0){
            for (int j = 0; j < 9; j++){
                
                //inicializador de 0`s do vet de verificacao
                for (int ini = 0; ini < 9; ini++){
                    vet_cont[ini] = 0;
                }
                for (int l = 0; l < 9; l++){
                    vet_cont[ mat_sudoku[l][j] - 1 ]++;
                }
                for (int l = 0; l < 9; l++){
                    if(vet_cont[l] != 1){
                        erro ++;
                        break;
                    }
                    if(erro !=0){
                        break;
                    }
                }
                if(erro !=0){
                    break;
                }
            }
        }
        //verificacao quadrante
        if(erro == 0){
            //indice + quadrante.Poderia ter tratado os quad como uma fileira soh
            for(int qlin = 0; qlin < 3; qlin ++){
                for(int qcol = 0; qcol <3; qcol ++){
                    //inicializador de 0`s do vet de verificacao
                    for (int ini = 0; ini < 9; ini++){
                        vet_cont[ini] = 0;
                    }
                    //multiplicador de quadrante por linhaXcoluna de cada alveolo
                    for (int j = 0 + qlin*3; j < 3 + qlin*3; j++){
                        for (int l = 0 + qcol*3; l < 3 + qcol*3; l++){
                            vet_cont[ mat_sudoku[j][l] - 1 ]++;
                        }
                    }
                    for (int l = 0; l < 9; l++){
                        if(vet_cont[l] != 1){
                            erro ++;
                            break;
                        }
                        if(erro !=0){
                            break;
                        }
                    }
                    if(erro !=0){
                        break;
                    }
                }
                if(erro !=0){
                break;
                }
            }
        }
        
        printf("Instancia %d\n", i + 1);
        if (erro == 0) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
    
    for(int i =  0; i < 9; i++){
        free(mat_sudoku[i]);
    }
    free(mat_sudoku);

    return 0;
}