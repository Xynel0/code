// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};
int C = 3;
int resp;

// -- escreva seu código abaixo, não altere esta linha


int dacerto (int D){
    int jafoi = 0, lastcow = 0, dacerto = 0;
    for (int i = 0; i < N; ++i){
        printf("%d | %d | %d\n", dacerto, lastcow, L[i] - lastcow);
        if (i == 0 || L[i] - lastcow >= D){
            ++jafoi;
            lastcow = L[i];
            if (jafoi >= C){
                dacerto = 1;
                break;
            }
        }
    }
    return dacerto;
}
int main() {
    int inicio = 1, fim = L[N-1];
    resp = 0;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (dacerto(meio)){
            resp = meio;
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    printf("%d\n", resp);
}
