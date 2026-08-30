#include <stdlib.h>
#include <stdio.h>

#define N 12

int U[N] = {1,3,4,8,11,12,13,18,26,28,30,33};
int V[N] = {3,4,6,8,13,16,18,26,27,30,41,42};

int resp;


// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int main() {
    resp = 0;
    int pu = 0, pv = 0;
    while (pu < N && pv < N){
        if(U[pu] < V[pv]){
            ++resp;
            ++pu;
        }
        if(U[pu] > V[pv]){
            ++resp;
            ++pv;
        }
        if(U[pu] == V[pv]){
            ++pu;
            ++pv;
        }
    }
    resp = resp + N - pu + N - pv;
    printf("%d\n", resp);
}
