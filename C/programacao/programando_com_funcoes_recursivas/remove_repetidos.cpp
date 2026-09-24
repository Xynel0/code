// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 8

int L[N] = {2,3,4,1,2,3,4,6};

void remova_repetidos(int L[], int i, int j);

// -- escreva seu código abaixo, não altere esta linha

void remova_repetidos(int L[], int i, int j){
	for(int k = i + 1; k <= j; ++k){
		if (L[k] == L[i]){
			for(int trocado = k; trocado < j; ++trocado){
				L[trocado] = L[trocado + 1];
			}
			L[j] = 0;
			remova_repetidos(L, i, j-1);
			return;
		}
	}
	if (i+1 < j){
		remova_repetidos(L, i + 1, j);
	}
}


int main() {

	remova_repetidos(L, 0, N-1);

	for (int i = 0; i < N; ++i){
		printf("%d ", L[i]);
	}
	printf("\n");
}
