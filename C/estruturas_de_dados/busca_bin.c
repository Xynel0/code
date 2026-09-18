#include <stdio.h>
#include <stdlib.h>

#define n 10

int A[n]= {1, 3, 5, 6, 8, 12, 15, 30, 73, 102}; //ordenada de forma crescente(A[n] <= A[n+1])

//--------------------------------------
int busca_bin(int vetor[], int k){
    int inicio = 0, fim = n - 1;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == k){
            return meio;
        }
        if (vetor[meio] < k){
            inicio = meio + 1;
        }
        else if (vetor[meio] > k){
            fim = meio - 1;
        }
    }
    return -1;
}
//--------------------------------------

int main(){
    int elemento;
    printf("insira o elemento a ser buscado na lista:\n");
    scanf("%d", &elemento);
    printf("%d\n", busca_bin(A, elemento));
}
