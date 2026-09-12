// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 8

int L[N] = {2,3,4,1,2,3,4,6};

void transforma(int L[], int i, int j);

// -- escreva seu código abaixo, não altere esta linha

void transforma(int L[], int i, int j){
	if (i != j){
		transforma(L, i+1, j);
		L[i] = L[i+1] + L[i];
	}
}


int main() {

	for(int i = 0; i < N; ++i){
		printf("%d ", L[i]);
	}
	printf("\n");

	transforma(L, 0, N-1);

	for(int i = 0; i < N; ++i){
		printf("%d ", L[i]);
	}
	printf("\n");
}
