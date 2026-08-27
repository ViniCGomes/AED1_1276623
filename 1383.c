/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Vinicius Cesar Gomes>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1383>>
Data        : 25/08/2026
Objetivo    :   A matriz do jogo é uma matriz de inteiros
                9 x 9 . Para ser uma solução do
                problema, cada linha e coluna deve
                conter todos os números de 1 a 9. Além
                disso, se dividirmos a matriz em 9
                regiões 3 x 3, cada uma destas regiões
                também deve conter os números de 1 a
                9. O exemplo mostra uma matriz que é
                uma solução do problema.
Dificuldade : <<< >>>
Uso de IA   :   <<<Uso para entender como a logica do sudoku
                seria valido ou nao. Resposta da IA: "A verificação de validade"
                em um tabuleiro de Sudoku 9x9 baseia-se 
                em garantir uma regra simples: não podem existir números
                repetidos (de 1 a 9) em nenhuma linha, em nenhuma coluna e em 
                nenhum dos 9 subquadrantes 3x3.".Uso para correcao e apontamento dos erros
                de sintaxe e funcionamento do beecrowd, por exemplo estava sendo impressa a msg de erro
                logo apos achar o erro, e o sist. do beecrowd pedia que fosse no final.Erros de indice de vetor
                e de usuario.Sugestoes de otimizacao de codigo e novas funcoes(novas libs) para tal.>>>
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main(){

    int n, mat_sudoku[9][9], vet_cont[9];
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
        /*
        para cada quadrante anexar um indice, assim como em batalha naval
        (0,0)(0,1)(0,2)
        (1,0)(1,1)(1,2)
        (2,0)(2,1)(2,2)
        o for usa verificacao generica, usando indices relativos quadrante
        */
        printf("Instancia %d\n", i + 1);
        if (erro == 0) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
    return 0;
}