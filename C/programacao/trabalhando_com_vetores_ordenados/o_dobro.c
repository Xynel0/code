#include <stdlib.h>
#include <stdio.h>

#define N 12

int U[N] = {1,5,6,9,11,12,17,20,26,28,30,33};
int V[N] = {3,4,6,8,13,16,18,23,27,34,42,51};

int resp;


// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int main() {
    resp = 0;
    int pu = 0, pv = 0;
    while (pu < N && pv < N){
        if (U[pu]*2 < V[pv]){
            ++pu;
        }
        else if(U[pu]*2 > V[pv]){
            ++pv;
        }
        else{
            resp = 1;
            break;
        }
    }
    printf("%d\n", resp);
}
