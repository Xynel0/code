#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};

// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


void arrasta(int i, int indice){
	for (int j = i; j > indice + 1; --j){
		L[j] = L[j-1];
	}
}

int main() {
	int indice = 1, balde;
	for (int i = N/2; i < N - 1; ++i){
		balde = L[indice];
		L[indice] = L[i];
		arrasta(i, indice);
		L[indice + 1] = balde;
		indice = indice + 2;
	}
}
