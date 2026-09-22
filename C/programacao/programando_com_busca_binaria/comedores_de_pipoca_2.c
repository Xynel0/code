// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 5
int L[5] = {5,8,3,10,7};
int C = 3;
int K; // variavel de saida

// -- escreva seu código abaixo, não altere esta linha



int da_certo(int capacidade){
    int comeu = 0, competidor = 1;
    for(int i = 0; i < N; ++i){
        if (L[i] > capacidade){
            return 0;
        }
        if (comeu + L[i] <= capacidade){
            comeu += L[i];
        }
        else if (competidor + 1 <= C){
            ++competidor;
            comeu = L[i];
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main(){
    int pipocas = 0;
    for(int i = 0; i < N; ++i){
        pipocas += L[i];
    }
    K = pipocas;
    int kmin = pipocas / C, kmax = pipocas;
    while (kmin <= kmax){
        int kmeio = (kmax + kmin) / 2;
        if (da_certo(kmeio)){
            K = kmeio;
            kmax = kmeio -1;
        }
        else{
            kmin = kmeio + 1;
        }
    }
    printf("%d\n", K);
}
