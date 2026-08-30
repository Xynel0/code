// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 10
#define M 5

int L[N] = {3,8,12,15,20,0,0,0,0,0};

int B[M] = {2,11,19,26,32};

// -- escreva seu código abaixo, não altere esta linha



int main() {
    int balde1, balde2;
    for(int i = 0; i < M; ++i){
        int passed0 = 0;
        for (int j = 0; j < N; ++j){
            if (L[j] > 0){
                passed0 = 1;
            }
            if (L[j] >= B[i] || (passed0 == 1 && L[j] == 0)){
                balde1 = B[i];
                for(int k = j; k < N; ++k){
                    balde2 = L[k];
                    L[k] = balde1;
                    balde1 = balde2;
                }
                break;
            }
        }
    }
}
