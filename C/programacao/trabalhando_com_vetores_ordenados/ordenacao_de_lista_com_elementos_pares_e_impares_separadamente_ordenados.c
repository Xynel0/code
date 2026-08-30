// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 20

int L[N] = {4, 13, 18, 28, 21, 32, 21, 32, 26, 51, 33, 58, 52, 64, 66, 92, 73, 94, 94, 95};


// -- escreva seu código abaixo, não altere esta linha



int main() {
	  int A[N], p = 0, i = 1, ca = 0;
    while(p < N || i < N){
        if (p >= N){
            A[ca] = L[i];
            i += 2;
        }
        else if (i >= N){
            A[ca] = L[p];
            p += 2;
        }
        else{
            if(L[p] < L[i]){
                A[ca] = L[p];
                p += 2;
            }
            else if (L[p] > L[i]){
                A[ca] = L[i];
                i += 2;
            }
            else{
                A[ca] = L[p];
                p += 2;
            }
        }
        ++ca;
    }
    for (int z = 0; z < N; ++z){
	      L[z] = A[z];
    }
}
