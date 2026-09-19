// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 5
int L[5] = {5,8,3,10,7};
int C = 3;
int K = 12;
int resp;

// -- escreva seu código abaixo, não altere esta linha



int da_certo(int r){
    int total = 0;
    int comeu = 0;
    int competidor = 1;
    for (int i = 0; i < N; ++i){
        if (L[i] > K){
            return 0;
        }
        if (comeu + L[i] <= K){
            comeu += L[i];
            total += L[i];
            if (total >= r){
                return 1;
            }
        }
        else if (competidor + 1 <= C){
            ++competidor;
            comeu = L[i];
            total += L[i];
            if (total >= r){
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    return 0;
}
int main() {
    int pipocas = 0;
    resp = 0;
    for(int i = 0; i < N; ++i){
        pipocas += L[i];
    }
    int inicio = 0, fim = pipocas;
    while (inicio <= fim){
        int meio = (inicio+fim)/2;
        if (da_certo(meio) == 1){
            resp = meio;
            inicio = meio + 1;
        }
        else{
            fim = meio -1;
        }
    }
    printf("%d\n", resp);
}
