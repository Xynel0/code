// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 10
#define M 5

int L[N] = {2,3,5,8,12,15,19,20,32,35};

int B[M] = {2,8,19,20,32};

// -- escreva seu código abaixo, não altere esta linha



int main() {
    for(int i = 0; i < M; ++i){
        int ij = 0;
        for(int j = ij; j < N; ++j){
            if (L[j] == B[i]){
                for (int k = j; k < N; ++k){
                    if (k == N-1){
                        L[k] = 0;
                    }
                    else{
                        L[k] = L[k+1];
                    }
                }
                ij = j+1;
            }
        }
    }
}
