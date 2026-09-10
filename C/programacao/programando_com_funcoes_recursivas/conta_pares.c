// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 8

int L[N] = {2,3,4,1,2,3,4,6};

int resp;

int conta_pares(int L[], int i, int j);


// -- escreva seu código abaixo, não altere esta linha

int conta_pares(int L[], int i, int j){
    if (i == j){
        if(L[i] %2 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        int r = conta_pares(L, i+1, j);
        if (L[i] %2 == 0){
            return r + 1;
        }
        else{
            return conta_pares(L, i+1, j);
        }
    }
}


int main() {
	resp = conta_pares(L, 0, N-1);
    printf("%d\n", resp);
}
