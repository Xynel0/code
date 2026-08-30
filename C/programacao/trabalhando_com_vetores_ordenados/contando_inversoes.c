// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 10
int L[N] = {2,3,5,7,1,3,5,8,10,12};
int meio = 4;
int cont;

// -- escreva seu código abaixo, não altere esta linha



int main() {
    cont = 0;
    int prim = 0, seg = meio;
    while (seg < N && prim < meio){
        if (L[seg] < L[prim]){
            cont = cont + meio -prim;
            ++seg;
        }
        else{
            ++prim;
        }
    }

    printf("%d\n", cont);
}
