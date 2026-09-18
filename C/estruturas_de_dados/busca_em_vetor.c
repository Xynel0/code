#include <stdio.h>
#include <stdlib.h>

#define n 10

int A[n]= {4,5,1,3,8,9,23,45,50,73};


int busca_vetor(int vetor[], int k){
    for(int i = 0; i < n; ++i){
        if (vetor[i] == k){
            return i;
        }
    }
    return -1;
}


int main(){
    int elemento;
    printf("insira o elemento a ser buscado na lista:\n");
    scanf("%d", &elemento);
    printf("%d\n", busca_vetor(A, elemento));
}
