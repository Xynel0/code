// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};
int C = 3;
int D = 3;
int resp;

// -- escreva seu código abaixo, não altere esta linha




int main() {
    int jafoi = 0, lastcow = 0;
    resp = 0;
    for (int i = 0; i < N; ++i){
        printf("%d | %d | %d\n", resp, lastcow,L[i] - lastcow);
        if (i == 0 || L[i] - lastcow >= D){
            ++jafoi;
            lastcow = L[i];
            if (jafoi >= C){
                resp = 1;
                break;
            }
        }
    }
    printf("%d\n", resp);
}
